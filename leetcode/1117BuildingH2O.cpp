#include "stdafx.h"

/**
 * There are two kinds of threas, oxygen and hydrogen. Your goal is to group these threads to form water molecules.
 * There is a barrier where each thread has to wait until a complete molecule can be formed.
 * Hydrogen and oxygen threads will be given releaseHydrogen and releaseOxygen methods respectively, which will allow them to pass the barrier.
 * These threads should pass the barrier in groups of three, and theymust be able to immediately bond with each other to form a water modlecule.
 *
 * In other words:
 * 	- if an oxygen thread arrives at the barrier when no hydrogen threads are present, it has to wait for two hydrogen threads
 *  - if an hydrogen thread arrives at the barrier when no other threads are present, it has to wait for an oxygen thread and another hydrogen thread
 *
 * You must guarantee that all the threads from one molecule bond before any other threads from the next molecule do.
 */

 //sphomore
 /*
 HHHH    OOOO
 ——2——   ——1——
 H,H     O   // two H thread and one O thread at the same time
 So      Sh
		 Sh
 --H--   --O--
		 --O--

 S       S

 */

class H2O {
private:
	mutex m;
	condition_variable  cv_h,
		cv_o,
		cv_h_barrier,
		cv_o_barrier;
	int h = 2, //控制H线程数量 最多为2
		o = 1, //控制O线程数量 最多为1
		h_barrier = 0,  //H屏障
		o_barrier = 0;  //O屏障
public:
	H2O() {}
	void hydrogen(function<void()> releaseHydrogen) {
		wait(cv_h, h);  //控制至多两个H线程同时操作

		signal(cv_o_barrier, o_barrier);    //这里唤醒一个O屏障

		wait(cv_h_barrier, h_barrier);      //这里需要被唤醒一道H屏障

		releaseHydrogen();

		signal(cv_h, h); //可以再唤醒一个H线程
	}

	void oxygen(function<void()> releaseOxygen) {
		wait(cv_o, o);  //控制至多只能有一个O操作

		wait(cv_o_barrier, o_barrier);  //这里需要被唤醒两道O屏障
		wait(cv_o_barrier, o_barrier);

		signal(cv_h_barrier, h_barrier);    //这里唤醒两道H屏障
		signal(cv_h_barrier, h_barrier);

		releaseOxygen();

		signal(cv_o, o);    //再开启另一个O线程
	}
private:

	// key
	void signal(condition_variable& cv, int& s) {
		unique_lock<mutex> lock(m);
		s++;
		cv.notify_one();
	}

	// locker
	void wait(condition_variable& cv, int& s) {
		unique_lock<mutex> lock(m);
		if (!s) cv.wait(lock, [&] {return s > 0; }); //wait if sephomore s is 0
		s--;
	}
};

class H2O_2 {
private:
	mutex m;    //mutex for two sephomores
	//sephomore for hydrogen
	int h;
	condition_variable cvh;
	//sephomore for ogygen
	int o;
	condition_variable cvo;
public:
	H2O_2() :h(2), o(0) {
	}

	void hydrogen(function<void()> releaseHydrogen) {
		unique_lock<mutex> lock(m); //lock the conditional variable below
		cvh.wait(lock, [this] {return h > 0; });  //after two consecutive hydrogen release, current thread needs to wait for an oxygen release
		releaseHydrogen();  // releaseHydrogen() outputs "H"
		h--;
		o++;
		cvo.notify_one();   //notify one oxgen release thread
	}

	void oxygen(function<void()> releaseOxygen) {
		unique_lock<mutex> lock(m);
		cvo.wait(lock, [this] {return o > 1; });   //after one execution of this funciton, current thread needs to wait for at lest one hydrgen
		releaseOxygen();    // releaseOxygen() outputs "O".
		o -= 2;
		h += 2;
		cvh.notify_all();   //notify all the hydrogen release thread
	}
};

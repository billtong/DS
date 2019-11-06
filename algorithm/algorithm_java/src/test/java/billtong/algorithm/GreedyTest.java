package billtong.algorithm;

import billtong.algorithm.greedy.HuffmanCode;
import org.junit.Assert;
import org.junit.Test;

public class GreedyTest {
    @Test
    public void HuffmanCodeTest() throws Exception {
        String testString = "hello this is the test file from huffman test!!";
        HuffmanCode huffmanCode = new HuffmanCode();
        Assert.assertEquals(testString, huffmanCode.decode(huffmanCode.encode(testString)));
    }
}

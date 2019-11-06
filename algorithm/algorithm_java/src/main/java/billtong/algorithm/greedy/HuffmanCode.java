package billtong.algorithm.greedy;

import lombok.*;

import java.io.*;
import java.net.URISyntaxException;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

@Getter
@Setter
public class HuffmanCode {
    private List<Letter> printable;
    private BinaryTreeNode root;

    public HuffmanCode() throws URISyntaxException {
        String rootPath = getClass().getResource("/huffman_code_sample.txt").toURI().getPath();
        loadFrequency(new File(rootPath));
        loadHuffmanCode();
    }

    private void loadFrequency(File file) {
        int[] frequencyArray = new int[127];
        for (int i = 0; i < 10; i++) {
            frequencyArray[i] = -1;
        }
        for (int i = 11; i < 32; i++) {
            frequencyArray[i] = -1;
        }
        try {
            InputStream in = new FileInputStream(file);
            Reader buffer = new BufferedReader(new InputStreamReader(in, Charset.defaultCharset()));
            int temp;
            while ((temp = buffer.read()) != -1) {  // check if meets end of the file
                if (frequencyArray[temp] != -1) frequencyArray[temp]++;
            }
            buffer.close();
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        printable = new ArrayList<>();
        for (int i = 0; i < frequencyArray.length; i++) {
            if (frequencyArray[i] != -1)
                printable.add(new Letter(i, frequencyArray[i]));
        }
        printable.sort(Comparator.comparingInt(Letter::getFrequency));
    }

    private void loadHuffmanCode() {
        PriorityQueue<BinaryTreeNode> queue = new PriorityQueue<>(printable.size(), Comparator.comparingInt(BinaryTreeNode::getValue));
        for (Letter letter : printable)
            queue.add(new BinaryTreeLeafNode(letter));
        for (int i = 1; i < printable.size(); i++) { // move n-1 times
            BinaryTreeNode left = queue.poll();
            BinaryTreeNode right = queue.poll();
            queue.add(new BinaryTreeNode(left.getValue() + right.getValue(), left, right, null));
        }
        BinaryTreeNode root = queue.poll();
        root.setPath("");
        List<Letter> tempPrintable = new ArrayList<>();
        BinaryTreeNode.preOrderTransverse(root, tempPrintable);
        tempPrintable.sort(Comparator.comparingInt(Letter::getAsciiCode));
        printable = tempPrintable;
        this.root = root;
    }

    public String encode(String str) {
        StringBuffer buffer = new StringBuffer();
        for (int charLoc : str.toCharArray()) {
            if (charLoc == 10)
                buffer.append(printable.get(0).getHuffmanCode());
            else
                buffer.append(printable.get(charLoc - 31).getHuffmanCode());
        }
        return String.valueOf(buffer);
    }

    public String decode(String str) {
        StringBuffer buffer = new StringBuffer();
        BinaryTreeNode iterator = root;
        for (char c : str.toCharArray()) {
            if (iterator.getLeft() == null && iterator.getRight() == null) {
                buffer.append((char) ((BinaryTreeLeafNode) iterator).getLeafValue().getAsciiCode());
                iterator = root;
            }
            iterator = Integer.parseInt(String.valueOf(c)) == 1 ? iterator.getLeft() : iterator.getRight();
        }
        buffer.append((char) ((BinaryTreeLeafNode) iterator).getLeafValue().getAsciiCode());
        return String.valueOf(buffer);
    }
}

@Data
@Setter
@RequiredArgsConstructor
class Letter {
    @NonNull
    private int asciiCode;
    @NonNull
    private int frequency;
    private String huffmanCode;
}

@Data
@Setter
@AllArgsConstructor
class BinaryTreeNode {
    @NonNull
    private int value;
    private BinaryTreeNode left;
    private BinaryTreeNode right;
    private String path;

    static void preOrderTransverse(BinaryTreeNode root, List<Letter> printable) {
        if (root != null) {
            if (root.getLeft() == null && root.getRight() == null) {
                Letter l = ((BinaryTreeLeafNode) root).getLeafValue();
                l.setHuffmanCode(root.getPath());
                printable.add(l);
            } else {
                String rootpath = root.getPath();
                if (root.getLeft() != null)
                    root.getLeft().setPath(rootpath + "1");   // left child is 1
                if (root.getRight() != null)
                    root.getRight().setPath(rootpath + "0");  // right child is 0
                preOrderTransverse(root.getLeft(), printable);
                preOrderTransverse(root.getRight(), printable);
            }
        }
    }
}

@Getter
@Setter
@EqualsAndHashCode(callSuper = true)
class BinaryTreeLeafNode extends BinaryTreeNode {
    @NonNull
    private Letter leafValue;

    BinaryTreeLeafNode(Letter letter) {
        super(letter.getFrequency(), null, null, null);
        this.leafValue = letter;
    }
}
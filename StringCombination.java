package offer;

import java.util.ArrayList;

/**
 * Created by gloria_z on 14-5-6.
 */
public class StringCombination {
	private ArrayList<Character> result = new ArrayList<Character>();

	public void combination(String string) {
		if (string == null)
			return;
		for (int i = 1; i <= string.length(); i++)
			combination(string, i);
	}

	private void combination(String string, int len) {
		if (len == 0) {
			System.out.println(result);
			return;
		}

		result.add(string.charAt(0));
		combination(string.substring(1), len - 1);
		result.remove(result.size() - 1);
		if (string.length() - 1 >= len)
			combination(string.substring(1), len);
	}

	public static void main(String[] args) {
		StringCombination combination = new StringCombination();
		combination.combination("abc");
	}
}

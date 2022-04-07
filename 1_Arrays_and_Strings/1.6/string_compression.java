public class Main
{
    public int countCompression(String str) 
    {
        int compressedlength = 0;
        int countConsecutive = 0;
        
        for (int i = 0; i < str.length(); i++)
        {
            countConsecutive++;

            /* If next character is different than current, increase the length.*/
            if (i + 1 >= str.length() || str.charAt(i) != str.charAt(i + 1))
            {
                compressedlength += 1 + String.valueOf(countConsecutive).length();
                countConsecutive = 0;
            }
        }
        return compressedlength;
    }
    
    public String compress(String str)
    {
        /* Check final length and return input string if it would be longer. */
        int finalLength = countCompression(str);
        if (finalLength >= str.length()) return str;

        StringBuilder compressed = new StringBuilder(finalLength); //initial capacity
        int countConsecutive = 0;
        for (int i = 0; i < str.length(); i++)
        {
            countConsecutive++;

            /* If next character is different than current, append this char to result.*/
            if ((i + 1 >= str.length()) || (str.charAt(i) != str.charAt(i + 1))) 
            {
                compressed.append(str.charAt(i));
                compressed.append(countConsecutive);
                countConsecutive = 0;
            }
        }   
        return compressed.toString();
    }
    
	public static void main(String[] args)
	{
	    Main obj = new Main();
	    
	    String s1 = "aabcccccaaa";
	    String s2 = "abcdef";
	    String s3 = "aaabbbcccdddeeefff";
	    
	    String result = obj.compress(s1);
      System.out.println(result);
        
      result = obj.compress(s2);
      System.out.println(result);
        
      result = obj.compress(s3);
      System.out.println(result);
	}
}

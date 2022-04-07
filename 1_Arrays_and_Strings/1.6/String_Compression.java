public class Main
{
    public String compress(String str)
    {
        StringBuilder compressed = new StringBuilder();
        int countConsecutive = 0;
        
        for (int i= 0; i < str.length(); ++i) 
        {
            countConsecutive++;
            
            if (i + 1 >= str.length() || str.charAt(i) != str.charAt(i + 1))
            {
                /* If next character is different than current, append this char to result.*/
                compressed.append(str.charAt(i));
                compressed.append(countConsecutive);
                countConsecutive = 0;
            }
        }
        
        return compressed.length() < str.length() ? compressed.toString() : str;
    }
    
	public static void main(String[] args) {
	    
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

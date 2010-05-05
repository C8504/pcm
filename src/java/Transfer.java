public class Transfer
{
   public static final char[] CHN_DIGITS = {
      '零', '壹', '贰', '叁', '肆', '伍', '陆', '柒', '捌', '玖'
   };

   public static final char[] CHN_UNITS = {
      ' ', '拾', '百', '千', '万', ' ', ' ', ' ', '亿'
   };

   public static String toChineseNumber(double n)
   {
      long integerPart = (long)n;
      StringBuilder result = new StringBuilder();
      trans(integerPart, result);

      // TODO: transfer fraction part
      double fractionPart = n - integerPart;
      return result.toString();
   }

   private static void trans(long n, StringBuilder result)
   {
      boolean appendZero = false;
      if (n >= 100000000)
      {
         trans(n / (int)1E8, result);
         result.append(CHN_UNITS[8]);
         n %= 1E8;
      }
      else if (n != 0 && result.length() > 0)
      {
         appendZero = true;
      }

      if (n >= 10000)
      {
         trans(n / (int)1E4, result);
         result.append(CHN_UNITS[4]);
         n %= 1E4;
      }
      else if (n != 0 && result.length() > 0)
      {
         appendZero = true;
      }

      int[] units = { 1000, 100, 10, 1 };
      for (int i = 0; i < units.length; i++)
      {
         if (n >= units[i])
         {
            if (appendZero)
            {
               result.append(CHN_DIGITS[0]);
               appendZero = false;
            }
            result.append(CHN_DIGITS[(int)n / units[i]]);
            if (i != units.length - 1)
            {
               result.append(CHN_UNITS[units.length - 1 - i]);
            }
            n %= units[i];
         }
         else if (result.length() > 0)
         {
            appendZero = true;
         }
      }
   }


   public static void main(String[] args)
   {
      System.out.println(toChineseNumber(100001023));
   }
}


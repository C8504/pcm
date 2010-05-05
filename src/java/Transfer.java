public class Transfer {
   public static final char[] CHN_DIGITS = {
      '零', '壹', '贰', '叁', '肆', '伍', '陆', '柒', '捌', '玖'
   };

   public static final char[] CHN_UNITS = {
      ' ', '拾', '百', '千', '万', ' ', ' ', ' ', '亿'
   };

   public static final char[] CHN_CURRENCY_UNITS = {
      '元', '角', '分', '毫', '厘'
   };

   public static final char CHN_DOT = '点';

   public static final char CHN_ONLY = '整';

   public static String toChineseCurrency(double m) {
      long integerPart = (long)m;
      StringBuilder result = new StringBuilder();
      trans(integerPart, result);
      result.append(CHN_CURRENCY_UNITS[0]);

      if(m - integerPart <= 0) {
         return result.append(CHN_ONLY).toString();
      }

      char[] fractionPart = String.valueOf(
            m - integerPart).substring(2).toCharArray();

      int len = Math.min(fractionPart.length, CHN_CURRENCY_UNITS.length - 1);
      for(int i = 0; i < len; i++) {
         result.append(CHN_DIGITS[fractionPart[i] - '0']).append(CHN_CURRENCY_UNITS[i + 1]);
      }
      return result.toString();
   }

   public static String toChineseNumber(double n) {
      long integerPart = (long)n;
      StringBuilder result = new StringBuilder();
      trans(integerPart, result);

      if(n - integerPart <= 0) {
         return result.toString();
      }

      result.append(CHN_DOT);

      char[] fractionPart = String.valueOf(
            n - integerPart).substring(2).toCharArray();
      for(int i = 0; i < fractionPart.length; i++) {
         result.append(CHN_DIGITS[fractionPart[i] - '0']);
      }
      return result.toString();
   }

   private static void trans(long n, StringBuilder result) {
      if(n >= 100000000) {
         long d = (n / 100000000);
         trans(d, result);
         result.append(CHN_UNITS[8]);
         n %= 100000000;
         if(n != 0 && d % 10 == 0) {
            result.append(CHN_DIGITS[0]);
         }
      }

      if(n >= 10000) {
         long d = (n / 10000);
         trans(d, result);
         result.append(CHN_UNITS[4]);
         n %= 10000;
         if(n != 0 && d % 10 == 0) {
            result.append(CHN_DIGITS[0]);
         }
      }

      int[] units = { 1000, 100, 10, 1 };
      boolean appendZero = false;
      for(int i = 0; i < units.length; i++) {
         if(n >= units[i]) {
            if(appendZero) {
               result.append(CHN_DIGITS[0]);
               appendZero = false;
            }
            result.append(CHN_DIGITS[(int)n / units[i]]);
            if(i != units.length - 1) {
               result.append(CHN_UNITS[units.length - 1 - i]);
            }
            n %= units[i];
         } else {
            appendZero = (result.length() > 0 && 
                  result.charAt(result.length() - 1) != CHN_DIGITS[0]);
         }
      }
   }

public static void main(String[] args) {
		Timer timer = new Timer().start();
		for(int i = 0; i < 100000000; i++) {
			toChineseCurrency(1018600002);
		}
		timer.stop();
		System.out.println("Time costs: " + timer.timeCosts());
		System.out.println(toChineseCurrency(1018600002));
	}

}


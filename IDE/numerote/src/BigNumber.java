/*
 *
 * Juan Antonio Melendres Villa A0039017
 *
*/

public class BigNumber implements Comparable<BigNumber> {
	private String number;
	private boolean negative = false;

	public BigNumber(String number) {
		StringBuilder num = new StringBuilder(number);
		try {
			while (num.length() >= 1 && num.charAt(0) == '0') {
				num.deleteCharAt(0);
			}

			if (num.length() >= 1 && number.charAt(0) == '-') {
				negative = true;
				this.number = num.substring(1, number.length());

			} else {
				this.number = num.toString();
			}
		}
		catch (Exception e) {
			if(num.length() > 64) {
				return;
			}
		}
	}

	public BigNumber(BigNumber b) {
		this.number = b.number;
	}

	public int getAt(int i) {
		return Integer.parseInt(number.charAt(number.length() - i - 1) + "");
	}

	public BigNumber add(BigNumber num2) {
		StringBuilder num = new StringBuilder();
		int remain = 0;
		boolean subtracted = false;
		int length = number.length();
		try {
			if (length < num2.number.length()) {
				length = num2.number.length();
			}
			for (int i = 0; i < length; i++) {
				int number1 = 0;
				try {
					number1 = this.getAt(i);
				}
				catch (Exception e) {
				}

				if (subtracted) {
					number1--;
				}
				int number2 = 0;

				try {
					number2 = num2.getAt(i);
				}
				catch (Exception e) {
				}

				int temp = number1 + number2 + remain;

				remain = temp / 10;
				temp = temp % 10;
				num.insert(0, temp);
			}
			if (remain > 0) {
				num.insert(0, remain);
			}
		}
		catch (Exception e) {
			throw new ArithmeticException("No se puede realizar la operacion");
		}
		return new BigNumber(num.toString());

	}

	public BigNumber subtract(BigNumber num2) {
		StringBuilder num = new StringBuilder();
		int remain = 0;
		boolean subtracted = false;
		try {
			for (int i = 0; i < number.length(); i++) {
				int number1 = 0;
				try {
					number1 = this.getAt(i);
				}
				catch (Exception e) {
				}
				int number2 = 0;
				try {
					number2 = num2.getAt(i);
				}
				catch (Exception e) {
				}

				if (subtracted) {
					number1--;
					subtracted = false;
				}
				int temp = number1 - number2 + remain;

				if (temp < 0) {
					subtracted = true;
					temp += 10;
				}

				remain = temp / 10;
				temp = temp % 10;

				num.insert(0, temp);
			}
			if (remain > 0) {
				num.append(remain);
			}
		}
		catch (Exception e) {
			throw new ArithmeticException("No se puede realizar la operacion");
		}
		return new BigNumber(num.toString());
	}

	public BigNumber multiply(BigNumber num) {
		BigNumber x, y, w, z, r, p, q;
		int m, n;
		n = num.number.length();

		if (this.number.length() > n) {
			n = this.number.length();
		}
		if (num.isZero() || isZero()) {
			return new BigNumber("0");
		}

		else if (n <= 4) {
			return new BigNumber(String.valueOf(Integer.parseInt(num.number)
					* Integer.parseInt(number)));
		}

		else {
			m = n / 2;
			x = this.divide10(m);
			y = this.remain10(m);
			w = num.divide10(m);
			z = num.remain10(m);
			BigNumber xSumy = x.add(y);
			BigNumber wSumz = w.add(z);
			r = xSumy.multiply(wSumz);
			p = x.multiply(w);
			q = y.multiply(z);
			BigNumber pmultiply = p.multiply10(2 * m);
			BigNumber pSumq = p.add(q);
			BigNumber rMinuspSumq = r.subtract(pSumq);
			return pmultiply.add(rMinuspSumq.multiply10(m)).add(q);
		}
	}

	public BigNumber divide(BigNumber other) {
		BigNumber x = new BigNumber(this);
		BigNumber y = new BigNumber("0");
		BigNumber z = new BigNumber("1");

		try {
			while (x.compareTo(other) == 1){
				x = x.subtract(other);
				y = y.add(z);
			}
		} catch (Exception e) {
			if(y.isZero()) {
				throw new ArithmeticException("No se puede dividir por 0");
			}
		}
		return new BigNumber(y);

	}

	public BigNumber module(BigNumber bigNum){
		BigNumber r = this.divide(bigNum);
		BigNumber p = r.multiply(bigNum);
		BigNumber m = this.subtract(p);
		return m;
	}

	public BigNumber divide10(int m) {
		StringBuilder strbuild = new StringBuilder(number);

		try {
			return new BigNumber(strbuild.substring(0, number.length() - m)
					.toString());
		}
		catch (Exception e) {
			return new BigNumber("0");
		}

	}

	public BigNumber remain10(int m) {
		StringBuilder strbuild = new StringBuilder(number);
		try {
			strbuild = new StringBuilder(strbuild.substring(
					number.length() - m, number.length()));
			return new BigNumber(strbuild.toString());
		}
		catch (Exception e) {
			return new BigNumber(number);
		}
	}

	public void negate() {
		this.negative = !this.negative;
	}

	public BigNumber multiply10(int m) {
		StringBuilder strbuild = new StringBuilder(number);
		for (int i = 0; i < m; i++) {
			strbuild.insert(number.length(), '0');
		}
		return new BigNumber(strbuild.toString());
	}

	public boolean isZero() {
		for (int i = 0; i < number.length(); i++) {
			char c = number.charAt(i);
			if (c != '0') {
				return false;
			}
		}
		if (number == null) {
			return true;
		}
		else {
			return true;
		}

	}

	public int compareMagnitude(BigNumber num) {
		int difference = num.number.compareTo(number);
		if (num.number.length() == number.length()) {
			if (difference > 0) {
				return -1;
			}
			else if (difference < 0) {
				return +1;
			}
			else {
				return 0;
			}
		}
		else if(num.number.length() < number.length()) {
			return 1;
		}
		else{
			return -1;
		}
	}

	@Override
	public String toString() {
		if (isZero()) {
			return "0";
		}
		else {
			if (negative) {
				return "-" + number;
			}
			else {
				return number;
			}
		}
	}

	@Override
	public int compareTo(BigNumber o) {
		if (!(this.negative ^ o.negative)) {
			if (this.negative) {
				return -this.compareMagnitude(o);
			}
			else {
				return this.compareMagnitude(o);
			}
		}
		else {
			if (this.negative) {
				return -1;
			}
			else if (this.isZero() && o.isZero()) {
				return 0;
			}
			else {
				return 1;
			}
		}
	}
}

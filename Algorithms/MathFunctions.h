#pragma once

#include "../Algorithms/Utility.h"

#include <limits>

#define PI 3.1415926535897932384626433832795
#define PRECISION 1E-16

namespace LCU
{
	inline namespace Algorithms
	{
		/**
		 * MathFunctions Class
		 *
		 * @project Algorithms
		 * @author Amine MAYOUF
		 */
		class MathFunctions
		{
		public:
			enum Radix
			{
				Binary,
				Decimal,
				Hexadecimal,
				Octal
			};

			MathFunctions() = delete;
			~MathFunctions() = delete;

			// A
			static double Abs(double);

			static double Arccos(double);
			static double Arccosh(double);

			static double Arcsin(double);
			static double Arcsinh(double);

			static double Arctan(double);
			static double Arctanh(double);

			// C
			static double Ceil(double);

			static double Clamp(double p_value, double p_min, double p_max);

			static double Cos(double);

			static double Cosh(double);

			// E
			static double Exp(double);

			// F
			static double Fact(int);
			static double Fact(double);

			static double FractionalPart(double);

			// G
			static int GCD(int, int);

			// I
			static int IntegerPart(double);

			static bool IsPair(double);

			static bool IsPerfectSquare(long);

			static bool IsPrime(int);

			// L
			static int LCM(int, int);

			static double Log(double);
			static double Log10(double);

			// M
			static double Mod(double, double);
			// P
			static double Pow(double, int);
			static double Pow(double, double);

			// S
			static double Sin(double);
			static double Sinh(double);
			/**
			 * @return The square root of p_x using the the Babylonian Method with precision 100
			 */
			static double Sqrt(double);
			// T
			static double Tan(double);
			static double Tanh(double);
		};

		inline double MathFunctions::Abs(double p_x)
		{
			return (p_x < 0) ? -p_x : p_x;
		}

		inline double MathFunctions::Arccos(double p_x)
		{
			return PI / 2 - Arcsin(p_x);
		}

		inline double MathFunctions::Arccosh(double p_x)
		{
			if (p_x > -1 && p_x < 1)
			{
				return std::numeric_limits<double>::quiet_NaN();
			}
			// |p_x| >= 1
			// On utilise la formule : Arccosh(p_x) = Log(p_x+Sqrt(p_x^2-1))
			return Log(p_x + Sqrt(p_x * p_x - 1));
		}

		inline double MathFunctions::Arcsin(double p_x)
		{
			if (p_x < -1 || p_x > 1)
			{
				return std::numeric_limits<double>::quiet_NaN();
			}
			// On utilise le DSE de asin : p_x + p_x^3/3 * (1/2) + p_x^5/5 * (1*3)/(2*4) + p_x^7/7*(1*3*5)/(2*4*6)...
			double result = 1;
			double coefficient = 1;
			double xSquared = p_x * p_x;
			int i = 1;
			do
			{
				coefficient *= (xSquared * (2 * i - 1)) / (2 * i);
				result += coefficient / (2 * i + 1);
				++i;
			}
			while (Abs(coefficient) > PRECISION);
			return p_x * result;
		}

		inline double MathFunctions::Arcsinh(double p_x)
		{
			if (p_x < -1 || p_x > 1)
			{
				return std::numeric_limits<double>::quiet_NaN();
			}
			// On utilise le DSE de Arcsinh : p_x - p_x^3/3 * (1/2) + p_x^5/5 * (1*3)/(2*4) - p_x^7/7*(1*3*5)/(2*4*6)...
			double result = 1;
			double coefficient = 1;
			double xSquared = p_x * p_x;
			int i = 1;
			do
			{
				coefficient *= -(xSquared * (2 * i - 1)) / (2 * i);
				result += coefficient / (2 * i + 1);
				++i;
			}
			while (Abs(coefficient) > PRECISION);
			return p_x * result;
		}

		inline double MathFunctions::Arctan(double p_x)
		{
			return Arcsin(p_x / Sqrt(1 + p_x * p_x));
		}

		inline double MathFunctions::Arctanh(double p_x)
		{
			if (p_x <= -1 || p_x >= 1)
			{
				return std::numeric_limits<double>::quiet_NaN();
			}
			// On utilise la formule Arctanh(p_x) = Log( (1+p_x)/(1-p_x) ) /2
			return Log((1 + p_x) / (1 - p_x)) / 2;
		}

		inline double MathFunctions::Ceil(double p_x)
		{
			int xIntPart = IntegerPart(p_x);
			if (p_x < 0)
			{
				return xIntPart;
			}
			if (static_cast<double>(xIntPart) == p_x)
			{
				return p_x;
			}
			return xIntPart + 1;
		}

		inline double MathFunctions::Clamp(double p_value, double p_min, double p_max)
		{
			if (p_value < p_min)
			{
				p_value = p_min;
			}
			if (p_value > p_max)
			{
				p_value = p_max;
			}
			return p_value;
		}

		inline double MathFunctions::Cos(double p_x)
		{
			// On travaille modulo 2*pi
			p_x = Mod(p_x, 2 * PI);
			// On utilise le DSE du Cos : 1 - p_x^2/2! + p_x^4/4! - p_x^6/6!...
			double result = 1;
			double xSquared = p_x * p_x;
			double coefficient = 1;
			int i = 1;
			do
			{
				coefficient = (-coefficient * xSquared) / (i * (i + 1));
				result += coefficient;
				i += 2;
			}
			while (Abs(coefficient) > PRECISION);
			return result;
		}

		inline double MathFunctions::Cosh(double p_x)
		{
			double expX = Exp(p_x);
			return (expX + 1 / expX) / 2;
		}

		inline double MathFunctions::Exp(double p_x)
		{
			// si p_x > Log(DBL_MAX)
			if (p_x > 709.782712893384)
			{
				return std::numeric_limits<double>::infinity();
			}
			// On utilise le DSE de Exp : p_x^0/0! + p_x^1/1! + p_x^2/2! + p_x^3/3!
			double result = 1;
			double coefficient = 1;
			int i = 1;
			do
			{
				coefficient *= p_x / i;
				result += coefficient;
				++i;
			}
			while (Abs(coefficient) > PRECISION);
			return result;
		}

		inline double MathFunctions::Fact(int p_x)
		{
			double result = 1;
			for (size_t i = 2; i <= static_cast<size_t>(p_x); ++i)
			{
				result *= i;
			}
			return result;
		}

		inline double MathFunctions::Fact(double p_x)
		{
			int xIntPart = IntegerPart(p_x);
			if (p_x > 0)
			{
				return xIntPart;
			}
			if (static_cast<double>(xIntPart) == p_x)
			{
				return p_x;
			}
			return xIntPart - 1;
		}

		inline double MathFunctions::FractionalPart(double p_x)
		{
			return Mod(p_x, IntegerPart(p_x));
		}

		inline int MathFunctions::GCD(int p_x, int p_y)
		{
			while (p_y != 0)
			{
				p_x %= p_y;
				if (p_x < p_y)
				{
					Utility::Swap(p_x, p_y);
				}
			}
			return p_x;
		}

		inline int MathFunctions::IntegerPart(double p_x)
		{
			return static_cast<int>(p_x);
		}

		inline bool MathFunctions::IsPair(double p_x)
		{
			return ((Mod(p_x, 2)) == 0) ? true : false;
		}

		inline bool MathFunctions::IsPerfectSquare(long p_x)
		{
			long s = static_cast<long>(Sqrt(p_x));
			while (s * s < p_x)
				++s;
			while (s * s > p_x)
				--s;
			return s * s == p_x;
		}

		inline bool MathFunctions::IsPrime(int p_x)
		{
			// On utilise les 100 plus petits nombres premiers connus
#ifndef SMALL_PRIMES
#define SMALL_PRIMES 100
#endif // SMALL_PRIMES
			int hundred_primes[] = {
				2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
				101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
				211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
				307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
				401, 409, 419, 421, 31, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499,
				503, 509, 521, 523, 541
			};

			// Si le nombre étudié est plus petit que 541 on sait si il est premier
			if (p_x <= hundred_primes[SMALL_PRIMES - 1])
			{
				for (size_t i = 0; i < SMALL_PRIMES; ++i)
				{
					if (p_x == hundred_primes[i])
					{
						return true;
					}
				}
				return false;
			}
			// Si le nombre étudié est plus grand que 541 on regarde s'il p_x'est pas divisble par un des cents nombres premiers
			for (size_t i = 0; i < SMALL_PRIMES; ++i)
			{
				if (p_x % hundred_primes[i] == 0)
				{
					return false;
				}
			}
			// Sinon on utilise la manière forte! (qui n'est utilisée qu'au-delà de 541 = 292681) !
			for (size_t j = hundred_primes[SMALL_PRIMES - 1] + 2; j < Sqrt(p_x); j += 2)
			{
				if (p_x % j == 0)
				{
					return false;
				}
			}
			return true;
		}

		inline int MathFunctions::LCM(int p_x, int p_y)
		{
			return (p_x * p_y) / GCD(p_x, p_y);
		}

		inline double MathFunctions::Log(double p_x)
		{
			// Ln n'est pas définie sur ]-inf,0[
			if (p_x < 0)
			{
				return std::numeric_limits<double>::quiet_NaN();
			}
			// Ln tend vers -inf quand p_x tend vers 0
			if (p_x == 0)
			{
				return -std::numeric_limits<double>::infinity();
			}
			// Log(1) = 0
			if (p_x == 1)
			{
				return 0;
			}
			// si p_x>1, on utilise Log(1/p_x) = -Log(p_x)
			if (p_x > 1)
			{
				return -Log(1 / p_x);
			}
			// sinon on a 0<p_x<1
			// on utilise le DSE de Ln : p_x - p_x^2/2 + p_x^3/3 - p_x^4/4...
			double result = 0;
			double coefficient = -1;
			int i = 1;
			do
			{
				coefficient *= 1 - p_x;
				result += coefficient / i;
				++i;
			}
			while (Abs(coefficient) > PRECISION);
			return result;
		}

		inline double MathFunctions::Log10(double p_x)
		{
			// Log(p_x) = Log(p_x) / Log(10)
			return Log(p_x) / 2.3025850929940456840179914546844;
		}

		inline double MathFunctions::Mod(double p_x, double p_y)
		{
			if (p_y == 0)
			{
				return std::numeric_limits<double>::quiet_NaN();
			}
			return p_x - p_y * static_cast<int>(p_x / p_y);
		}

		// Quand l'exposant est entier
		inline double MathFunctions::Pow(double p_x, int p_y)
		{
			// Si l'exposant est negatif, on utilise p_x^(-y) = 1/(p_x^y)
			if (p_y < 0)
			{
				return 1 / (Pow(p_x, -p_y));
			}
			// ici l'exposant est positif
			// On multiplie par p_x, y fois
			double result = 1;
			for (int i = 0; i < p_y; ++i)
			{
				result *= p_x;
			}
			return result;
		}

		// Quand l'exposant p_x'est pas entier
		inline double MathFunctions::Pow(double p_x, double p_y)
		{
			int yIntPart = IntegerPart(p_y);
			// Si p_x<0 et que y p_x'est pas entier
			if (p_x < 0 && static_cast<double>(yIntPart) != p_y)
			{
				return std::numeric_limits<double>::quiet_NaN();
			}
			// Si p_x<0 et que y est entier
			if (p_x < 0)
			{
				return Pow(p_x, yIntPart);
			}
			// sinon p_x>0
			// On décompose l'exposant en partie entiere/partie decimale
			// Par ex : 12.345^67.890123 = (12.345^67) * (12.345^0.890123)
			// Pour la partie enti�re on utilise Pow(double, int) et pour la partie d�cimale : p_x^y = Exp(y*Log(p_x))
			return Pow(p_x, yIntPart) * Exp((p_y - yIntPart) * Log(p_x));
		}

		inline double MathFunctions::Sin(double p_x)
		{
			// On travaille modulo 2*pi
			p_x = Mod(p_x, 2 * PI);
			// On utilise le DSE du Sin : p_x - p_x^3/3! + p_x^5/5! - p_x^7/7!... en le factorisant par p_x
			double result = 1;
			double xSquared = p_x * p_x;
			double coefficient = 1;
			int i = 2;
			do
			{
				coefficient = (-coefficient * xSquared) / (i * (i + 1));
				result += coefficient;
				i += 2;
			}
			while (Abs(coefficient) > PRECISION);
			return p_x * result;
		}

		inline double MathFunctions::Sinh(double p_x)
		{
			double expX = Exp(p_x);
			return (expX - 1 / expX) / 2;
		}

		inline double MathFunctions::Sqrt(double p_x)
		{
			// double a = (eventually the main method will plug values into a)
			double a = static_cast<double>(p_x);
			double x = 1;
			// For loop to get the square root value of the entered number.
			for (size_t i = 0; i < p_x; i++)
			{
				x = 0.5 * (x + a / x);
			}
			return x;
		}

		double MathFunctions::Tan(double p_x)
		{
			// On travaille modulo pi
			p_x = Mod(p_x, PI);
			// On utilise simultan�ment les DSE de Cos et de Sin
			double sin = 1, cos = 1;
			double xSquared = p_x * p_x;
			double coefficient = 1;
			int i = 1;
			do
			{
				coefficient = -coefficient * xSquared / (i * (i + 1));
				sin += coefficient / (i + 2);
				cos += coefficient;
				i += 2;
			}
			while (Abs(coefficient) > PRECISION);
			return p_x * sin / cos;
		}

		inline double MathFunctions::Tanh(double p_x)
		{
			double expX = Exp(p_x);
			return (expX - 1 / expX) / (expX + 1 / expX);
		}
	}
}

#undef PI
#undef PRECISION

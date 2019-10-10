#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "sstack.h"

WORD GetWord(char *str, int *k)
{
	int i = *k, j;
	WORD w;
	char tmpstr[40];
	float f;

	w.type = ERROR;
	if (str[i] == 0) return w;

	else if (str[i] == '.' || (str[i] >= '0' && str[i] <= '9'))
	{
		//get the operand
		j = 0;
		while (str[i] == '.' || (str[i] >= '0' && str[i] <= '9'))
			tmpstr[j++] = str[i++];
		tmpstr[j] = 0;
		*k = i;
		sscanf(tmpstr, "%f", &f);
		w.type = OPERAND;
		w.word.X = f;
	}
	else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == '(' || str[i] == ')' || str[i] == '=' || str[i] == 's' || str[i] == 'c')
	{
		//get the operator
		w.type = OPERATOR;
		w.word.op = str[i];
		*k = i + 1;
	}

	return w;
}

int InPri(char op)
{
	char operators[9] = "(+-*/^cs";
	int pri[8] = { 0, 2, 2, 4, 4, 7, 6, 6 };
	int i = 0;
	while (operators[i] != 0)
		if (operators[i] == op)
			return pri[i];
		else i++;
	return -1;
}

int OutPri(char op)
{
	char operators[9] = "(+-*/^cs";
	int pri[8] = { 9, 1, 1, 3, 3, 8, 5, 5 };
	int i = 0;
	while (operators[i] != 0)
		if (operators[i] == op)
			return pri[i];
		else i++;
	return -1;
}

float comput1(float x, char op, float y)
{
	switch (op)
	{
		case '+':
			return x + y;
		case '-':
			return x - y;
		case '*':
			return x * y;
		case '/':
			return x / y;
		case '^':
			return pow(x, y);
	}
}

float comput2(float x, char op)
{
	if (op == 'c') return cos(x);
	else return sin(x);
}

int Evaluate(char *exp, float *result)
{
	int k = 0;
	WORD w, W1, W2, W3;
	SQSTACK s1, s2;
	*result = 0;
	InitSqstack(&s1, 50);
	InitSqstack(&s2, 50);
	w.word.op = '(';
	Push(&s2, w);
	while (1)
	{
		w = GetWord(exp, &k);
		if (w.type == ERROR) return 0;
		else if (w.type == OPERAND) Push(&s1, w);
		else if (w.type == OPERATOR)
			switch (w.word.op)
			{
				case ')':
					while (s2.elem[s2.top].word.op != '(')
					{
						if (s2.elem[s2.top].word.op == 's' || s2.elem[s2.top].word.op == 'c')
						{
							if (!Pop(&s1, &W2) || !Pop(&s2, &W3))
							{
								DestroySqstack(&s1);
								DestroySqstack(&s2);
								return 0;
							}
							else
							{
								W1.word.X = comput2(W2.word.X, W3.word.op);
								Push(&s1, W1);
							}
						}
						else
						{
							if (!Pop(&s1, &W2) || !Pop(&s1, &W1) || !Pop(&s2, &W3))
							{
								DestroySqstack(&s1);
								DestroySqstack(&s2);
								return 0;
							}

							if (!(W2.word.X == 0 && W3.word.op == '/'))
							{
								W1.word.X = comput1(W1.word.X, W3.word.op, W2.word.X);
								Push(&s1, W1);
							}
							else
							{
								DestroySqstack(&s1);
								DestroySqstack(&s2);
								return 0;
							}
						}
					}

					Pop(&s2, &W3);
					break;
				case '=':
					while (s2.elem[s2.top].word.op != '(')
					{
						if (s2.elem[s2.top].word.op == 's' || s2.elem[s2.top].word.op == 'c')
						{
							if (!Pop(&s1, &W2) || !Pop(&s2, &W3))
							{
								DestroySqstack(&s1);
								DestroySqstack(&s2);
								return 0;
							}
							else
							{
								W1.word.X = comput2(W2.word.X, W3.word.op);
								Push(&s1, W1);
							}
						}
						else
						{
							if (!Pop(&s1, &W2) || !Pop(&s1, &W1) || !Pop(&s2, &W3))
							{
								DestroySqstack(&s1);
								DestroySqstack(&s2);
								return 0;
							}

							if (!(W2.word.X == 0 && W3.word.op == '/'))
							{
								W1.word.X = comput1(W1.word.X, W3.word.op, W2.word.X);
								Push(&s1, W1);
							}
							else
							{
								DestroySqstack(&s1);
								DestroySqstack(&s2);
								return 0;
							}
						}
					}

					*result = s1.elem[s1.top].word.X;
					if (s1.top != 0)
					{
						DestroySqstack(&s1);
						DestroySqstack(&s2);
						return 0;
					}
					else
					{
						DestroySqstack(&s1);
						DestroySqstack(&s2);
						return 1;
					}

				default:
					while (InPri(s2.elem[s2.top].word.op) > OutPri(w.word.op))
					{
						if (s2.elem[s2.top].word.op == 's' || s2.elem[s2.top].word.op == 'c')
						{
							if (!Pop(&s1, &W2) || !Pop(&s2, &W3))
							{
								DestroySqstack(&s1);
								DestroySqstack(&s2);
								return 0;
							}
							else
							{
								W1.word.X = comput2(W2.word.X, W3.word.op);
								Push(&s1, W1);
							}
						}
						else
						{
							if (!Pop(&s1, &W2) || !Pop(&s1, &W1) || !Pop(&s2, &W3))
							{
								DestroySqstack(&s1);
								DestroySqstack(&s2);
								return 0;
							}

							if (!(W2.word.X == 0 && W3.word.op == '/'))
							{
								W1.word.X = comput1(W1.word.X, W3.word.op, W2.word.X);
								Push(&s1, W1);
							}
							else
							{
								DestroySqstack(&s1);
								DestroySqstack(&s2);
								return 0;
							}
						}
					}

					Push(&s2, w);
					break;
			}	//switch
	}	//while(1)
}
std::string infx2pstfx(std::string inf)
{
std::string work;
TStack<char> stack;
for (auto &sim : inf)
{
int prior = un_num(sim);
if (prior == -1)
work += sim;
else
if (stack.get() < prior || prior == 0 || stack.isEmpty())
stack.push(sim);
else if (sim == ')')
{
char sm = stack.get();
while (un_num(sm) >= prior)
{
work += sm;
stack.pop();
sm = stack.get();
}
stack.pop();
}
else
{
char sm = stack.get();
while (un_num(sm) >= prior)
{
work += sm;
stack.pop();
sm = stack.get();
}
stack.push(sim);
}
}
while (!stack.isEmpty())
{
work += stack.get();
stack.pop();
}
return work;
}

int eval(std::string pst)
int counter(const int& a, const int& b , const char& el)
{
switch (el)
{
default:
break;
case '+':return a + b;
case '-':return a - b;
case '*':return a * b;
case '/':return a / b;
}
} 

// вычисление выражения, записанного в постфиксной форме
int eval(std::string pst)
{
int summ{ 0 };
TStack<int> stack;
for (auto& el : pst)
{
if (un_num(el) == -1)
{
char k[2];
k[0] = el;
k[1] = '\0';
int r = atoi(k);
stack.push(r);
}
else
{
int b = stack.get();
stack.pop();
int a = stack.get();
stack.pop();
stack.push(counter(a, b, el));
}
}
return stack.get();
}

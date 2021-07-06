void X(void){}

void func4(void){}
void func3(void){ func4(); }
void func2(void){ X(); func3(); }
void func1(void){ func2(); X(); }

int main(void){ func1(); }

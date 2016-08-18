
//栈Stack构造函数
function Stack()
{
  this.dataStore = [];
  this.top = 0;
  this.push = push;
  this.pop = pop;
  this.peek = peek;
  this.length = length;
  this.clear = clear;
}

//入栈 push
function push(element)
{
  this.dataStore[this.top++] = element;
}


//出栈 pop
function pop()
{
  return this.dataStore[--this.top];
}


//返回栈顶元素 peek
function peek()
{
  return this.dataStore[this.top-1];
}


//返回栈的长度 length
function length()
{
  return this.top;
}

//清空栈 clear
function clear()
{
  this.top = 0;
}



var s = new Stack();
s.push("David");
s.push("Raymond");
s.push("Bryan");
console.log("length: " + s.length());
console.log(s.peek());
var popped = s.pop();
console.log("The popped element is: " + popped);
console.log(s.peek());
s.push("Cynthia");
console.log(s.peek());
s.clear();
console.log("length: " + s.length());
console.log(s.peek());
s.push("Clayton");
console.log(s.peek());






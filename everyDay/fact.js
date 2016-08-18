
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

var fact = function(n)
{
  var result = 1;
  var s = new Stack();
  while( n > 1){
    s.push(n--);
  }
  //console.log(s.dataStore);

  while( s.length() > 0 ){

    result = result * s.pop();
    
  }

  return result;

}
console.log(fact(5));  

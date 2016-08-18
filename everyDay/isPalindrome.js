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


function isPalindrome(word)
{
	var s = new Stack();
	for(var i=0; i<word.length;i++)
	{
		s.push(word[i]);
	}

	var rword = "";

	while(s.length()>0)
	{
		rword+=s.pop();
	}

	if(word == rword)
	{
		return true;
	}
	else
	{
		return false;
	}
}

console.log(isPalindrome("ABCCBA"));
console.log(isPalindrome("abcabc"));



                    











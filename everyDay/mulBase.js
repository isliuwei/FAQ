
/**
 *
 *
 *
 *
 *
 */



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

/**
  (1) 最高位为 n % b,将此位压入栈。
  (2) 使用n/b代替n。
  (3) 重复步骤 1 和 2,直到 n 等于 0,且没有余数。
  (4) 持续将栈内元素弹出,直到栈为空,依次将这些元素排列,就得到转换后数字的字符串形式。
*/

function mulBase(num,base)
{
    var s = new Stack();

    do{
      s.push(num%base);
      num = Math.floor(num/base);
    }while(num>0);

    // while(num>0){
    //   s.push(num%base);
    //   num = Math.floor(num/base);
    // }




    //return s;


    var converted = "";
    while(s.length()>0){
      converted+=s.pop();
    }

    return converted;
}

console.log(mulBase(125,8));

//console.log(Array.from(mulBase(125,8).dataStore).reverse().join(""));

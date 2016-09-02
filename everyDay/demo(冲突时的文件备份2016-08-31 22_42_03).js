// var arr1 = [1,2,3,4];
  // var arr2 = [];
  // arr1.forEach(function(item,index,array){
  //   arr2[index] = item;
  // })
  // console.log(arr2);
  // console.log(arr1 === arr2);


 //  	var updateArr = function(arr,elem)
 //  	{
	// 	if(arr.indexOf(elem) === -1)
	// 	{
	// 		arr.push(elem);
	// 		console.log(arr);
	// 	}
	// 	else if(arr.indexOf(elem) > -1)
	// 	{
	// 		console.log('exist');
	// 	}
	// }

	// var arr = [1,2,3];
	// updateArr(arr,4);
	// updateArr(arr,5);
	// updateArr(arr,4);


	// var indices = [];
	// var array = ['a', 'b', 'a', 'c', 'a', 'd'];
	// var element = 'a';
	// var idx = array.lastIndexOf(element);

	// while (idx != -1) 
	// {
	//   indices.unshift(idx);
	//   idx = (idx > 0 ? array.lastIndexOf(element, idx - 1) : -1);
	// }

	// console.log(indices);

// 	function isPrime(element) {
// 	    var start = 2;
// 	    while (start <= Math.sqrt(element)) {
// 	        if (element % start++ < 1) return false;
// 	    }
// 	    return (element > 1);
// 	}

// console.log(isPrime(4));
// console.log(isPrime(7));

// var a = 3;
// var b = 4;

// tag`var1 ${a} var2$ {b}`;


// var a = 5;
// var b = 10;

// function tag(strings, ...values) {
//   console.log(strings[0]); // "Hello "
//   console.log(strings[1]); // " world "
//   console.log(values[0]);  // 15
//   console.log(values[1]);  // 50

//   return "Bazinga!";
// }

// tag`Hello ${ a + b } world ${ a * b}`;

// var arr = [1,2,2,2,2,1,1,3,3,4,5,5,5];

// function unique(a)
// {
//   //var res = [];
//   var hash = {};
  
//   // for(var i=0; i<a.length; i++)
//   // {
//   //   if(hash.hasOwnProperty(a[i]))
//   //   {
      
//   //     res.push(a[i]);
//   //     hash[a[i]] = 1;
      

//   //   }
//   // }
  
//   // return a;

//   return a.filter(function(item){
//   	return a.hasOwnProperty(item) ? false : (a[item] = true);
//   });

  
// }


// console.log(unique(arr));



// var arr = [1,2,3,4,5,6,7,8,9];

// function shuffle(array)
// {
//   var b = [];
//   while(array.length>0)
//   {
//     var index = ~~(Math.random()*array.length);
//     b.push(array[index]);
//     array.splice(index,1);
//   }
//   return b;
// }

// console.log(shuffle(arr));

// var arr = [0,1,2,3,4,5,6,7,8,9];

// arr.sort(function(a,b){
// 	return Math.random()-0.5;
// });

// console.log(arr);

/*
var arr = [0,1,2,3,4,5,6,7,8,9];
function shuffle(array)
{
	var length = array.length;
	var i,t;
	while(length>0)
	{
		i = ~~(Math.random()*length--);

		// t = array[i];
		// array[i] = array[length];
		// array[length] = t;

		t = array[length];
		array[length] = array[i];
		array[i] = t;
	}
	return array;
}

console.log(shuffle(arr));
*/

/*
var arr = [1,2,2,2,2,1,1,3,3,4,5,5,5];

function unique(array)
{
	var uniqueArr = [];
	for(var i=0; i<array.length; i++)
	{
		for(var j=i; j<array.length; j++)
		{
			if(array[j] === array[i])
			{
				j = ++i;
			}
		}

		uniqueArr.push(arr[i]);
	}
	return uniqueArr;
}

console.log(unique(arr));
*/

/*

var arr = [1,2,2,2,2,1,1,3,3,4,5,5,5];

var uniqueArr = arr.filter(function(item,index,array){
	return array.indexOf(item) === index;
});
console.log(uniqueArr);

*/

/*
var arr = [1,2,2,2,2,1,1,3,3,4,5,5,5];

function unique(array)
{
	var len = array.length;
	var uniqueArr = [];
	var hash = {};
	for(var i=0; i<len; i++)
	{
		if(!hash[array[i]])
		{
			hash[array[i]] = true;
			uniqueArr.push(array[i]);
		}
	}
	return uniqueArr;
}


console.log(unique(arr));
*/

/*
var arr = [1,2,2,2,2,1,1,3,3,4,5,5,5];

function unique(array)
{
	var len = array.length;
	var uniqueArr = [];
	var hash = {};
	
	for(var i=0; i<len; i++)
	{
		if(!hash[array[i]])
		{
			hash[array[i]] = true;
			uniqueArr.push(array[i]);
		}
	}
	return uniqueArr;
	
	// return array.filter(function(item){
 //  		return hash.hasOwnProperty(item) ? false : (hash[item] = true);
 //  	});
}

console.log(unique(arr));

*/

/**该函数的形参只是显示的传入了一个参数，
但是在函数内部可以通过arguments对象获取实参列表，
由于它是类数组对象，我们调用数组的slice方法，将除了分割符以后的参数变成数组，
然后调用数组的join方法，将数组转换成字符串*/
/*
function myConcat(separator)
{
  var args = Array.prototype.slice.call(arguments,1);
  return args.join(separator);
}

myConcat(' ','I','love','you');
*/

/*
function myConcat(separator)
{
  var args = Array.from(arguments);
  //var xx = args.splice(0,1);
  //args.shift();
  args.splice(0,1);
  //console.log(args);
  
  return args.join(separator);
}

myConcat(' ','I','love','you');
*/

/*
function list(type)
{
  var args = Array.prototype.slice.call(arguments,1);
  var html = 
      "<"+type+"l>\n"
      +"\t<li>";
  html+= args.join("</li>\n\t<li>");
  html+= "</li>\n</" + type + "l>";
     
    
  return html;
}

console.log(list("o",1,2,3,4));
*/

/*

function fact(n)
{
  if(n<=1)
  {
    return 1;
  }
  else
  {
    //return n*fact(n-1);
    return n*arguments.callee(n-1);
  }
}

fact(5);
*/
/*
(function(n)
{
  if(n<=1)
  {
    return 1;
  }
  else
  {
    //return n*fact(n-1);
    return n*arguments.callee(n-1);
  }
})(5);
*/

/*
[1,2,3,4,5].map(function(n){
  return n<=1?1:n*arguments.callee(n-1);
});


[1,2,3,4,5].map(function fact(n){
  return n<=1?1:n*fact(n-1);
});
*/

/*
this.x = 9; 
var module = {
  x: 81,
  getX: function() {
    console.log(this);
    return this.x; 
  }
};

module.getX(); // 81

var retrieveX = module.getX;
retrieveX(); 

var retrieveX1 = module.getX.bind(module);

retrieveX1(); 
*/
//console.log(global);

/*
var numbers = [1,200,2,-3,12];
Math.max.apply(null,numbers);
Math.min.apply(null,numbers);
*/

/*
var obj = {
      x: 'objX',
      y: 'objY'
};


  
var foo = {
  	x: 'fooX',
  	y: 'fooY',
    getX: function(a,b) {
        return this.x +"--"+this.y+"-->"+a+","+b;
    }
}

foo.getX(2,3);
foo.getX.call(obj,2,3);
foo.getX.apply(obj,[2,3]);
foo.getX.bind(obj,2,3)();
*/

/*
var Person = function(name,age)
{
  this.name = name;
  this.age = age;
  this.sayInfo = function()
  {
    console.log(this.name+","+this.age);
  }
}

//var p1 = new Person('lisi',23);
//p1.sayInfo();

var Asian = function(n,a,c)
{
  
  this.newMethod = Person;
  this.newMethod(n,a);
  this.newMethod = null;  //delete newMethod;
  this.country = c;
  this.location = function(){
    console.log("from"+this.country);
  }
  
  
}

var a = new Asian('lisi',23,'China');
a.sayInfo();
a.location();

*/


/*
function ClassA(name,age)
{
	this.name = name;
	this.age = age;
	this.sayInfo = function()
	{
		console.log(this.name+","+this.age);
	}

}

function Class0(id)
{
	this.id = id;
	this.printId = function()
	{
		console.log(this.id);
	}

}

//var cla = new ClassA('lisi',23);
//cla.sayInfo();

function ClassB(id,name,age,sex)
{
	ClassA.call(this,name,age);
	//ClassA.bind(this,name,age)();
	//ClassA.apply(this,[name,age]);
	//ClassA.apply(this,arguments);

	
	//对象冒充可以实现多重继承
		
	
	Class0.call(this,id);
	this.sex = sex;
	this.saySex = function()
	{
		console.log(this.sex);
	}


}



var clb = new ClassB(340802199004060218,'wangwu',29,'male');
clb.printId();
clb.sayInfo();
clb.saySex();
*/



/*
function ClassA(name,age)
{
  this.name=name;
  this.age=age;
}

ClassA.prototype.sayInfo = function()
{
  console.log(this.name+","+this.age);
}


var cla = new ClassA('lisi',23);
cla.sayInfo();

function ClassB(name,age,sex)
{
  ClassA.call(this,name,age);
  this.sex = sex;
}

ClassB.prototype = new ClassA();

ClassB.prototype.constructor = ClassB;

ClassB.prototype.saySex = function()
{
  console.log(this.sex);
}

var clb = new ClassB('zhangsan',20,'male');
clb.sayInfo();
clb.saySex();
console.log(cla.constructor);
console.log(clb.constructor);
*/

/*
var obj = new Object();
function cerateObj()
{
	
}*/

/*
Item.prototype = {
    constructor: Item,
    bindEvents: function () {
        var self = this;
        this.relevance = new Relevance(this.$el.find('.J-relevance-app'), {
            complete: function (lemmas, tashuoId) {
                self.saveLemmasToServer(lemmas, tashuoId);
            }
        });
        this.$el.on('click', '.J-reject', function () {
            var dialog = new Dialog(
            {
                classNames: 'dialog-tashuo-common',
                title: '填写拒绝原因',
                content: '<textarea class="dialog-tashuo-reject J-reason"></textarea>',
                btns: [{
                    text: '确定',
                    key: 'sure'
                }],
                onBtnClick: function (btnKey) {
                    if (btnKey === 'sure') {
                        self.notifyServer('/tashuo/api/auditDenyTashuo', {
                            tashuoId: self.data.tashuoId,
                            auditReason: $.trim(dialog.node.find('.J-reason').val())
                        },dialog.callback);
                    }
                },
                onHide: function () {
                    dialog.node.remove();
                },
                callback:function(){
                    alert(11);
                }
            });
            dialog.show();
        });
    },
    notifyServer: function (url, data, callback) {
        $.ajax({
            type: 'POST',
            url: url,
            dataType: 'json',
            data: data,
            success: function (response) {
                if (response.error !== 0) {
                    Dialog.alert({
                        icon: 'ERROR',
                        mainMsg: response.msg || '操作失败'
                    });
                } else {
                    callback && callback();
                }
            }
        });
    }
};
 */

//  'use strict';

// function _possibleConstructorReturn(self, call) { if (!self) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return call && (typeof call === "object" || typeof call === "function") ? call : self; }

// function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function, not " + typeof superClass); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, enumerable: false, writable: true, configurable: true } }); if (superClass) Object.setPrototypeOf ? Object.setPrototypeOf(subClass, superClass) : subClass.__proto__ = superClass; }

// function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

// /*****  定义一个点类 Point  *****/

// var Point = function () {

//   /*构造函数 constructor*/
//   function Point(x, y) {
//     _classCallCheck(this, Point);

//     this.x = x;
//     this.y = y;
//   }

//   /*静态方法*/


//   Point.prop = function prop() {
//     return '[class,Point]';
//   };

//   /*公有方法*/


//   Point.prototype.getX = function getX() {
//     return this.x;
//   };

//   Point.prototype.getY = function getY() {
//     return this.y;
//   };

//   return Point;
// }();

// var Line = function (_Point) {
//   _inherits(Line, _Point);

//   function Line(length) {
//     _classCallCheck(this, Line);

//     var _this = _possibleConstructorReturn(this, _Point.call(this, x, y));

//     _this.length = length;

//     return _this;
//   }

//   Line.prop = function prop() {
//     return '[class,Line]';
//   };

//   Line.prototype.distance = function distance(line) {
//     return Math.sqrt(Math.pow(this.x - line.x) + Math.pow(this.y - line.y));
//   };

//   return Line;
// }(Point);

// var p1 = new Point(3,4);
// console.log(p1.getX());
// console.log(Point.prop());



/*****  定义一个点类 Point  *****/

// class Point{
  
//   /*构造函数 constructor*/
//   constructor(x,y){
//     this.x = x;
//     this.y = y;
//   }
  
//   /*静态方法*/
//   static prop(){
//     return '[class,Point]';
//   }
  
//   /*公有方法*/
//   getX(){
//     return this.x;
//   }
//   getY(){
//     return this.y;
//   }
  
  
// }


// class Line extends Point{
  
//   constructor(length){
//     super(x,y);
//     this.length = length;
    
//   }
  
//   static prop(){
//     return '[class,Line]';
//   }
  
//   distance(line){
//     return Math.sqrt(Math.pow(this.x - line.x) + Math.pow(this.y - line.y));
//   }
  
  
  
// }


/*静态方法 $$ 公有方法 $$ 私有属性和方法 $$ 特权方法*/

function Person(name,age)
{
  /*
    静态方法 --> 类名.方法  
    只能通过类名.方法的形式调用 
    不需要实例化对象 并且它的里面不能出现this 
    一般用来做工具函数方法 例如：Math
  */

  Person.prop = function()
  {
    return '[class,Person]';
  }

  this.name = name;
  this.age = age;


  /*私有方法 私有变量*/
  var birth = function()
  {

  }

  var id = 'x0234653';


  this.getId = function()
  {
    return id;
  }


  /*
    特权方法
  */

  this.getName = function()
  {
    return this.name;
  }

  this.getAge = function()
  {
    return this.age;
  }


}


/*
  公有方法
*/

Person.prototype.showProp = function()
{
  return this.name+","+this.age;
}


var p1 = new Person('lisi',23);
console.log(Person.prop());
console.log(p1.showProp());
console.log(p1.getName());
console.log(p1.getAge());
console.log(p1.getId());



























/*
function log(x,y){
	y = y || 'world';
	console.log(x,y);
}

log('hello');
log('hello','ES6');
log('hello','');
*/


/*
function log(x,y){
	
	if(typeof y === 'undefiend'){
		y = 'wrold';
	}

	if(arguments.length === 1){
		y = 'wrold';
	}
	console.log(x,y);
}


log('hello');
log('hello','ES6');
log('hello','');
*/

/* ES6 允许为函数的参数设置默认值,即直接写在参数定义的后面 */
/*
function log(x, y = 'world'){
	console.log(x,y);
}

log('hello');
log('hello','ES6');
log('hello','');
*/


/*
function Point(x = 0, y = 0){
	this.x = x;
	this.y = y;
}

var p = new Point();
console.log(p);
*/


/*
function f(x, y=2, z){
	return [x,y,z];
}
*/



/*如果传入undefined,将触发该函数等于默认值,null则没有这个结果*/

/*
console.log(f());
console.log(f(1,undefined,3));
console.log(f(1,null,3));
console.log(f(1,2.2,3));
*/
//console.log(f(1,,3));

/*
function foo(x = 5, y = 6){
	console.log(x,y);
}
foo(undefined,null);
*/


/*函数的 length 属性*/
//指定了函数的默认值以后,函数的length属性将返回没有指定默认值的参数个数
//只有指定正确的为尾参数,该属性才有效

/*
console.log((function(a){}).length); 
console.log((function(a = 5){}).length);
console.log((function(a,b,c=5,d=6,e=7){}).length);
*/

/*

function f(w, x, y, z=4){
	return [w,x,y,z];
}

console.log(f());
console.log(f(1));
console.log(f(1,2));
console.log(f(1,2,3));

*/

/*
let x = 1;
function f(y=x){
	let x = 2;
	console.log(y);

}

f();
*/

/*
var x = 1;
function f(x, y=x){
	
	console.log(y);

}

f();
*/

/*
function add(...nums){
	let sum = 0;
	for(var n of nums){
		sum += n;
	}
	return sum;
}


console.log(add(1,3,5,7,9));
*/


/*

function sortNumbers(...nums){
	return nums.sort();
}
console.log(sortNumbers(1,4,3,2,5));


function sortNumbers(){
	return Array.from(arguments).sort();
}
console.log(sortNumbers(1,4,3,2,5));


function sortNumbers(){
	return Array.prototype.slice.call(arguments).sort();
}
console.log(sortNumbers(1,4,3,2,5));
*/

/*
function push(array, ...items){
    items.forEach((item)=>{
        array.push(item);
    });
    return array;
}
var arr = [];
console.log(push(arr,1,2,3,4));
*/

/*
function f(a,...b,c){
    
    return b;
}


console.log(f(1,2,3,4));
*/

/*
console.log((function(a){}).length);
console.log((function(...a){}).length);
console.log((function(a,...b){}).length);
console.log((function(a,b,c=1,...d){}).length);
*/

/*
var arr1 = [1,2,3];
var arr2 = [1,2,3];
var arr3 = [1,2,3];

var a = [4,5,6];
var b = [4,5,6];
var c = [4,5,6];

var concatArr = arr1.concat(a);
console.log(concatArr);

arr2.push(b);
console.log(arr2);








//arr3.push.apply(arr3,c);
//[].push.apply(arr3,c);
//Array.prototype.push.apply(arr3,c);
//Array.prototype.push.call(arr3,4,5,6);
Array.prototype.push.call(arr3,...c);
console.log(arr3);
*/

/*
var f = [1,2,3];

console.log(...f);
console.log(1,2,3);

 */

/*
var numArr = [14,3,77,2];
console.log(Math.max.call(null,14,3,77,2));
console.log(Math.max.call(null,...numArr));
console.log(Math.max.apply(null,numArr));
console.log(Math.max(...numArr));
*/
/*
var a1 = [1,2,3];
var a2 = [4,5,6];
a1.push(4,5,6)
console.log(a1);
*/


/*
var arr1 = [0,1,2];
var arr2 = [0,1,2];
var arr3 = [0,1,2];
var arr4 = [0,1,2];
var arr5 = [0,1,2];
var testArr = [4,5,6];

arr1.push(4,5,6);
console.log(arr1);							//显示 [ 0, 1, 2, 4, 5, 6 ]

arr2.push(...testArr);
console.log(arr2);							//显示 [ 0, 1, 2, 4, 5, 6 ]

var concatArr = arr3.concat(testArr);
console.log(concatArr);						//显示 [ 0, 1, 2, 4, 5, 6 ]


Array.prototype.push.apply(arr4,testArr);	//[].push.apply(arr4,testArr);
console.log(arr4);							//显示 [ 0, 1, 2, 4, 5, 6 ]

Array.prototype.push.call(arr5,...testArr);	//[].push.apply(arr5,testArr);
console.log(arr5);							//显示 [ 0, 1, 2, 4, 5, 6 ]

*/

/*
var arr1 = [0,1,2];
var arr2 = [3,4,5];
//[].push.call(arr1,...arr2);
//[].push.apply(arr1,arr2);
arr1.push(...arr2);
console.log(arr1);
*/

/*

var arr1 = ['a','b'];
var arr2 = ['c'];
var arr3 = ['d','e'];

//ES5
console.log(arr1.concat(arr2,arr3));

//ES6
console.log([...arr1,...arr2,...arr3]);
*/


/*

var fact = function(){
        //...
}
console.log(fact.name);						//显示 fact

var fn = function(){
    //
}
console.log(fn.name);						//显示 fn

var bar = function baz(){
	//...
}
console.log(bar.name);						//显示 baz

console.log((function(){}).name);			//


console.log((new Function).name);			//显示 anonymous

function foo(){
	//...
}

console.log(foo.bind({}).name);				//显示 bound foo

console.log((function(){}).bind({}).name);	//显示 bound 
*/


/*
function LateBloomer() {
  this.petalCount = Math.ceil(Math.random() * 12) + 1;
}

// Declare bloom after a delay of 1 second
LateBloomer.prototype.bloom = function() {
	var self = this;
  global.setTimeout(function(){
  	declare.bind(self)();
  },1000);
};

LateBloomer.prototype.declare = function() {
  console.log('I am a beautiful flower with ' +
    this.petalCount + ' petals!');
};

var flower = new LateBloomer();
flower.bloom();  // 一秒钟后, 调用'declare'方法



function LateBloomer() {
  this.petalCount = Math.ceil(Math.random() * 12) + 1;
}


LateBloomer.prototype.bloom = function() {
  var self = this;
  window.setTimeout(function(){
    //self.declare.bind(self)();
    //self.declare.apply(self);
    self.declare.apply(self);
  }, 1000);
};

LateBloomer.prototype.declare = function() {
  console.log('I am a beautiful flower with ' +
    this.petalCount + ' petals!');
};

var flower = new LateBloomer();
flower.bloom();
*/

/*
function LateBloomer() {
  this.petalCount = Math.ceil(Math.random() * 12) + 1;
}


LateBloomer.prototype.bloom = function() {
  
 


  setTimeout(()=>{
  	this.declare();
  },1000);


};

LateBloomer.prototype.declare = function() {
  console.log('I am a beautiful flower with ' +
    this.petalCount + ' petals!');
};

var flower = new LateBloomer();
flower.bloom();
*/
function Person(){
	this.age = Math.ceil(Math.random() * 100) + 1;
}

/*
Person.prototype.sayAge = function(){
	setTimeout(function(){
		//console.log(this === window);	// true
		this.showAge();	//this.showAge is not a function
	},1000);
}
*/

/*
Person.prototype.sayAge = function(){
	var _self = this;
	setTimeout(function(){
		//_self.showAge.apply(_self);
		_self.showAge.call(_self);
	},1000);
}
*/

/*
Person.prototype.sayAge = function(){
	var _self = this;
	setTimeout(function(){
		_self.showAge.bind(_self)();
	},1000);
}
*/

/*
Person.prototype.sayAge = function(){
	setTimeout(()=>{
		console.log(this);
  		this.showAge();
  	},1000);
}

Person.prototype.showAge = function(){
	console.log('I am ' + this.age + ' years old!');
}

global.showAge = function(){
	console.log('setTimeout inner this is window');
}

var lisi = new Person();
lisi.sayAge();
*/

function foo(){
	setTimeout(function(){
		console.log(arguments);
	},1000);
}

foo(1,2,3,4);



function baz(){
	setTimeout(()=>{
		console.log(arguments);
	},1000);
}

baz('a','b','c','d');










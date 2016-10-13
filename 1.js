function fun(n,o){
	console.log(o);
	return {
		fun: function(m){
			return fun(m,n);
		}
	};
}

/*
var x = fun(0);
x.fun(1);
*/

/*
var y = fun(0).fun(1).fun(2);
*/

var z = fun(0).fun(1);

z.fun(2);
z.fun(3);
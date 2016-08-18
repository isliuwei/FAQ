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

	function isPrime(element) {
	    var start = 2;
	    while (start <= Math.sqrt(element)) {
	        if (element % start++ < 1) return false;
	    }
	    return (element > 1);
	}

console.log(isPrime(4));
console.log(isPrime(7));





/*
var OPT = function(testarr, len) {

	var arr = [];
	var count = 0;
	for (var i = 0; i < testarr.length; i++) {
		flag = 1;
		if (arr.length >= len) {
			if (arr.indexOf(testarr[i]) >= 0) {
				console.log(arr);
			} else {
				var pos = [];
				var temp;
				var tem;
				var j;
				arr.forEach(function(item, index, array) {
					if (testarr.slice(i).indexOf(item) === -1) {
						tem = item;
					} else {
						pos.push(testarr.slice(i).indexOf(item));
					}
				});
				if (tem) {
					temp = tem;
				} else {
					temp = testarr.slice(i)[Math.max.apply(null, pos)];
				}
				j = arr.indexOf(temp);
				if (j >= 0) {

					arr.splice(j, 1, testarr[i]);
					count++;
					console.log(arr);
				} else {
					count++;
					console.log(arr);
				} 
			}

		} else {
			for (var j = 0; j < arr.length; j++) {
				if (arr[j] === testarr[i]) {
					flag = !flag;
					break;
				}

			}
			if (flag) {
				arr.push(testarr[i]);
				console.log(arr);
			}

		}
	}

	console.log("缺页数: " + count);
	console.log("缺页率: " + ((count/testarr.length)*100).toFixed(0)+"%");
}

var testarr = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1];
OPT(testarr,3);

*/

/*
var LRU = function(testarr, len){

	function isLruExist(elem,arr){
		for(var j=0; j<arr.length; j++){
			if(elem == arr[j]){
				arr.splice(j,1);
				arr.push(elem);
				console.log(arr);
				flag = !flag;
				break;
			}
		}
		return flag;
	}

	var arr = [];
	var count = 0;

	for(var i=0; i<testarr.length; i++){
		flag = 1;
		if(arr.length >= len){
			if(isLruExist(testarr[i],arr)){
				arr.shift();
				arr.push(testarr[i]);
				console.log(arr);
				count++;
			}
		}else{
			if(isLruExist(testarr[i],arr)){
				arr.push(testarr[i]);
				console.log(arr);
				count++;
			}
		}

	}

	console.log("缺页数: " + count);
	console.log("缺页率: " + ((count/testarr.length)*100).toFixed(0)+"%");
}

var testarr = [4,7,0,7,1,0,1,2,1,2,6];
var len = 5;
LRU(testarr,len);
*/







// var testarr = [4,7,0,7,1,0,1,2,1,2,6];
// var arr = [];
// var len = 5;
// var count = 0;


//var testarr = [7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1];
//var len = 3;





/*
function isExist(elem,arr){
	for(var j=0; j<arr.length; j++){
		if(elem == arr[j]){
			arr.splice(j,1);
			arr.push(elem);
			console.log(arr);
			flag = !flag;
			break;
		}
	}
	return flag;
}



for(var i=0; i<testarr.length; i++){
	flag = 1;
	if(arr.length >= len){
		if(isExist(testarr[i],arr)){
			arr.shift();
			arr.push(testarr[i]);
			console.log(arr);
			count++;
		}
	}else{
		if(isExist(testarr[i],arr)){
			arr.push(testarr[i]);
			console.log(arr);
			count++;
		}
	}

}


console.log(count);





*/



































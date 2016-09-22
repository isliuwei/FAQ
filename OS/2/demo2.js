

var testarr = [4,7,0,7,1,0,1,2,1,2,6];
var arr = [];
var len = 5;
var count = 0;


//var testarr = [7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1];
//var len = 3;






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






































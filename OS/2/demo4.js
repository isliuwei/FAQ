var testarr = [7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1];
//var testarr = [6,0,1,2,0,3,0,4,2,3];
//var testarr = [1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6];
var arr = [];
var len = 3;
var count = 0 ;





for(var i=0; i<testarr.length; i++){
	flag=1;
	if(arr.length>=len){
		if(arr.indexOf(testarr[i])>=0){
			console.log(arr);
		}else{
			var pos = [];
			var temp;
			var tem;
			var j;
			console.log("$$$$$$$"+testarr.slice(i));
			arr.forEach(function(item,index,array){
				if(testarr.slice(i).indexOf(item) === -1){
					
					tem = item;
				}else{
					pos.push(testarr.slice(i).indexOf(item));
				}

				
				
			});
			
			//console.log("xxxx"+pos);
			if(tem){
				temp = tem;
				
			}else{
				temp = testarr.slice(i)[Math.max.apply(null, pos)];
			}
			
			
			//console.log("yyyy"+temp);
			j = arr.indexOf(temp);
			if(j>=0){
				
				arr.splice(j,1,testarr[i]);
				count++;
				console.log(arr);

			}else{
				count++;
				console.log(arr);
			} 
		}

	}else{
		for(var j=0; j<arr.length;j++){
			if(arr[j] === testarr[i]){
				flag = !flag;
				break;
			}

		}
		if(flag){
			arr.push(testarr[i]);
			console.log(arr);
		}

	}
}


console.log(count);
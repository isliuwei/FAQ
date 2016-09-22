
/*
var testarr = [7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1];

// var arr = [];

// var len = 3;

// for(var i=0; i<testarr.length; i++){
// 	if(arr.indexOf(testarr[i])!=-1){
// 		arr.shift();
// 		arr.push(testarr[i]);
// 	}else{

// 	}
// }


function FIFO()
{
	this.len = 3;
	this.arr = [];
	this.size = 20;


}

FIFO.prototype.isFull = function() 
{
	if()
};



public class FIFO {
	
	public static final int N = 3;
	
	Object[] array = new Object[N];
	private int size;
	
	public boolean isEmpty() {
		if(0 == size)
			return true;
		else
			return false;
	}
	
	public boolean isFulled() {
		if(size >= N) 
			return true;
		else 
			return false;
	}
	
	public int size() {
		return size;
	}
	
	public int indexOfElement(Object o) {
		for(int i=0; i<N; i++) { 
			if(o == array[i]) {
				return i;
			}
		}
		return -1;
	}	

	public Object trans(Object obj){
		Object e = null;
		int t = 0;
		if(indexOfElement(obj) != -1) {
			t = indexOfElement(obj);
			for(int i=t; i<size-1; i++) {
				array[i] = array[i+1];
			}
			array[size-1] = obj;
		} else {
			if(!isFulled()){
				array[size] = obj;
				size ++;
			} else {
				for(int i=0; i<size-1; i++) {
					array[i] = array[i+1];
				}
				array[size-1] = obj;
			}
		}
		if( -1 == t) {
			return null;
		} else {
			return array[t];
		}
	}
	
	public void showMemoryBlock() {
		for(int i=0; i<size; i++) {
			System.out.print(array[i] + "        ");
		}
	}
	
	
	public void clear(){
		
	}
	
	public static void main(String[] args) {
		Integer iter[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
		FIFO fifo = new FIFO();
		for(int i=0; i<iter.length; i++) {
			fifo.trans(iter[i]);
			fifo.showMemoryBlock();
			System.out.println();
		}
	}

}
*/

var testarr = [7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1];
//var testarr = [6,0,1,2,0,3,0,4,2,3];
var arr = [];
var len = 3;
var count = 0;



function isExist(elem,arr){
	for(var j=0; j<arr.length; j++){
		if(elem == arr[j]){
			console.info();
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
			//count++;
		}
	}

}




/*
for(var i=0; i<testarr.length; i++){

	if(arr.length >= len){

		for(var j=0; j<len; j++){
			if(arr[j] !== testarr[i]){
				
				arr.shift();
				arr.push(testarr[i]);
				console.log(arr);

			}else{
				console.log("**********");
				break;
			}
						
		}

		

	}else{

		for(var j=0; j<len; j++){
			if(arr[j] !== testarr[i]){
				
				arr.push(testarr[i]);
				console.log(arr);

			}else{
				console.log("**********");
				break;
			}
						
		}
		
		
		
			
			
		
	}
	
	
	// for(){
		
	// }
	// if(arr.indexOf(testarr[i])!=-1){
	// 	t = arr.indexOf(testarr[i]);
	// 	for(var j=t; j<len-1; j++) {
	// 		arr[j] = arr[j+1];
	// 	}
	// 	arr[len-1] = testarr[i];

	// }else{
	// 	if(arr.length<len){
	// 		for(var i=0; i<len; i++){
	// 			arr.push(testarr[i]);
	// 		}
	// 		// arr[len] = testarr[i];
	// 		// len++;
			
	// 	}else{
	// 		arr.shift();
	// 		arr.push(testarr[i]);
	// 	}
	// }


	
}

 
*/

/*
function isExist(elem,arr){
	for(var j=0; j<arr.length; j++){
		if(elem == arr[j]){
			console.log("\n");
			break;
		}
	}
	return 1;

}


*/


console.log(count);



















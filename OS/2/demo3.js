
var testarr = [7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1];

var arr = [];
var len = 3;
var count = 0;





function isExist(elem,arr){
	for(var j=0; j<arr.length; j++){
		if(elem == arr[j]){
			// console.info();
			flag = !flag;
			break;
		}
	}
	
	return flag;

}





for(var i=0; i<testarr.length; i++){
	flag = 1;
	if(arr.length>=len){
		if(isExist(testarr[i],arr)){
			var pos = [];
			var temp;
			var j;
			//console.log("$$$$$$$"+testarr.slice(i));
			arr.forEach(function(item,index,array){
				pos.push(testarr.slice(i).indexOf(item));
			});
			//console.log("xxxx"+pos);
			temp = testarr.slice(i)[Math.max.apply(null, pos)];
			//console.log("yyyy"+temp);
			j = arr.indexOf(temp);
			if(j>=0){
				
				arr.splice(j,1,testarr[i]);
				console.log(arr);

			}else{
				console.log(arr);
			}
			
			count++;
			
		}
	}else{
		if(isExist(testarr[i],arr)){
			arr.push(testarr[i]);
			console.log(arr);
			
		}
	}
}

console.log(count);


/*

var getMax = function(element,i,testarr){
	var count = 0;
	for(var j=i;j<testarr.length;j++){
		if(testarr[j] == element){
			break;
		}
		else{
			count++;
		}
	}

	return count;
}


var isExist = function(testarr,element){
	return testarr.indexOf(element);
}
*/

// while(i<m)
//    {
//     if(Search(p[i].num,page,N)>=0)
//      i++;//如果找到了，就不做处理。
//     else//如果找不到
//     {
//      int temp=0,cn;//cn用来保存离后面最远的数
//      for(t=0;t<N;t++)//对物理块里面的每个数进行遍历
//      {
//       if(temp<Compfu(page,i,t,p,m))//temp用来保存
//       {//page[t]= p[i]~p[m]这个区间内，走的次数，最大的数
//        temp=Compfu(page,i,t,p,m);
//        cn=t;
//       }
//      }
//      page[cn]=p[i];//把当前的值放要发生要走最远的数，也就最不可能最近出现的数
//      n=n+1;//缺页数加1
//      i++;//跳到下一次循环
//     }
//    }
/*
var OPT = function(testarr)
{
	var i = 0;
	var m = testarr.length;
	var arr = [];
	var len = 3;
	while(i<m)
	{
		for(var j=0; j<arr.length; j++){
			if(isExist(testarr,arr[j]) >=0){
				i++;
			}else{
				var temp = 0;
				var num;
				for(var k=0; k<m; k++){
					for(var l=0; l<arr.length; l++){
						if(temp<getMax(arr[l],k,testarr)){
							temp = getMax(arr[l],k,testarr);
							num = temp;
						}
					}
				}
				arr.push(testarr[i]);
				console.log(arr);
			    i++;
			}
		}
		
	}


}

OPT(testarr);
*/

/*
var  Search(int e,Pro *page,int N)//算法里面都要用到它。
{//它是找e页是否在page物理块中，N是物理块的大小

 for(int i=0;i<N;i++)
  if(e==page[i].num)
   return i;//如果找到，就返回在物理块中的位置给Search
 return -1;//找不到，就返回-1
}





// int Compfu(Pro *page,int i,int t,Pro p[],int m)//OPT算法用到的
// {
// //找出如果page[t]要等于p，并且zai p[i]~p[m]这个区间内，走的次数，最大的数
//  int count=0;//count是保存走的步数
//  for(int j=i;j<m;j++)
//  {
//   if(page[t].num==p[j].num )break;//如果相等，跳出循环
//   else count++;//不等就步数加1
//  }
//  return count;
 
// }








// for(var i=0; i<testarr.length; i++){
	
// 	if(arr.length >= len){
// 		for()
		


	
// 	}else{
		
// 		arr.push(testarr[i]);
// 		console.log(arr);
// 		count++;
		
// 	}

// }


// console.log(count);



// int Compfu(Pro *page,int i,int t,Pro p[],int m)//OPT算法用到的
// {
// //找出如果page[t]要等于p，并且zai p[i]~p[m]这个区间内，走的次数，最大的数
//  int count=0;//count是保存走的步数
//  for(int j=i;j<m;j++)
//  {
//   if(page[t].num==p[j].num )break;//如果相等，跳出循环
//   else count++;//不等就步数加1
//  }
//  return count;
 
// }



// void OPT(Pro p[],Pro page[],int m,int N)//p[]数组是存放页面的空间，m是页面的长度
// {    //page[]是可以使用的物理块，N是物理块的大小

//      float n=0;//n用来保存缺页的次数
//         int i=0;//i是循环变量，它是表示走到页面的位置。
//          int t=0; //t是用来表示物理块走到的位置
//    while(i<m)
//    {
//     if(Search(p[i].num,page,N)>=0)
//      i++;//如果找到了，就不做处理。
//     else//如果找不到
//     {
//      int temp=0,cn;//cn用来保存离后面最远的数
//      for(t=0;t<N;t++)//对物理块里面的每个数进行遍历
//      {
//       if(temp<Compfu(page,i,t,p,m))//temp用来保存
//       {//page[t]= p[i]~p[m]这个区间内，走的次数，最大的数
//        temp=Compfu(page,i,t,p,m);
//        cn=t;
//       }
//      }
//      page[cn]=p[i];//把当前的值放要发生要走最远的数，也就最不可能最近出现的数
//      n=n+1;//缺页数加1
//      i++;//跳到下一次循环
//     }
//    }
//    cout<<"缺页次数："<<n<<"    缺页率："<<n/m<<"    命中率："<<1-n/m<<endl;  

// }



*/



































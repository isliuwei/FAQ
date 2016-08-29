var arr = [];
for(var i=0; i<100; i++)
{
	arr.push(i);
}




/**
	方式一: splice

	原理: 每次 random 一个下标，看看这个元素有没有被选过，
	如果被选过了，继续 random，
	如果没有，将其标记，然后存入返回数组，直到所有元素都被标记了。
	每次选中后，可以直接从数组中删除，无需标记了。

	时间复杂度: O(n^2)
*/
/*
	function shuffle(array)
	{
		var shuffledArr = [];
		while(array.length>0)
		{
			var index = ~~(Math.random()*array.length);
			shuffledArr.push(array[index]);
			array.splice(index,1);

		}
		return shuffledArr;
	}
*/

/**
	方式二: Math.random()

	原理: "巧妙应用" JavaScript 中的 Math.random() 函数。

	时间复杂度: O(nlogn)
*/

/*
	function shuffle(array)
	{
		return array.concat().sort(function(a,b){
			return Math.random()-0.5;
		})
	}
*/

/**
	方式三: Fisher–Yates Shuffle
	时间复杂度: O(n)
	遍历数组元素，将其与之前的任意元素交换。
*/


/*
	function shuffle(array)
	{
		
		var m = array.length;
		var i,t;
		while(m>0)
		{
			var i = ~~(Math.random()*m--);
			t = array[m];
			array[m] = array[i];
			array[i] = t;
		}
		return array;

	}
*/

console.log(shuffle(arr));




function shuffle(array) {
  var copy = [], n = array.length, i;

  // While there remain elements to shuffle…
  while (n) {

    // Pick a remaining element…
    i = Math.floor(Math.random() * array.length);

    // If not already shuffled, move it to the new array.
    if (i in array) {
      copy.push(array[i]);
      delete array[i];
      n--;
    }
  }

  return copy;
}


function shuffle(array) {
  var copy = [], n = array.length, i;

  // While there remain elements to shuffle…
  while (n) {

    // Pick a remaining element…
    i = Math.floor(Math.random() * n--);

    // And move it to the new array.
    copy.push(array.splice(i, 1)[0]);
  }

  return copy;
}


function shuffle(array) {
  var m = array.length, t, i;

  // While there remain elements to shuffle…
  while (m) {

    // Pick a remaining element…
    i = Math.floor(Math.random() * m--);

    // And swap it with the current element.
    t = array[m];
    array[m] = array[i];
    array[i] = t;
  }

  return array;
}
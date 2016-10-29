/**
 *
 *  最大子段和问题
 *
 */


/*
var maxSum = function(num)
{

    var start = 0;
    var end = 0;
    var max = 0;
   
    console.time('解法一');
    for(var i=0; i<num.length; i++) //控制求和起始项
    {
        for(var j=i; j<num.length; j++) //控制求和结束项
        {
            var sum = 0;
            for(var k=i; k<=j; k++)
            {
                sum+=num[k];
            }

            if(sum>max)
            {
                start = i;
                end = j;
                max = sum;
            }

        }
    }
    console.log("最大子段和:" + max +","+" 区间为:"+"["+start+","+end+"]");
    console.timeEnd('解法一');

};


var num = [-2,11,-4,13,-5,2];

maxSum(num);




var maxSum = function(num)
{

    var start = 0;
    var end = 0;
    var max = 0;
   
    console.time('解法二');
    for(var i=0; i<num.length; i++) //控制求和起始项
    {
        var sum = 0;
        for(var j=i; j<num.length; j++) //控制求和结束项
        {
            sum+=num[j];
            if(sum>max)
            {
                start = i;
                end = j;
                max = sum;
            }
        }
    }
    console.log("最大子段和:" + max +","+" 区间为:"+"["+start+","+end+"]");
    console.timeEnd('解法二');
};


var num = [-2,11,-4,13,-5,2];

maxSum(num);

*/
console.info();
console.log("最大子段和动态规划法:\n当b[j-1]>0时,b[j] = b[j-1] + num[j],否则b[j] = num[j] \nb[j]的动态递推公式: b[j] = max{b[j-1]+a[j],a[j]}, (1≤j≤n)");
console.info();

var maxSum = function(num)
{
    var sum = 0;
    var b = 0;
    for(var i=0; i<num.length; i++)
    {
        if(b>0)
        {
            b+=num[i];
        }
        else
        {
            b = num[i];
        }

        if(b>sum)
        {
            sum = b;
        }

    }

    return sum;

}



var num = [-2,11,-4,13,-5,2];

console.log(maxSum(num));


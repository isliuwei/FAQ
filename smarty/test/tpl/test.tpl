<div style="background: #aaa; width: 500px; height: 200px;line-height: 200px;text-align: center;">
	{include file="header.tpl" sitename="isliuwei.com"}
</div>

<br>
{$title|default: "这里是标题"}
<br />	
{$articletitle|capitalize}
<br />
{$articletitle|capitalize|cat: " Smarty.":"nihao"}
<br />
{$time|date_format:"%H:%M:%S"|cat:" 格林威治时间 "}
<br />
{$time|date_format:"%B %e, %Y"}
<br />
{$time|date_format:"%B %e, %Y %H:%M:%S"}
<br />
{$url|escape:"url"}
<br />
{$html|escape:"html"}
<br />
{$javascript1}
<br />
{$javascript2|escape:"javascript"}
<br />
{$content|nl2br}
<br />
{if $name1 eq 'admin'}
welcome {$name1};
{/if}
<br />
{if $name2 eq 'admin'}
welcome {$name2};
{else}
welcome {$name2};
{/if}
<br />
{if $name3 eq 'admin'}
welcome {$name3};
{elseif $name3 eq 'guest'}
welcome {$name3};
{else}
welcome {$name3};
{/if}
<br />
<table border='1'>
	{foreach item=book from=$bookList}
		<tr>
			<td>{$book['name']}</td>
			<td>{$book.price|cat:"￥"}</td>
		</tr>
	{/foreach}
</table>

<table border='1'>
	{foreach item=person from=$personList}
		<tr>
			<td>{$person['name']}</td>
			<td>{$person['age']}</td>
		</tr>
	{foreachelse}
		无数据
	{/foreach}
</table>

<table border='1'>
	{foreach $bookList as $book}
		<tr>
			<td>{$book['name']}</td>
			<td>{$book.price|cat:"￥"}</td>
		</tr>
	{/foreach}
</table>
<br />
{$obj->fn(array('苹果','熟了'))}
<br />
{"Y-m-d"|date:$time2}
<br />
{$str}
<br />
{'abc'|str_replace: 'aaa':$str}






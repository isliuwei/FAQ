<?php
/* Smarty version 3.1.29, created on 2016-06-05 12:42:47
  from "/Applications/XAMPP/xamppfiles/htdocs/smarty/test/tpl/test.tpl" */

if ($_smarty_tpl->smarty->ext->_validateCompiled->decodeProperties($_smarty_tpl, array (
  'has_nocache_code' => false,
  'version' => '3.1.29',
  'unifunc' => 'content_5754022719f604_09441237',
  'file_dependency' => 
  array (
    '77bb11c0a780a0592e88043e39b0c4e60174818f' => 
    array (
      0 => '/Applications/XAMPP/xamppfiles/htdocs/smarty/test/tpl/test.tpl',
      1 => 1465123355,
      2 => 'file',
    ),
  ),
  'includes' => 
  array (
  ),
),false)) {
function content_5754022719f604_09441237 ($_smarty_tpl) {
if (!is_callable('smarty_modifier_capitalize')) require_once '/Applications/XAMPP/xamppfiles/htdocs/smarty/smarty/plugins/modifier.capitalize.php';
if (!is_callable('smarty_modifier_date_format')) require_once '/Applications/XAMPP/xamppfiles/htdocs/smarty/smarty/plugins/modifier.date_format.php';
echo (($tmp = @$_smarty_tpl->tpl_vars['title']->value)===null||$tmp==='' ? "这里是标题" : $tmp);?>

<br />	
<?php echo smarty_modifier_capitalize($_smarty_tpl->tpl_vars['articletitle']->value);?>

<br />
<?php echo (smarty_modifier_capitalize($_smarty_tpl->tpl_vars['articletitle']->value)).(" Smarty.").("nihao");?>

<br />

<br />
<?php echo (smarty_modifier_date_format($_smarty_tpl->tpl_vars['time']->value,"%H:%M:%S")).(" 格林威治时间 ");?>

<br />
<?php echo smarty_modifier_date_format($_smarty_tpl->tpl_vars['time']->value,"%B %e, %Y");?>

<br />
<?php echo smarty_modifier_date_format($_smarty_tpl->tpl_vars['time']->value,"%B %e, %Y %H:%M:%S");?>

<br />
<?php echo rawurlencode($_smarty_tpl->tpl_vars['url']->value);?>

<br />
<?php echo htmlspecialchars($_smarty_tpl->tpl_vars['html']->value, ENT_QUOTES, 'UTF-8', true);?>

<br />
<?php echo $_smarty_tpl->tpl_vars['javascript1']->value;?>

<br />
<?php echo strtr($_smarty_tpl->tpl_vars['javascript2']->value, array("\\" => "\\\\", "'" => "\\'", "\"" => "\\\"", "\r" => "\\r", "\n" => "\\n", "</" => "<\/" ));?>

<br />
<?php echo nl2br($_smarty_tpl->tpl_vars['content']->value);?>

<br />
<?php if ($_smarty_tpl->tpl_vars['name1']->value == 'admin') {?>
welcome <?php echo $_smarty_tpl->tpl_vars['name1']->value;?>
;
<?php }?>
<br />
<?php if ($_smarty_tpl->tpl_vars['name2']->value == 'admin') {?>
welcome <?php echo $_smarty_tpl->tpl_vars['name2']->value;?>
;
<?php } else { ?>
welcome <?php echo $_smarty_tpl->tpl_vars['name2']->value;?>
;
<?php }?>
<br />
<?php if ($_smarty_tpl->tpl_vars['name3']->value == 'admin') {?>
welcome <?php echo $_smarty_tpl->tpl_vars['name3']->value;?>
;
<?php } elseif ($_smarty_tpl->tpl_vars['name3']->value == 'guest') {?>
welcome <?php echo $_smarty_tpl->tpl_vars['name3']->value;?>
;
<?php } else { ?>
welcome <?php echo $_smarty_tpl->tpl_vars['name3']->value;?>
;
<?php }?>
<br />
<table border='1'>
	{
		foreach item=book from=$bookList
	}
	<tr>
		<td><?php echo $_smarty_tpl->tpl_vars['book']->value['name'];?>
</td>
		<td><?php echo $_smarty_tpl->tpl_vars['book']->value['price'];?>
</td>
	</tr>
	{
		/foreach
	}
	
</ul>




<?php }
}

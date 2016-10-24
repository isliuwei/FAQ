<!doctype html>
<html class="no-js">
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>feelingsmedia后台管理</title>
    <meta name="description" content="这是一个 table 页面">
    <meta name="keywords" content="table">
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
    <meta name="renderer" content="webkit">
    <meta http-equiv="Cache-Control" content="no-siteapp" />
    <base href="<?php echo site_url();?>">

    <link rel="icon" type="image/png" href="assets/i/favicon.png">
    <link rel="apple-touch-icon-precomposed" href="assets/i/app-icon72x72@2x.png">
    <meta name="apple-mobile-web-app-title" content="Amaze UI" />
    <link rel="stylesheet" href="assets/css/amazeui.min.css"/>
    <link rel="stylesheet" href="assets/css/admin.css">
    <link rel="stylesheet" href="assets/css/amazeui.chosen.css"/>
    <link rel="stylesheet" href="assets/css/amazeui.datatables.min.css"/>
    <style>
        #search{
            float: right;
            padding-right: 30px;
            padding-bottom: 20px;
        }
        #result{
            float: left;
            margin-left: 20px;
            margin-top: 10px;
        }
        #page{
            float: right;
            margin-right: 20px;
        }
        p{
        	margin: 5px !important;
        }
        td{
        	vertical-align: middle !important;
        }
        .am-offcanvas-content {
		     padding: 0px; 
		     
		}
		.am-offcanvas-content a{
			/*color: #0e90d2;*/
			color: #e0690c;
		}
		.am-panel-footer{
			color: #e0690c;
		}
		#alert{
			visibility: hidden;
		}
        .am-add{
            margin-top: 20px;
            margin-bottom: 20px;
        }
		
    </style>
</head>
<body>
<!--[if lte IE 9]>
<p class="browsehappy">你正在使用<strong>过时</strong>的浏览器，Amaze UI 暂不支持。 请 <a href="http://browsehappy.com/" target="_blank">升级浏览器</a>
    以获得更好的体验！</p>
<![endif]-->

<?php include 'admin-header.php'; ?>

<div class="am-cf admin-main">
    <?php include 'admin-sidebar.php'; ?>

    <!-- content start -->
    <div class="admin-content">

        <div class="am-cf am-padding">
            <div class="am-fl am-cf"><strong class="am-text-primary am-text-lg">首页轮播图列表</strong> / <small>carousel list</small></div>
        </div>
        <div class="am-g am-add">
      <div class="am-u-sm-12 am-u-md-6">
        <div class="am-btn-toolbar">
          <div class="am-btn-group am-btn-group-xs">
            <button type="button" class="am-btn am-btn-default"><span class="am-icon-plus"></span><a href="admin/add_case"> 新增案例</a></button>
          </div>
        </div>
      </div>
    </div>



<div class="admin-content">       
<div class="am-g">
<div class="am-u-sm-12">
<table class="am-table am-table-striped am-table-bordered am-table-compact" id="example">
<thead>
  	<tr>
    	<th class="table-type">轮播图主题</th>
        <th class="table-type">轮播图描述</th>
        <th class="table-type">轮播图缩略图</th>
        <th class="table-type">操作</th>
  	</tr>
</thead>
<tbody id="tbody">
<?php
	$num = 0;
    foreach($cases as $case){
    $num++;
?>

  <tr class="<?php echo $num%2==0?'odd' : 'even' ;?>">
    <td><?php echo $case -> case_time; ?></td>
    <td>
    	<p class="am-text-success">
    		<span class="am-icon-copyright"></span>
    		<?php echo $case -> case_mainTitle; ?>
    	</p>
    	<p class="am-text-success">
    		<span class="am-icon-qrcode"></span>
    		<?php echo $case -> case_subTitle; ?>
    	</p>
    </td>
    <td>
    	<p class="am-text-danger">
    		<span class="am-icon-language"></span>
    		<?php echo $case -> case_desc; ?>
    	</p>

    </td>
    <td>
    	<p class="am-text-danger">
    		<span class="am-icon-phone"></span>
    		<?php echo $case -> case_cate; ?>
    		</a>
    	</p>
    
    </td>
    
    <td>
    	<p class="am-text-default">
    		<span class="am-icon-navicon"></span>
    		<?php echo mb_substr($case -> case_content, 0,8)."......"; ?>
    	</p>

    </td>
    
<td selector="<?php echo $case -> case_id; ?>">
    <div class="am-btn-toolbar" >
        <div class="am-btn-group am-btn-group-xs">
        	<button data-id="<?php echo $case -> case_id; ?>" class="am-btn am-btn-default am-btn-xs  am-hide-sm-only am-radius am-btn-block" data-am-modal="{target: '#my-popup<?php echo $case -> case_id ;?>'}"><span class="am-icon-search"></span> 查&nbsp;&nbsp;&nbsp;&nbsp;看</button> 
            

            <button data-id="<?php echo $case -> case_id; ?>" class="am-btn am-btn-default am-btn-xs  am-hide-sm-only am-radius am-btn-block"><a style="display:block;" href="admin/case_edit/<?php echo $case -> case_id ;?>"> <span class="am-icon-pencil"></span> 编&nbsp;&nbsp;&nbsp;&nbsp;辑</a></button>

            <button data-id="<?php echo $case -> case_id; ?>" class="am-btn am-btn-default am-btn-xs  am-hide-sm-only am-radius am-btn-block am-btn-delete"><span class="am-icon-trash-o"></span> 删&nbsp;&nbsp;&nbsp;&nbsp;除</button>

           

           

<!-- 侧边栏内容 -->
<div class="am-popup" id="my-popup<?php echo $case -> case_id; ?>">
  <div class="am-popup-inner">
    <div class="am-popup-hd">
      <h4 class="am-popup-title">案例详细信息</h4>
      <span data-am-modal-close
            class="am-close">&times;</span>
    </div>
    <div class="am-popup-bd">
      <div class="am-panel-bd" style="text-align:center;">
                <img class="am-circle" src="<?php echo $case -> case_img ;?>" width="100" height="100"/>
        </div>

        <ul class="am-list am-list-border">
            <li>
                <a href="javascript:;"><span class="am-icon-copyright"></span>
                案例主标题：<?php echo $case -> case_mainTitle; ?>
                </a>
            </li>
            <li>
                <a href="javascript:;"><span class="am-icon-briefcase"></span>
                案例副标题：<?php echo $case -> case_subTitle; ?>
                </a>
            </li>
            <li>
                <a href="javascript:;"><span class="am-icon-briefcase"></span>
                案例类别：<?php echo $case -> case_cate; ?>
                </a>
            </li>
            <li>
                <a href="javascript:;"><span class="am-icon-connectdevelop"></span>
                案例描述：<?php echo $case -> case_desc; ?>
                </a>
            </li>
             <li>
                <a href="javascript:;"><span class="am-icon-connectdevelop"></span>
                案例内容：<?php echo $case -> case_content; ?>
                </a>
            </li>
            <li>
                <a href="javascript:;"><span class="am-icon-calendar-check-o"></span>
                案例时间：<?php echo $case -> case_time; ?>
                </a>
            </li>
            
        </ul>

        
    
    </div>
  </div>
</div>

        </div>
    </div>
</td>   

  </tr>
  <?php 
  	}
  ?>
  </tbody>
</table>

                
</div>
</div>
</div>


<button
	id="alert"
  type="button"
  class="am-btn am-btn-primary"
  data-am-modal="{target: '#my-alert'}">
 
</button>

<div class="am-modal am-modal-alert" tabindex="-1" id="my-alert">
  <div class="am-modal-dialog">
    <div class="am-modal-hd">提示</div>
    <div class="am-modal-bd">
     删除成功！
    </div>
    <div class="am-modal-footer">
      <span class="am-modal-btn">确定</span>
    </div>
  </div>
</div>





        




<!-- <footer>
    <hr>
    <p class="am-padding-left">© 2014 AllMobilize, Inc. Licensed under MIT license.</p>
</footer> -->


<?php include 'copyright.php'; ?>

<!--[if lt IE 9]>
<script src="http://libs.baidu.com/jquery/1.11.1/jquery.min.js"></script>
<script src="http://cdn.staticfile.org/modernizr/2.8.3/modernizr.js"></script>
<script src="assets/js/amazeui.ie8polyfill.min.js"></script>
<![endif]-->

<!--[if (gte IE 9)|!(IE)]><!-->
<script src="assets/js/jquery.min.js"></script>
<!--<![endif]-->
<script src="assets/js/amazeui.min.js"></script>
<script src="assets/js/app.js"></script>
<script src="assets/js/amazeui.chosen.min.js"></script>
<script src="assets/js/underscore.min.js"></script>
<script src="assets/js/amazeui.datatables.min.js"></script>
<script>
	jQuery.extend(jQuery.fn.dataTableExt.oSort, {
		  "chinese-string-asc": function(s1, s2) {
		    return s1.localeCompare(s2);
	  	},

		  "chinese-string-desc": function(s1, s2) {
		    return s2.localeCompare(s1);
	  	}
	});


	
	$(function() {
    	$('#example').DataTable();
  	});

</script>
<script>
    
    $(function(){
        $('#tbody').on('click','.am-btn-delete', function(){
            var $case_id = $(this).data('id');
            var $tr = $('tr[selector='+$case_id+']');
            
            $.get('admin/case_delete',{'case_id':$case_id},function(res){
                if(res=='success'){
                    $tr.remove();
                    $('#alert').trigger('click');
                   
                    setTimeout(function(){
                    	location.reload();
                    },3000);
                }
            },'text');

        });

    });
</script>

<script>
    $(function() {
      $('.my-select').chosen();

      $('.chosen-select').chosen({disable_search_threshold: 10});
    });
</script>











<script>
    // $(function() {
    //   $('#doc-prompt-toggle').on('click', function() {
    //     $('#my-prompt').modal({
    //       relatedTarget: this,
    //       onConfirm: function(e) {
    //         $.get('admin/check_delete',{'pwd':e.data},function(res){
    //             if(res == "true"){
    //                 alert('你的密码输入正确！');
    //                 $('.am-btn-delete').removeClass('am-disabled');
    //             }else{
    //                 alert('你的密码输入错误，无法进行后续操作！');
    //             }
    //         });
    //       },
    //       onCancel: function(e) {
    //         alert('你的输入有误!');
    //       }
    //     });
    //   });
    // });
</script>










</body>
</html>

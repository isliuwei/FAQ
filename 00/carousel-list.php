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
  <link rel="stylesheet" href="css/blue.css">
  <style>
    .icheckbox_square-blue{
      width: 24px;
      height: 24px;
    }
    .none{
      visibility: hidden;
    }
    .am-add{
    	margin-top: 40px;
    	margin-bottom: 10px;
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
      <div class="am-fl am-cf"><strong class="am-text-primary am-text-lg">首页轮播图管理界面</strong> / <small>Carousel</small></div>
    </div>

    <div class="am-g am-add">
      <div class="am-u-sm-12 am-u-md-6">
        <div class="am-btn-toolbar">
          <div class="am-btn-group am-btn-group-xs">
            <button type="button" class="am-btn am-btn-default"><span class="am-icon-plus"></span><a href="admin/add_carousel"> 新增</a></button>
          </div>
        </div>
      </div>
    </div>

    <div class="am-g">
      <div class="am-u-sm-12">
          <table class="am-table am-table-striped am-table-hover table-main">
            <thead>
              <tr>
                <th class="table-check"><input type="checkbox" /></th>
                <th class="table-id">ID</th>
                <th class="table-title">轮播图主题</th>
                <th class="table-title">轮播图描述</th>
                <th class="table-type">轮播图缩略图</th>
                <th class="table-set">操作</th>
              </tr>
          </thead>
          <tbody id="tbody">
          <!-- <?php
            foreach($partners as $img){
          ?>
              <tr>
                <td><input type="checkbox" /></td>
                <td><?php echo $img -> id; ?></td>
                <td><?php echo $img -> partner_name; ?></td>
                <td><?php echo $img -> partner_web; ?></td>
                <td><img class="am-circle" src="<?php echo $img -> partner_img; ?>" width="50px" height="50px" alt="<?php echo $img -> partner_name;?>" /></td>
                <td selector="<?php echo $img -> id; ?>">
                  <div class="am-btn-toolbar">
                    <div class="am-btn-group am-btn-group-xs">
                      <button class="am-btn am-btn-default am-btn-xs am-text-secondary" ><span class="am-icon-pencil-square-o"></span><a href="admin/partner_edit/<?php echo $img -> id; ?>"> 编辑</a></button>
                      <button class="am-btn am-btn-default am-btn-delete am-btn-xs am-text-secondary" data-id="<?php echo $img -> id; ?>" ><span class="am-icon-trash-o"></span> 删除</button>
                    </div>
                  </div>
                </td>
              </tr>
          <?php
            }
          ?> -->
          </tbody>
        </table>
      </div>

    </div>
  </div>
  <!-- content end -->
</div>

<a href="#" class="am-icon-btn am-icon-th-list am-show-sm-only admin-menu" data-am-offcanvas="{target: '#admin-offcanvas'}"></a>

<!-- <footer>
  <hr>
  <p class="am-padding-left">© 2014 AllMobilize, Inc. Licensed under MIT license.</p>
</footer> -->

<?php include 'copyright.php'; ?>


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
<script src="js/icheck.js"></script>
<script>
  $('input').iCheck({ checkboxClass: 'icheckbox_square-blue', radioClass: 'iradio_square-blue', increaseArea: '20%'  });
</script>

<script>
    
    $(function(){
        $('#tbody').on('click','.am-btn-delete', function(){
        	
            var $partner_id = $(this).data('id');
            var $tr = $('tr[selector='+$partner_id+']');
            

            
            $.get('admin/partner_delete',{'partner_id':$partner_id},function(res){
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




</body>
</html>

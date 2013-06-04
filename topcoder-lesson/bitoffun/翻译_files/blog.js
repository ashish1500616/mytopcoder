//blogjs
//by www.eol.cn

var rootDomain = 'eol.cn';
var loginUrl = 'http://reg.'+rootDomain;
var centerUrl = 'http://i.'+rootDomain;

var blogDomain = 'blog.edu.cn';
var blogUrl = 'http://.' + blogDomain;
var blogImg = 'http://i.' + blogDomain;

var blogInfo = new Array();
var notic_info = '';


//登录类
var Passport = {
	signCook: 'REG1101',
	errCook: 'LoginError',
	timeHandle: null,
	msg:null,
	tarFm:'',
	args:[],
	listenCookie: function() {
		Passport.msg = '';
		var sCookie = Passport.getCookie(Passport.signCook);
		if(sCookie=='Y') {
			Passport.msg = decodeURI(Passport.getCookie('eol_name'))+loginYes;
			/*
			loginYes = '，已登录！ <a href="#" onclick="Passport.logout();return false;">退出</a> <a href="'+centerUrl+'/blog_post.php?type=vipblog" target="_blank">发博文</a>&nbsp;<a href="'+centerUrl+'/vipblog.php" target="_blank">博客管理</a>&nbsp;<a href="'+centerUrl+'/public/toblog.php?id='+Passport.getCookie('eol_userid')+'" target="_blank">我的博客</a>&nbsp;';
			*/
			loginYes = '，已登录！ <a href="#" onclick="Passport.logout();return false;"  class="body_835249">退出</a>　<a href="'+centerUrl+'/blog_post.php?type=vipblog" target="_blank"  class="black">发博文</a>　<a href="'+centerUrl+'/blog.php" target="_blank"  class="black">博文管理</a>　<a href="'+centerUrl+'/vipblog.php" target="_blank"  class="black">博客设置</a>　<a href="'+centerUrl+'/public/toblog.php?id='+Passport.getCookie('eol_userid')+'" target="_blank" class="black">我的博客</a>&nbsp;';

			Passport.showMsg();
		}else if(Passport.getCookie('LoginError')){
			Passport.showMsg();
		}
	},
	doListen: function() {
		
		Passport.tarFm = Passport.tarFm || '1';
		//alert(Passport.tarFm);
		$('loginform'+Passport.tarFm).action = loginUrl + '/interface/sublogin.php?ispanel=2&from='+encodeURI("http://blog.edu.cn/edulogin.php");
		//alert($('loginform'+Passport.tarFm).action);
		
		Passport.timeHandle = setInterval('Passport.listenCookie()',500);
		//$('loginform'+Passport.tarFm).submit();
	},
	showMsg: function(flag) {
		clearInterval(Passport.timeHandle);
		if(Passport.msg) {
			$('loginSpan1').innerHTML = Passport.msg;
			if($('loginSpan2')) $('loginSpan2').innerHTML = Passport.msg;
			/**if(Passport.tarFm == '2' && Passport.check()) {
				
				//jump to another page with result messages.
				$('commentform').submit();
				
				doComment();
			}*/
			if(flag) doComment();
		}
		else {
			//$('loginSpan'+tarFm).innerHTML = loginNo;
			//alert(Passport.tarFm);
			//$('loginSpan'+Passport.tarFm).innerHTML = Passport.msg || $('loginSpan'+Passport.tarFm).innerHTML+'&nbsp;<font color="red">'+decodeURI(Passport.getCookie('LoginError')).replace(/\+/g,'')+'</font>';
			alert(decodeURI(Passport.getCookie('LoginError')).replace(/\+/g,''));
		}
		/*
		if(navigator.userAgent.toLowerCase())
			$('eiTopL').style.paddingTop = '0px';
		Passport.delCookie(Passport.errCook,'/',rootDomain);
		*/
	},
	isLogin: function(el) {
		//alert(Passport.getCookie(Passport.signCook));
		//Passport.tarFm = el;
		var span = 'loginSpan' + el;
		if(Passport.getCookie(Passport.signCook)=='Y') {
			if($(span)) $(span).innerHTML = decodeURI(Passport.getCookie('eol_name'))+loginYes;
		}else {
			//alert(loginNo.replace(/_\$_/,Passport.tarFm));
			//$(el).innerHTML = loginNo.replace(/_\$_/,Passport.tarFm);
			$('loginSpan1').innerHTML = loginNo;
			if($('loginSpan2')) $('loginSpan2').innerHTML = '你还没有登录，<a href="#">现在登录</a>';
			//if(el == '2') $(span).innerHTML = loginNo2;
			/*if(el == 'loginSpan2') 
				$('_login').onclick = function() {
					
				}*/
			//if($('loginSpan2')) 
			//	$('loginform2').action = loginUrl + '/interface/sublogin.php?ispanel=2&from='+encodeURI(blogUrl+"/edulogin.php");
			
		}
	},
	logout: function() {
		//$('logoutform').target = "loginifr";
		Passport.delCookie(Passport.signCook,'/',"."+blogDomain);
		Passport.delCookie(Passport.errCook,'/',"."+blogDomain);
		//document.cookie = '';
		$('logoutform').action = loginUrl + '/interface/sublogout.php';
		$('logoutform').submit();
		$('loginSpan1').innerHTML = loginNo;
		if($('loginSpan2')) $('loginSpan2').innerHTML = '你还没有登录，<a href="#">现在登录</a>';
		//$('eiTopL').style.paddingTop = '0px';
		
		Passport.msg = '';
		
	},
	getCookie: function(cookie_name) {
		var aCookie = document.cookie.split(";");
		try {
			for (var i=0; i<aCookie.length; i++) {
				var aCrumb = aCookie[i].split("=");//alert(aCrumb[0]+' '+aCrumb[1]);
				aCrumb[0] = aCrumb[0].replace(/^\s+/,'').replace(/\s+$/,'');
				if (cookie_name == aCrumb[0]) return aCrumb[1].replace(/^\s+/,'').replace(/\s+$/,'');
			}
		}catch(e){ return false;}
		return false;
	},
	delCookie: function(name,path,domain) {
		//alert(name + "=" + ((path) ? "; path=" + path : "") + ((domain) ? "; domain=" + domain : "") + "; expires=Thu, 01-Jan-70 00:00:01 GMT");
		document.cookie = name + "=" + ((path) ? "; path=" + path : "") + ((domain) ? "; domain=" + domain : "") + "; expires=Thu, 01-Jan-70 00:00:01 GMT";
	},

	check:function() {
		var u = $('content');
		if(u.value.length<1 || u.value.match(/^\s+/)) {
			window.alert('留言内容不能为空');
			u.focus();
			return false;
		}else {
			if(u.value.length>200) {
				window.alert('留言内容不能超过200个字');
				u.focus();
				return false;
			}
		}
		return true;
	},
	display:function() {
		//var u = $('loginSpan');
		var w = $('noname');
		//alert(w.checked);
		if(w.checked) {
			infoMessage = $('loginSpan').innerHTML;
			$('loginSpan').innerHTML = 'EOL网友';
			$('fromname').value = '1';
		}else {
			$('loginSpan').innerHTML = infoMessage;
		}
	}
}
//ajax请求
function httpRequest() { this.ro = null; this.initRequest(); }
httpRequest.prototype = {
	initRequest: function() {
		var self = this;
		if(this.ro != null) return this.ro;
		try {
			this.ro = new XMLHttpRequest();
		}catch(e) {
			this.ro = new ActiveXObject("Microsoft.XMLHTTP");
		}
		this.ro.onreadystatechange = function() {
			if (self.ro.readyState == 4) {
				clearInterval(self.tl);
				if(self.ro.status == 200)
					self.success();
				else self.failure();
			}else 
				self.loading();
		}
	
	},
	request: function(url,obj) {
		obj.method = obj.method || 'get';
		url = obj.param?url+(url.indexOf('?')>-1?'&':'?')+obj.param:url;
		try {
			this.ro.open(obj.method,url,true);
			if(obj.method == 'post')
				this.ro.setRequestHeader("Content-type","application/x-www-form-urlencoded");
			//this.param = this.param || obj.param;alert(this.param);
			this.s = obj.onSuccess;
			this.l = obj.onLoading;
			this.f = obj.onFailure;
			this.el = obj.el;
			if(obj.timeout) {
				this.t = 1000*obj.timeout + (new Date()).getTime();
				this.tl = setInterval(this.listen,500);
			}
			//alert(this.tl);
			this.ro.send(this.param?this.param:null);
		}catch(e) {}
		
	},
	success: function() {
		//alert(this.tl);
		if(typeof this.s == 'function')
			(this.s)(this.ro,this.el);
		else return;
	},
	loading: function() {
		if(typeof this.l == 'string')
			eval(this.l+"()");
		else if(typeof this.l == 'function')
			(this.l)(this.el);
		else return;
	},
	failure: function() {
		if(typeof this.f == 'string')
			eval(this.f+"()");
		else if(typeof this.f == 'function')
			(this.f)(this.ro,this.el);
		else return;
	},
	serialize: function(fm) {
		//alert('xxxxxxxxx');
		var res = [];
		var eles = $(fm).elements;
		for(var i=0;i<eles.length;i++)
			res[i] = encodeURI(eles[i].name)+'='+encodeURI(eles[i].value);
		this.param = res.join('&');
		//alert(this.param);
	},
	listen: function() {
		if(this.tl)
			if((new Date()).getTime()>this.t && this.ro.readyState!=4) {
				this.ro.abort();
				clearInterval(this.tl);
			}
	},
	alert: function(test) {
		//alert(this.serialize(test));
		document.write(unescape(this.serialize(test)));
	}
	
}
//简化调用函数
function $()
{
	var elements = new Array();
	for(var i=0;i<arguments.length;i++) {
		var element = arguments[i];
		if(typeof element == "string")
			element = document.getElementById(element) || document.getElementsByName(element)[0];
		if(arguments.length == 1)
			return element;
		elements.push(element);
	}
	return elements;
}
//自动加载函数

function loadArtical(url,ele,msg)
{
	if($(ele))
	{
		var obj = new Object();
		obj.msg = msg;
		obj.onSuccess=function(r){
				$(ele).innerHTML = r.responseText;
			};
		obj.onLoading=function(){
				$(ele).innerHTML = (typeof obj.msg=='undefined')?'内容读取中…':obj.msg[1];
			};
		obj.onFailure=function(){
				$(ele).innerHTML = (typeof obj.msg=='undefined')?'无内容':obj.msg[2];
			};
		(new httpRequest()).request(url,obj);
	}
}
//加载博客信息
function loadBlogInfo(msg)
{

	var obj = new Object();
	obj.msg = msg;
	if(0/*blogInfo*/)
	{
		$("bloginfo_name").innerHTML = blogInfo[1];
		$("bloginfo_info").innerHTML = blogInfo[2];
		if($("bloginfo_inform"))
			$("bloginfo_inform").innerHTML = blogInfo[3];
	}
	else
	{
		obj.onSuccess=function(r){
				var rtArr = r.responseText.split('|');
				$("bloginfo_name").innerHTML = rtArr[1];
				$("bloginfo_info").innerHTML = rtArr[2];
				if($("bloginfo_inform"))
					$("bloginfo_inform").innerHTML = rtArr[3];
			};
		obj.onLoading=function(){
			if($("bloginfo_inform"))
				$("bloginfo_info").innerHTML = (typeof obj.msg=='undefined')?'内容读取中…':obj.msg[1];
			};
		obj.onFailure=function(){
			if($("bloginfo_inform"))
				$("bloginfo_info").innerHTML = (typeof obj.msg=='undefined')?'无内容':obj.msg[2];
			};
		(new httpRequest()).request("/cache/bloginfo.html",obj);
	}
	//alert( "ID:" +Passport.getCookie("eol_userid") );
	//需要判断用户是否已经登录
	//var seeuserid = Passport.getCookie("eol_userid");
	var seeissee = Passport.getCookie("issee");
	if(/*seeuserid &&*/ seeissee!="Y" )
	{
	    //alert( "ID:" + seeuserid + ":" + seeissee );
		var obj2 = new Object();
		(new httpRequest()).request("/actsee.php",obj2);
	}
}

//自动加载浏览量
Array.prototype.unique = function()
{
	var i = 0, j = 0;
	while (undefined !== this[i]) {
		j = i + 1;
		while(undefined !== this[j]) {
			if (this[i] === this[j]) this.splice(j, 1);
			++j;
		}
		++i;
	}
	return this;
}
function loadCount()
{
	var spans = document.getElementsByTagName('span');
	if(spans.length < 1 )
		return false;

	var newspans=[];
	var newsid;
	var j=0;
	for(var i=0;i<spans.length;i++) {
		
		var sp = spans[i];
		if(newsid = sp.id.match(/^(\d+count)_(1|2)$/))
		{
			newspans[j] = newsid[1];
			j++;
		}
	}
	var newspans = newspans.unique();

	var obj = new Object();

	for(var i=0;i<newspans.length;i++) {
		obj.onSuccess=function(r,ele){
			if(ele)
			{
				var rtArr = r.responseText.split('|');
				var s1 = ele + "_1";
				var s2 = ele + "_2";
				$(s1).innerHTML = rtArr[0];
				$(s2).innerHTML = rtArr[1];//0|1

			}
		};
		obj.onLoading=function(ele){
				//if($(ele)) $(ele).innerHTML = '0';
		};
		obj.onFailure=function(r,ele){
			//if(r.status != 404)
				//$(ele).innerHTML = '0';
		};

		var sp = newspans[i];
		var url = '/count/'+sp+'.html';
		obj.el = sp;
		try {
			(new httpRequest()).request(url,obj);
		} catch(e){}
	}
}


//评论登录
function loginComment(dir,id)
{
	//Passport.tarFm = '2';
	//Passport.args.push([dir,id]);
	//Passport.doListen();
	/*var lf2 = $('loginform2');
	if(Passport.getCookie(Passport.signCook)!='Y') {
		if(!lf2.elements['email'].value || !lf2.elements['passwd'].value){
			alert('请输入登录信息');
			clearInterval(Passport.timeHandle);
			return false;
		}
		
		lf2.submit();
		//return false;
	}*/
	if(Passport.getCookie(Passport.signCook)!='Y') {
		alert('请先登录');
		return false;
	}else {
		Passport.args.push([dir,id]);
		doComment();
	}
}
//添加评论
function doComment()
{
	var obj = new Object();
	obj.method = 'post';
	obj.onSuccess=function(r,ele){//alert(Passport.timeHandle);
		//clearInterval(Passport.timeHandle);
		if(r.responseText == 'ok') var msg = '评论发表成功';
		else var msg = r.responseText;
		
		alert(msg);
		initComment('/'+Passport.args[0][0]+'/'+Passport.args[0][1]+'comment.html');
		if(r.responseText == 'ok') $('content').value='';
	};
	obj.onLoading=function(){
		
	};
	obj.onFailure=function(){
		alert('评论提交失败');
	};
	var oRequest = new httpRequest();
	oRequest.serialize('commentform');
	oRequest.request("/action/?act=sendreply&id="+Passport.args[0][1],obj);
}

//初始化所有页面
function initAllPage()
{
  if($("notic_id"))
	$("notic_id").innerHTML = notic_info;

  loadArtical("/right_post.html","right_post");
  loadArtical("/right_sort.html","right_sort");

  loadArtical("/right_comment.html","right_comment");
  loadArtical("/right_link.html","right_link");

  loadArtical("/right_archives.php","right_archives");
  loadArtical("/right_stat.php","right_stat");
  loadArtical("/right_info.php","right_info");

  loadArtical("/right_guest.php","right_guest");
  loadArtical("/right_friend.php","right_friend");
  loadArtical("/right_viewer.php","right_viewer");

  loadCount();
  loadBlogInfo();
}
//初始化日历
function initCalendar()
{
  loadArtical("/right_calendar.php","right_calendar");
}
//初始化评论
function initComment()
{
  //alert(document.location.href);
  var url = document.location.href.match(/^\w+:\/\/[\w.]+(\/\d+)(\/\d+)\.html/);
  url = url[1]+url[2]+'comment.html';
  var obj = new Object();
  obj.onSuccess=function(r){ $('commentlist').innerHTML = r.responseText; };
  obj.onLoading=function(){ $('commentlist').innerHTML = (typeof obj.msg=='undefined')?'内容读取中…':obj.msg[1]; };
  obj.onFailure=function(){ $('commentlist').innerHTML = (typeof obj.msg=='undefined')?'无内容':obj.msg[2]; };
  (new httpRequest()).request(url,obj);
}

//判断图片大小

var flag=false;
function DrawImage(ImgD)
{
	var image=new Image();
	image.src=ImgD.src;
	if(image.width>0 && image.height>0){
		flag=true;
	if(image.width/image.height>= 540/720){
		if(image.width>540){
			ImgD.width=540;
			ImgD.height=(image.height*540)/image.width;
		}else{
			ImgD.width=image.width;
			ImgD.height=image.height;
		}
		ImgD.alt=image.width+"x"+image.height;
	}
	else{
		if(image.height>720){
			ImgD.height=720;
			ImgD.width=(image.width*720)/image.height;
		}else{
			ImgD.width=image.width;
			ImgD.height=image.height;
		}
		ImgD.alt=image.width+"x"+image.height;
		}
	}
}
//加载css
function setActiveCss(msg) {

	var obj = new Object();
	obj.msg = msg;
	var tplid = "tpl1";

	obj.onSuccess=function(r){
			blogInfo = r.responseText.split('|');
			tplid = blogInfo[0];
			//alert(tplid);
			if(!tplid.match("^tpl")) tplid = "tpl1";

			//设置第一个css
			var css=document.getElementById("blogcss");
			//css.setAttribute("href");
			if(tplid.match("_"))
			{
				tplidinfo = tplid.split('_');
				var cssself = blogImg + "/img/"+tplidinfo[0]+".css";
				if(css && css.getAttribute("href") !=cssself)
				{
					//alert("abc");
					css.setAttribute("href",cssself);
				}
				//alert(cssself);
			}
			else
			{
				var cssself = blogImg + "/img/tpl.css";
				if(css && css.getAttribute("href") !=cssself)
				{
					//alert("abc");
					css.setAttribute("href",cssself);
				}
			}
			//设置第二个css
			var css2=document.getElementById("blogcss2");
			var cssself2 = blogImg + "/"+tplid+"/css.css";
			if(css2 && css2.getAttribute("href") !=cssself2)
			{
				css2.setAttribute("href",cssself2);
				//alert(cssself2);
			}
		};
	obj.onLoading=function(){
			//$("bloginfo_info").innerHTML = (typeof obj.msg=='undefined')?'内容读取中…':obj.msg[1];
		};
	obj.onFailure=function(){
			//$("bloginfo_info").innerHTML = (typeof obj.msg=='undefined')?'无内容':obj.msg[2];
		};
	(new httpRequest()).request("/cache/bloginfo.html",obj);

}
setActiveCss();

//信息头
var loginNo = ' 用户名 <input type="text" name="email"  class="input_02" > 密码 <input type="password" name="passwd" class="input_02" > <input type="hidden" name="subcode" value="1101">　<a href="#" class="body_dl" onclick="javascript:Passport.doListen();document.getElementById(\'loginform1\').submit();" >登录</a>　<a href="'+loginUrl+'/register.php" target="_blank"  class="body_dl">注册</a> ';

//var loginNo2 = ' 用户名 <input type="text" name="email"  class="input_01" > 密码 <input type="password" name="passwd" class="input_02" > <input type="hidden" name="subcode" value="1101">　<a href="#" class="body_dl" onclick="javascript:Passport.doListen();document.getElementById(\'loginform2\').submit();" >登录</a>　<a href="'+loginUrl+'/register.php" target="_blank"  class="body_dl">注册</a> ';

var loginYes = '，已登录！ <a href="#" onclick="Passport.logout();return false;"  class="body_835249">退出</a>　<a href="'+centerUrl+'/blog_post.php?type=vipblog" target="_blank"  class="black">发博文</a>　<a href="'+centerUrl+'/blog.php" target="_blank"  class="black">博文管理</a>　<a href="'+centerUrl+'/vipblog.php" target="_blank"  class="black">博客设置</a>　<a href="'+centerUrl+'/public/toblog.php?id='+Passport.getCookie('eol_userid')+'" target="_blank" class="black">我的博客</a>&nbsp;';

//添加统计
document.write('<img src="http://pv.img.eol.cn/images/cer.net/log/blog.png  ?'+Math.round(Math.random()*1e17)+'" width="0" height="0"/>');



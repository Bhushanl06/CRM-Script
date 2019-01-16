vuser_init()
{

	//web_cleanup_cookies();
	
	//web_cache_cleanup();
	
	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_set_max_html_param_len("1664");

	CRM_Login_Popup();

	lr_think_time(10);

	web_add_auto_header("Accept", 
		"text/html, application/xhtml+xml, */*");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate, peerdist");

	web_add_auto_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_auto_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

/*Correlation comment: Automatic rules - Do not change!  
Original value='08cf561d-3ef4-40de-b6f8-d051d91db3c4' 
Name ='CorrelationParameter_24' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_24",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"RequestUrl=*/homepage.aspx*",
		LAST);

	lr_start_transaction("CRM_06_CreateCase_02_ClickCase");

	web_url("homepage.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_root/homepage.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&etc=112&pagemode=iframe&sitemappath=area_service%7cPeople%7cNewSubArea_b823cecf&viewid=%7b00000000-0000-0000-00AA-000010001032%7d", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("CRM_06_CreateCase_02_ClickCase",LR_AUTO);

	lr_think_time(10);

	lr_start_transaction("CRM_06_CreateCase_03_FirstTimeUserExperienceNewCase");

	web_url("page.aspx",
		"URL=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t27.inf",
		"Mode=HTML",
		LAST);

	web_revert_auto_header("X-P2P-PeerDist");

	web_revert_auto_header("X-P2P-PeerDistEx");

	web_add_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

/*Correlation comment: Automatic rules - Do not change!  
Original value='1ecd6a99-f562-42a2-bb2c-d9bfd08305e8' 
Name ='CorrelationParameter_26' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_26",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"RequestUrl=*/Data.aspx*",
		LAST);

/*Correlation comment - Do not change!  Original value='42709735-3edb-4243-ac11-456c85c94bd7' Name ='process' Type ='ResponseBased'*/
	web_reg_save_param_json(
		"ParamName=process",
		"QueryString=$.formData._processControlDataKey._processId",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/Data.aspx*",
		LAST);

/*Correlation comment - Do not change!  Original value='46831689-423c-4c43-9b9d-50425db20926' Name ='formid_1' Type ='ResponseBased'*/
	web_reg_save_param_json(
		"ParamName=formid_1",
		"QueryString=$.formData._formId",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/Data.aspx*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='12b760d5-800c-4f20-ae25-a35ea7446636' 
Name ='CorrelationParameter_36' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_36",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"RequestUrl=*/Data.aspx*",
		LAST);

/*Correlation comment - Do not change!  Original value='636576217430693911' Name ='CorrelationParameter_53' Type ='ResponseBased'*/
	web_reg_save_param_json(
		"ParamName=CorrelationParameter_53",
		"QueryString=$.tokenData[9].Timestamp",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/Data.aspx*",
		LAST);
	
	web_reg_save_param(
		"CorrelationParameter_2129",
		"LB/IC=\"Token\":\"",
		"RB/IC=\",\"Url\":\"\\/APPWEBSERVICES\\/INLINEEDITWEBSERVICE.ASMX\"",
		//"Ord=All",
		//"IgnoreRedirections=No",
		LAST);
		
	web_reg_save_param(
		"CorrelationParameter_2128",
		"LB/IC=\"Token\":\"",
		"RB/IC=\",\"Url\":\"\\/APPWEBSERVICES\\/APPGRIDWEBSERVICE.ASHX\"",
		//"Ord=All",
		//"IgnoreRedirections=No",
		LAST);

	web_url("Data.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/form/Data.aspx?_CreateFromId=&_CreateFromType=&appid=ab18c93f-61e6-e711-a848-000d3ad117e3&counter=1522024938097&etc=112&extraqs=%3fetc%3d112%26process%3d&formid=46831689-423c-4c43-9b9d-50425db20926&oid=&pagemode=iframe&pagetype=entityrecord&process=", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t316.inf", 
		LAST);

	web_add_auto_header("Accept", 
		"*/*");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate");

	web_add_auto_header("Cache-Control", 
		"no-cache");

	web_add_auto_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_add_auto_header("ReferrerReqId",
		"{CorrelationParameter_11}");

	web_add_auto_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/GetString");

/*Correlation comment: Automatic rules - Do not change!  
Original value='eb96a05a-c3df-48de-881d-7da0b21db3da' 
Name ='CorrelationParameter_27' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_27",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		LAST);

	web_custom_request("ResourceManager.asmx", 
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/ResourceManager.asmx", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=utf-8", 
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetString xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><key>SearchWidget.Mobile.Filters.AllDraftArticles</key></GetString></soap:Body></soap:Envelope>", 
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='73a6f0df-9187-47c7-a194-0259ed639932' 
Name ='CorrelationParameter_28' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_28",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		LAST);

	web_custom_request("ResourceManager.asmx_2", 
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/ResourceManager.asmx", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=utf-8", 
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetString xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><key>SearchWidget.Mobile.Filters.AllApprovedArticles</key></GetString></soap:Body></soap:Envelope>", 
		LAST);

	web_revert_auto_header("Cache-Control");

	web_revert_auto_header("LoginRequestCorrelationId");

	web_revert_auto_header("ReferrerReqId");

	web_revert_auto_header("SOAPAction");

	/*web_add_auto_header("Accept-Encoding", 
		"gzip, deflate, peerdist");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("page.aspx_2",
		"URL=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t30.inf",
		"Mode=HTML",
		LAST);*/

	/*web_add_auto_header("Accept-Encoding", 
		"gzip, deflate");

	web_add_auto_header("Cache-Control", 
		"no-cache");

	web_add_auto_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_add_auto_header("ReferrerReqId",
		"{CorrelationParameter_11}");

	web_add_auto_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/GetString");

/*Correlation comment: Automatic rules - Do not change!  
Original value='b9942d21-bade-41ad-be5b-99b1f77f5fd5' 
Name ='CorrelationParameter_29' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_29",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		LAST);

	web_custom_request("ResourceManager.asmx_3", 
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/ResourceManager.asmx", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=utf-8", 
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetString xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><key>SearchWidget.Mobile.Filters.AllPublishedArticles</key></GetString></soap:Body></soap:Envelope>", 
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='7fccd806-b5e9-4a62-b207-4ffb0a07e62f' 
Name ='CorrelationParameter_30' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_30",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		LAST);

	web_custom_request("ResourceManager.asmx_4", 
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/ResourceManager.asmx", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=utf-8", 
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetString xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><key>SearchWidget.Mobile.Filters.AllScheduledArticles</key></GetString></soap:Body></soap:Envelope>", 
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='eef1449b-1ddb-455a-afa5-95a73f5bb76a' 
Name ='CorrelationParameter_31' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_31",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		LAST);

	web_custom_request("ResourceManager.asmx_5", 
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/ResourceManager.asmx", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t33.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=utf-8", 
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetString xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><key>SearchWidget.Mobile.Filters.AllExpiredArticles</key></GetString></soap:Body></soap:Envelope>", 
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='8e1cab83-3b72-4299-b98a-047db708365c' 
Name ='CorrelationParameter_32' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_32",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		LAST);

	web_custom_request("ResourceManager.asmx_6", 
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/ResourceManager.asmx", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=utf-8", 
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetString xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><key>SearchWidget.Mobile.Filters.AllArchivedArticles</key></GetString></soap:Body></soap:Envelope>", 
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='ed955c16-e8c0-45f0-a972-450a39fa6fde' 
Name ='CorrelationParameter_33' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_33",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		LAST);

	web_custom_request("ResourceManager.asmx_7", 
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/ResourceManager.asmx", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t35.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=utf-8", 
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetString xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><key>SearchWidget.Mobile.Filters.AllTrashedArticles</key></GetString></soap:Body></soap:Envelope>", 
		LAST);

	web_revert_auto_header("Cache-Control");
	web_revert_auto_header("LoginRequestCorrelationId");
	web_revert_auto_header("ReferrerReqId");
	web_revert_auto_header("SOAPAction");

	/*web_add_auto_header("Accept-Encoding", 
		"gzip, deflate, peerdist");

	web_add_auto_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_auto_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("page.aspx_3",
		"URL=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t36.inf",
		"Mode=HTML",
		LAST);*/

	web_add_auto_header("Accept","text/html, */*; q=0.01");

	web_url("notesv2template.aspx",
		"URL=https://{param_URL}.crm6.dynamics.com/_controls/notes/notesv2template.aspx?lcid=1033&ver=-2068631631",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t37.inf",
		"Mode=HTML",
		LAST);

	web_url("ActivitiesWallContent.aspx",
		"URL=https://{param_URL}.crm6.dynamics.com/_static/WallControl/ActivitiesWallContent.aspx?ver=-2068631631",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t38.inf",
		"Mode=HTML",
		LAST);

	web_url("WallContent.1033.htm",
		"URL=https://{param_URL}.crm6.dynamics.com/%7B636567693290000510%7D/WebResources/msdyn_/WallContent.1033.htm?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=-2068631631",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t39.inf",
		"Mode=HTML",
		LAST);

	web_url("FirstRunContent.1033.htm",
		"URL=https://{param_URL}.crm6.dynamics.com/%7B636567693290000510%7D/WebResources/msdyn_/FirstRunContent.1033.htm?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=-2068631631",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t40.inf",
		"Mode=HTML",
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("Accept", 
		"*/*");

	web_add_header("FormLoadId", 
		"{61832369-0ee9-1055-a44b-5695cb830697}");

	web_add_header("x-crm-original", 
		"null");

/*Correlation comment - Do not change!  Original value='2286cef5-5237-4a7f-9023-41ad0af2b9b6' Name ='formid' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=formid",
		"RegExp=:\\[\\\\\"(.*?)\\\\\",",
		"Ordinal=5",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);
//https://{param_URL}.crm6.dynamics.com/_imgs/search_normal.gif

	web_url("layout.aspx",
		"URL=https://{param_URL}.crm6.dynamics.com/_forms/read/layout.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&etc=112&formid=&formts=1525827372045&hash=1525827372045&highcontrast=false&isPreview=False&isTurboForm=true&process=&processts=0",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038",
		"Snapshot=t11.inf",
		"Mode=HTTP",
		EXTRARES,
		"URL=/_imgs/formsections_navigationflyout_button.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_imgs/search_normal.gif", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_imgs/imagestrips/transparent_spacer.gif", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_imgs/AdvFind/progress.gif", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		LAST);

	web_add_auto_header("Accept", 
		"text/html, application/xhtml+xml, */*");

	web_url("ClientApiWrapper.aspx",
		"URL=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038",
		"Snapshot=t12.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=../_imgs/formsections_navigationflyout_button.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=../_imgs/inlineedit/alert.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/cc_shared/knockout/3.2.0/libs/knockout.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=../_imgs/imagestrips/formentityimages.png?ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=../_imgs/imagestrips/inlineedit_images.png?ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=../_imgs/imagestrips/process_control_images.png?ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=../_imgs/imagestrips/entity_imgs.png?ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=../_imgs/theme/Outlook15White/FormFooterGradient.png?ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=../_imgs/dropdown_refresh.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/cc_shared/sol/2.0.0/libs/sol.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/cc_shared/mscommon/1.2.2/libs/mscommon.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=../_static/cs/cases/cases.js?ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=../_static/_common/scripts/formevt.js?ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/Service/Incident/Incident_main_system_library.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=../%7b636609085240000054%7d/webresources/crm/clientutility.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=../%7b636609085240000054%7d/webresources/service/localization/script/resourcestringprovider.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=../%7b636609085240000054%7d/webresources/crm/localization/resourcestringprovider.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/msdyn_/Utils/head.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/msdyn_/Case/Case.Library.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/dhhs_case?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/dhhs_telemetry?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/cc_shared/wijmo/5.20173.403/libs/wijmo/wijmo.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		LAST);

	/*web_url("layout.aspx",
		"URL=https://{param_URL}.crm6.dynamics.com/_forms/read/layout.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&etc=112&formid={formid_1}&formts=3151419&hash=3E332CBCCA2A6A3D1B33B0C79F6816DD648C99B6D91828053473C75C6BFD2944&isPreview=False&isTurboForm=True&outlook=False&process={process}&processts=3152315",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t41.inf",
		"Mode=HTML",
		LAST);

	web_add_auto_header("Accept", 
		"text/html, application/xhtml+xml, *//*");

	web_url("ClientApiWrapper.aspx",
		"URL=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=-2068631631",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t42.inf",
		"Mode=HTML",
		LAST);*/

	web_add_auto_header("Accept", 
		"*/*");

	web_add_auto_header("FormLoadId", 
		"{21d37787-185b-784e-a3a9-2b21b41e11c3}");

	web_add_header("x-crm-mismatch", 
		"other");

	web_url("layout.aspx_2",
		"URL=https://{param_URL}.crm6.dynamics.com/_forms/read/layout.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&etc=112&formid=2286cef5-5237-4a7f-9023-41ad0af2b9b6&formts=5032066&hash=CC3A7E0DE261C7383451B9903626CD435F491EE84A21A148A207B235D39B520C&isPreview=False&isTurboForm=True&outlook=False&process=42709735-3edb-4243-ac11-456c85c94bd7&processts=5033217",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038",
		"Snapshot=t13.inf",
		"Mode=HTTP",
		EXTRARES,
		"URL=/_imgs/formsections_navigationflyout_button.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_imgs/search_normal.gif", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_imgs/imagestrips/transparent_spacer.gif", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_imgs/AdvFind/progress.gif", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_imgs/processcontrol/processcontrolarrows.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_imgs/processcontrol/process_control_global_active_flag.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_imgs/processcontrol/10_stage_scroll_arrow_left.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_imgs/processcontrol/10_stage_scroll_arrow_right.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/%7B636609085240000054%7D/WebResources/cc_shared/wijmoInput/5.20173.403/libs/wijmo/wijmoInput.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/%7B636609085240000054%7D/WebResources/cc_shared/wijmoGrid/5.20173.403/libs/wijmo/wijmoGrid.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=../formscript.js.aspx?airenabled=true&businessrulesversion=%7b636609084220000061%7d1033&formid=2286cef5-5237-4a7f-9023-41ad0af2b9b6&formname=crmform&fver=874927165&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=Form&etn=incident&hierarchy=2286cef5-5237-4a7f-9023-41ad0af2b9b6&id=Mscrm.CommandBar&ie=1&isTurboForm=True&ise=1&lcid=1033&mver={tstamp}&oc=0&page=&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=activitypointer&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cactivitypointer%7cOneToMany%7cIncident_ActivityPointers&ie=1&ise=1&lcid=1033&mver={tstamp}&oc=0&page=%2f_FORMS%2fREAD%2fLAYOUT.ASPX&relName=Incident_ActivityPointers&relType=OneToMany&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=connection&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cconnection%7cOneToMany%7ccontact_connections1&ie=1&ise=1&lcid=1033&mver={tstamp}&oc=0&page=%2f_FORMS%2fREAD%2fLAYOUT.ASPX&relName=contact_connections1&relType=OneToMany&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=connection&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cconnection%7cOneToMany%7cincident_connections1&ie=1&ise=1&lcid=1033&mver={tstamp}&oc=0&page=%2f_FORMS%2fREAD%2fLAYOUT.ASPX&relName=incident_connections1&relType=OneToMany&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=incident&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cincident%7cOneToMany%7cdhhs_casegroup_incident_Casegroupsid&ie=1&ise=1&lcid=1033&mver={tstamp}&oc=0&page=%2f_FORMS%2fREAD%2fLAYOUT.ASPX&relName=dhhs_casegroup_incident_Casegroupsid&relType=OneToMany&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=dhhs_caseactivity&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cdhhs_caseactivity%7cOneToMany%7cdhhs_incident_dhhs_caseactivity_CaseId&ie=1&ise=1&lcid=1033&mver={tstamp}&oc=0&page=%2f_FORMS%2fREAD%2fLAYOUT.ASPX&relName=dhhs_incident_dhhs_caseactivity_CaseId&relType=OneToMany&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=dhhs_screeningpersons&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cdhhs_screeningpersons%7cManyToMany%7cdhhs_incident_dhhs_screeningpersons_L17&ie=1&ise=1&lcid=1033&mver={tstamp}&oc=0&page=%2f_FORMS%2fREAD%2fLAYOUT.ASPX&relName=dhhs_incident_dhhs_screeningpersons_L17&relType=ManyToMany&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=dhhs_alert&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cdhhs_alert%7cOneToMany%7cdhhs_contact_dhhs_alert_PersonorClient&ie=1&ise=1&lcid=1033&mver={tstamp}&oc=0&page=%2f_FORMS%2fREAD%2fLAYOUT.ASPX&relName=dhhs_contact_dhhs_alert_PersonorClient&relType=OneToMany&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=incident&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cincident%7cNoRelationship%7c&ie=1&ise=1&lcid=1033&mver={tstamp}&oc=0&page=%2f_FORMS%2fREAD%2fLAYOUT.ASPX&relName=&relType=NoRelationship&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/%7B636609085240000054%7D/WebResources/cc_shared/wijmoGridFilter/5.20173.403/libs/wijmo/wijmoGridFilter.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=/%7B636609085240000054%7D/WebResources/msdyn_/Utils/jquery1.4.1.min.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=/%7B636609085240000054%7D/WebResources/msdyn_/SDK/SOAP/Sdk_Soap_min.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=/_imgs/inlineedit/save.png?ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		LAST);

	web_add_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/RetrieveItem");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate");

	web_add_auto_header("Cache-Control", 
		"no-cache");

	web_add_auto_header("ReferrerReqId",
		"{CorrelationParameter_36}");

	web_custom_request("LookupService.asmx",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/LookupService.asmx",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038",
		"Snapshot=t14.inf",
		"Mode=HTML",
		"EncType=text/xml; charset=utf-8",
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><RetrieveItem xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><typesArray><int>8</int></typesArray><guidValues><string>550009ac-59fc-e711-a843-000d3ad07359</string></guidValues><lookupValues></lookupValues><positions></positions><additionalParameters></additionalParameters></RetrieveItem></soap:Body></soap:Envelope>",
		LAST);

	web_add_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/QuerySipInfo");

	web_custom_request("PresenceService.asmx",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/PresenceService.asmx",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038",
		"Snapshot=t15.inf",
		"Mode=HTML",
		"EncType=text/xml; charset=utf-8",
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><QuerySipInfo xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><entityListXml>&#60;grid&#62;&#60;row oid&#61;&#34;&#38;&#35;123&#59;550009AC-59FC-E711-A843-000D3AD07359&#38;&#35;125&#59;&#34; otype&#61;&#34;8&#34;&#47;&#62;&#60;&#47;grid&#62;</entityListXml></QuerySipInfo></soap:Body></soap:Envelope>",
		EXTRARES,
		"URL=../%7B636609085240000054%7D/WebResources/msdyn_/Action/FieldServiceSystemAction/Sdk_msdyn_FieldServiceSystemAction_min.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/msdyn_/Utils/CrudSDK.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/msdyn_/Utils/sdk.jquery.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/msdyn_/Utils/FieldOneSkyUtils.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/msdyn_/Utils/EntityDictionary.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/msdyn_/LocalizationLibrary/Localization.Library.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/cc_shared/wijmoKnockout/5.20173.403/libs/wijmo/wijmoKnockout.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/cc_shared/wijmoGridDetail/5.20173.403/libs/wijmo/wijmoGridDetail.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/cc_shared/wijmoAccessibilityExtender/1.0.0/libs/wijmo/wijmoAccessibilityExtender.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/dhhs_screeningperson?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/cc_shared/gridlib/1.9.17/libs/gridlib.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		"URL=../%7B636609085240000054%7D/WebResources/cc_MscrmControls.Grid.GridControl/Grid.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", ENDITEM,
		LAST);

	lr_end_transaction("CRM_06_CreateCase_03_FirstTimeUserExperienceNewCase",LR_AUTO);

	web_revert_auto_header("FormLoadId");

	web_revert_auto_header("ReferrerReqId");

	web_revert_auto_header("X-P2P-PeerDist");

	web_revert_auto_header("X-P2P-PeerDistEx");

	lr_think_time(10);

	web_revert_auto_header("Cache-Control");
		

	return 0;
}

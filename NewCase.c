NewCase()
{

	
	web_add_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

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
	
	lr_think_time(5);

	lr_start_transaction("CRM_06_CreateCase_03_NewCaseMulti");

	web_url("Data.aspx_2",
		"URL=https://{param_URL}.crm6.dynamics.com/form/Data.aspx?_CreateFromId=&_CreateFromType=&appid=ab18c93f-61e6-e711-a848-000d3ad117e3&counter=1522024942876&etc=112&extraqs=%3fetc%3d112%26formid%3d{formid}%26process%3d&formid={formid}&oid=&pagemode=iframe&pagetype=entityrecord&process=",
		"Resource=1",
		"RecContentType=application/json",
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t423.inf",
		LAST);

	web_add_auto_header("Accept", 
		"*/*");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate");

	web_add_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/RetrieveItem");

	web_add_auto_header("Cache-Control", 
		"no-cache");

	web_add_auto_header("FormLoadId", 
		"{90e54e86-12d1-3a6b-32ae-82426864576d}");

	web_add_auto_header("ReferrerReqId",
		"{CorrelationParameter_36}");

/*Correlation comment: Automatic rules - Do not change!  
Original value='414fded4-c97b-4427-9d29-5cd274f38e6a' 
Name ='CorrelationParameter_37' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_37",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"RequestUrl=*/LookupService.asmx*",
		LAST);

	web_custom_request("LookupService.asmx_2",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/LookupService.asmx",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t47.inf",
		"Mode=HTML",
		"EncType=text/xml; charset=utf-8",
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><RetrieveItem xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><typesArray><int>8</int></typesArray><guidValues><string>{userguid}</string></guidValues><lookupValues></lookupValues><positions></positions><additionalParameters></additionalParameters></RetrieveItem></soap:Body></soap:Envelope>",
		LAST);

	lr_end_transaction("CRM_06_CreateCase_03_NewCaseMulti",LR_AUTO);

	return 0;
}

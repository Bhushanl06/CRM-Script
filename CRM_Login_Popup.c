CRM_Login_Popup()
{

	#include <string.h>
	char path1[1024],path2[1024],path3[1024];
   	char separators[] = "\\"; 
  	char * token,* token1,* pch;
  	char word[] = "x2b";
   	char crmwrpctoken1[1024],crmwrpctoken2[1024],crmwrpctoken3[1024],crmwrpctoken4[1024];


	web_add_cookie("wlidperf=FR=L&ST=1523946042477; DOMAIN=login.microsoftonline.com");

	/*web_add_cookie("buid=AQABAAEAAADX8GCi6Js6SK82TsD2Pb7rbv3jHPYVnnhsyWGihf1LWU42acrZGpoIPzRaI_aOG2jWrOsJl1IA1oqD876BqfmMNWe91SqX2C17GcTU31fYFoXlI9zE6L7z9MoCpVLynQuv29Vq3EZCX7-Z58YdHn4fgllusheoiQOFQy_wwMzgY7eGN2rXEjnS1olmWHzIdQsgAA; DOMAIN=login.microsoftonline.com");

	web_add_cookie("ESTSAUTHPERSISTENT=AQABAAEAAADX8GCi6Js6SK82TsD2Pb7rOLYwfve4XYbxrwixoczK8FdtyoazPSX482k-I6zfuOy6FTXrjXTiCiZRkDyW5IfqcoMERZHjlVnxTw9uADO4QL2la3S98tT2fGBEbjiZKkJgXfbb4p-hzaH_fMvnrnoY9grXOFB4zaTZ7v5um0_FwYvCXEE3ZRSdXZX6KEHea5-PUBqOj1ShnmJLeZVffcq4a7V7VOyduIjTsheqs5qzGhHSKYq8gz1GldhPib65f3VL75Z7zJhBZXLPj7QEE6dQg0nuxayvTCCNWFDAPFJnjBC6HZiYCwPpYG_cX_u1u9pyQ9c0D98MK1piEP_odMjWm6pIIzRviwSXi5rqBQleX3pLnZ07REcs98L2PRdWWeu3t7Rk9hCqbbRk1XrKtJ_7YfV-Oe8zfINTUXtnVTheLyAA; DOMAIN="
		"login.microsoftonline.com");

	web_add_cookie("ESTSSSOTILES=1; DOMAIN=login.microsoftonline.com");

	web_add_cookie("AADSSOTILES=1; DOMAIN=login.microsoftonline.com");*/

	web_add_header("Accept", 
		"text/html, application/xhtml+xml, */*");

	web_add_auto_header("Accept-Language", 
		"en-AU");

	web_add_auto_header("User-Agent", 
		"Mozilla/5.0 (Windows NT 6.3; WOW64; Trident/7.0; rv:11.0) like Gecko");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate, peerdist");

	web_add_auto_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_auto_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

/*Correlation comment: Automatic rules - Do not change!  
Original value='636595438418881160.MTUwOTIyOTAtZmYxNC00YzljLTk2M2QtZDRhMTAyOWViMDBmYzVmZWMyMWEtZjZlNS00NWQ4LWJmNDQtMGE5MzlhNWJjYmVm' 
Name ='CorrelationParameter_22' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='CRMWSFed1'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_22",
		"RegExp=CRMWSFed.nonce.(.*?)&wct",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"RequestUrl=*/main.aspx*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='2018-04-17T06%3a37%3a21Z' 
Name ='wct_3' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='wct1'*/
	web_reg_save_param_regexp(
		"ParamName=wct_3",
		"RegExp=wct=(.*?)&",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"RequestUrl=*/main.aspx*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='5382cb68-ac2b-4a7a-8e62-f6e898ec3a00' 
Name ='hpgrequestid_3' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='hprequestid'*/
	web_reg_save_param_regexp(
		"ParamName=hpgrequestid_3",
		"RegExp=x-ms-request-id:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='AQABAAAAAADX8GCi6Js6SK82TsD2Pb7rja2ATEbZqtxj4HKH5Jglu9kH2Tyn0M54bFTP9L7Pc8jH_-LTD5JzCde56eZ5oa5WBVrW7J1bRePvO_wqde3M8FtiG-pP8liMIVCnG70H31PvGm3p2ox75FhPIugsZsUCEPuAxA-sgBxPWWjDNLXodbHQreiaE3RVGysTVS5Q7yQgAA' 
Name ='esctx_2' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='esctx1'*/
	web_reg_save_param_regexp(
		"ParamName=esctx_2",
		"RegExp=esctx=(.*?);",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Cookies",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='rQIIAb1SPWzTQBi1SRqVKEOFhMTYgWSpbN_ZjmNHiiBN2pKoTkjixiTb-e5cO_GfbIcmGdlBjIiRESEGNthY26UzMxIVYmBCjEQRZQKpYqj0Ld_T-957-vTyTJV30jRKqoJgJ4-dmeW5wTSKQxK5XpjyOPYVniwC5Ls44XHoC_Gt_NbtLy3z_tnD1tvCe2b3aV97zTYuRbAXzkhMiRtTnIbxXwQOhPosdfq_KUIrIHTOoySan7PsBct-ulEwk31KaIxSNwxeZj5norh2kth_oFLs19Z2RQkVRXs1V0q-4pXi2X9e-sgN1iGLko2iyCVFiSALqliTbE6BVOFoBUIOqbLKAQCIhAiEFSqV4sV1O67EwvjYJTWNWlDTkMYRUYScLJEKpxIAuQoAigIg0TCGpSAMMK01-ro5WD2dX6-8IillrSxLqgxVVYVQAbxuHJ10jdaia9TTsT-adxoAjJbe5NCYirrYS8fNvqMb9UXXHLp6c9cfLYf-2NQXurmXjidjrzMAoGP25EOz7XeavVQ_2CvrS8_pmO3JyB_67zJ3MaBglcvmgI0wJ8sa5jSsqhyCQMYytTRbVM-z-a_ZAshUNzdzW5k7zDbzM8u-2lh10jl7Mth5s2w_s35cvPhWZU43BOWoTnd8ZzQdhlp_ZtvT9qNJ33T38WQS6hRZdlRxxOMHpghaNaUKn-cKpznme475cPMje-U-V2VZ-nen711iRnjNPfgF0' 
Name ='ctx_3' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='ctx1'*/
	web_reg_save_param_regexp(
		"ParamName=ctx_3",
		"RegExp=\"sCtx\":\"(.*?)\",",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='5749e715-cb40-4950-ae0c-b900428d5239' 
Name ='CorrelationParameter_23' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='RequestID1'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_23",
		"RegExp=u0026client-request-id=(.*?)\",",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='AQABAAEAAADX8GCi6Js6SK82TsD2Pb7r6b0XYmF4a4_QjPTbfMMk9GNYmPohScbTBVQTPaXd1ACqHSc5_NOSlanDlUjlyhbYAL1K8_ZKoTyHCVj3TfMDJgcM7sB9EKj-yM_1nzQUkJNK-rI2lWhCN-ksHkyRHT8zzcY9ttHNeoVHGGnAGnZlZKb9I5KR50Fx8YY_Ap75-sT2avbpjbAbtxfPuUTJI1KJDIrWxgd3j-Lfcnoia5vXjr9DQht1tdxp4xI3LlvQASW3QqV_x-YVguKfYRn44SmMOwS4DqrIZHcf4npY40g8V2vMJY5MFs2I1nvcqVzpg6bjmWGOCUW9awXffQsifMAzn0s4J1H-VaEFkBj3FFomgiAA' 
Name ='flowToken_3' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='flowtoken2'*/
	web_reg_save_param_regexp(
		"ParamName=flowToken_3",
		"RegExp=\"sFT\":\"(.*?)\",",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='AQABAAAAAADX8GCi6Js6SK82TsD2Pb7rRa20YMmlHVRSKK1Ooa4_U7XzeU2FdpuMQzo7Cbw73lZ9dCe_eUC1AKuiK-L7yHLKljxhLEIIQXlIvQVbqF4oI_z-CcQtxKNd76hQJ60zwjiJHomPihpPUdSbTheEDeFcYFg1WFxptJ4giVcfE0RwgwdZOBjnID1koRHWf0OWoyB2UE6X9UQ56JxG4u8zs6gJ-adqwGIorleVeihXQi9X_iAA' 
Name ='CorrelationParameter_24' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='apicanary1'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_24",
		"RegExp=\"apiCanary\":\"(.*?)\",",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='6UAe+mhYkVo9RuffkJXjRWiFcjjoMeabfp7h2gHW20I=6:1' 
Name ='canary_3' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='canaryid1'*/
	web_reg_save_param_regexp(
		"ParamName=canary_3",
		"RegExp=\",\"canary\":\"(.*?)\",",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		LAST);

	web_url("main.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t873.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Accept", 
		"application/javascript, */*;q=0.8");

	web_concurrent_start(NULL);

	web_url("convergedlogin_pcore.min.js",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/cdnbundles/convergedlogin_pcore.min.js",
		"Resource=1",
		"RecContentType=application/x-javascript",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t874.inf",
		LAST);

	web_add_header("Accept", 
		"text/css, */*");

	web_url("converged.login.min.css",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/cdnbundles/converged.login.min.css",
		"Resource=1",
		"RecContentType=text/css",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t875.inf",
		LAST);

	web_add_header("Accept", 
		"application/javascript, */*;q=0.8");

	web_url("convergedloginpaginatedstrings-en.min.js",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/cdnbundles/convergedloginpaginatedstrings-en.min.js",
		"Resource=1",
		"RecContentType=application/x-javascript",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t876.inf",
		LAST);

	web_add_header("Accept", 
		"*/*");

	web_url("favicon_a.ico", 
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/images/favicon_a.ico", 
		"Resource=1", 
		"RecContentType=image/x-icon", 
		"Referer=", 
		"Snapshot=t877.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_add_header("Accept", 
		"image/png, image/svg+xml, image/*;q=0.8, */*;q=0.5");

	web_concurrent_start(NULL);

	web_url("microsoft_logo.svg",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/images/microsoft_logo.svg?x=ee5c8d9fb6248c938fd0dc19370e90bd",
		"Resource=1",
		"RecContentType=image/svg+xml",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t878.inf",
		LAST);

	web_add_header("Accept", 
		"image/png, image/svg+xml, image/*;q=0.8, */*;q=0.5");

	web_url("12.png",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/images/applogos/12.png?x=e15869494a1446169159c7b1a5e959c0",
		"Resource=1",
		"RecContentType=image/png",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t879.inf",
		LAST);

	web_add_header("Accept", 
		"image/png, image/svg+xml, image/*;q=0.8, */*;q=0.5");

	web_url("picker_more.svg",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/images/picker_more.svg?x=7568a43cf440757c55d2e7f51557ae1f",
		"Resource=1",
		"RecContentType=image/svg+xml",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t880.inf",
		LAST);

	web_add_header("Accept", 
		"image/png, image/svg+xml, image/*;q=0.8, */*;q=0.5");

	web_url("picker_account_aad.svg",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/images/picker_account_aad.svg?x=9de70d1c5191d1852a0d5aac28b44a6c",
		"Resource=1",
		"RecContentType=image/svg+xml",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t881.inf",
		LAST);

	web_add_header("Accept", 
		"image/png, image/svg+xml, image/*;q=0.8, */*;q=0.5");

	web_url("picker_account_add.svg",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/images/picker_account_add.svg?x=56e73414003cdb676008ff7857343074",
		"Resource=1",
		"RecContentType=image/svg+xml",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t882.inf",
		LAST);

	web_add_header("Accept", 
		"image/png, image/svg+xml, image/*;q=0.8, */*;q=0.5");

	web_url("ellipsis_white.svg",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/images/ellipsis_white.svg?x=5ac590ee72bfe06a7cecfd75b588ad73",
		"Resource=1",
		"RecContentType=image/svg+xml",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t883.inf",
		LAST);

	web_add_header("Accept", 
		"image/png, image/svg+xml, image/*;q=0.8, */*;q=0.5");

	web_url("ellipsis_grey.svg",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/images/ellipsis_grey.svg?x=2b5d393db04a5e6e1f739cb266e65b4c",
		"Resource=1",
		"RecContentType=image/svg+xml",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t884.inf",
		LAST);

	web_concurrent_end(NULL);

	//web_add_cookie("ESTSAUTHPERSISTENT={ESTSAUTHPERSISTENT_5}; DOMAIN=login.microsoftonline.com");

	//web_add_cookie("ESTSAUTH={ESTSAUTH_1}; DOMAIN=login.microsoftonline.com");

	web_add_cookie("esctx={esctx_2}; DOMAIN=login.microsoftonline.com");

	web_revert_auto_header("X-P2P-PeerDist");

	web_revert_auto_header("X-P2P-PeerDistEx");

	web_add_header("Accept", 
		"application/json");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate");

	web_add_auto_header("Accept-Language", 
		"en-AU");

	web_add_auto_header("Cache-Control", 
		"no-cache");

	web_add_auto_header("User-Agent", 
		"Mozilla/5.0 (Windows NT 6.3; WOW64; Trident/7.0; rv:11.0) like Gecko");

	web_add_header("canary",
		"{CorrelationParameter_24}");

	web_add_header("client-request-id",
		"{CorrelationParameter_23}");

	web_add_header("hpgact", 
		"1050");

	web_add_header("hpgid", 
		"1104");

	web_add_header("hpgrequestid",
		"{hpgrequestid_3}");

	web_convert_from_formatted("FormattedData=<HP_EXTENSION name=\"JsonXml,Xml\"><object><pair name=\"username\" type=\"str\">{param_UserID}@dhhsvicgovau.onmicrosoft.com</pair><pair name=\"isOtherIdpSupported\" type=\"bool\">false</pair><pair name=\"checkPhones\" type=\"bool\">false</pair><pair name=\"isRemoteNGCSupported\" type=\"bool\">false</pair><pair name=\"isFidoSupported\" type=\"bool\">false</pair><pair name=\"originalRequest\" type=\"str\">{ctx_3}</pair></object></HP_EXTENSION>", 
		"TargetParam=DFE_BODY", 
		LAST);

	lr_start_transaction("CRM_01_a_VerifyUserID");

	web_custom_request("GetCredentialType",
		"URL=https://login.microsoftonline.com/common/GetCredentialType",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t886.inf",
		"Mode=HTTP",
		"EncType=application/json; charset=utf-8",
		"Body={DFE_BODY}",
		LAST);

	lr_end_transaction("CRM_01_a_VerifyUserID",LR_AUTO);

	lr_think_time(3);

	web_add_cookie("CkTst=G1523947050910; DOMAIN=login.microsoftonline.com");

	web_add_cookie("wlidperf=FR=L&ST=1523947088076; DOMAIN=login.microsoftonline.com");

	web_add_auto_header("Accept", 
		"text/html, application/xhtml+xml, */*");

/*Correlation comment: Automatic rules - Do not change!  
Original value='AQABAAEAAABHh4kmS_aKT5XrjzxRAtHzeJe0cH9ImBrQyJYdl6xR6cEp2AtTHKuNsMhZbSus-_yEDWXBrtycbyDSq6swh1faGvoLqqxmJQ1XipaR1Kaprqm-zUhdtfO753MARXncxNfjnSACpSegqVUZOditYW0ZdasCzGckNAXaAY55nG_wXq_4Sn5wdpkzOBVfL6yww-k2GZfqCgU1AuVEU-o_5ckNYg2n29v86Jy5w68oxeBuk63iLybD7ZiBm9F_AI8OCm7FGf7Cc6BaulG8FbYI8DQPJDyAHuprKFgthKC_SyIXEbC33d9yXjsIHMQVLnSjg7ct17QLxF4LKof15R_dY5k0fJb1WO3eDDc_RRUHgZln6tXll_620lMkhkzXr6oLAnhmRfOYafeB4WQI4rRuGrImZoFxW4yzbJpTWiNYZCLuKCAA' 
Name ='ESTSAUTHPERSISTENT_1' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='ESTSAUTHPERSISTENT2'*/
	/*web_reg_save_param_regexp(
		"ParamName=ESTSAUTHPERSISTENT",
		"RegExp=ESTSAUTHPERSISTENT=(.*?);",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Cookies",
		//"RequestUrl=*///login*",
		//LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='QVFBQkFBRUFBQUJIaDRrbVNfYUtUNVhyanp4UkF0SHpvNHlMUXZYR0RRNkZvZGpEM0pxT0xBbkwtVUwyUTU3dXNTVTdmeENjVHBON0xuZTBHZ1kzV0NwRjVLaTdLSGJadV9abTZaZ2s1T3RlNExtcEZOTW4xMUR3MDdaSFVBTURZUGJKYWstOVktaC1IQVl5T25TNU5BaEpXdzRIV2JXc2JhVnJoVTdfRWRqbkVjMnRXSElsYXBtMmxEMktrSUlRQzhRN1lzTXRTT1BuU0FGalNSOHQ1Q1IzWUlCaUFjQ1YtS1NaU2ZBWTZRQ2E1T2JxT1RUZktJRnROR0pxNDVRYlBIdWs5SVFBRlUyYTRGS2k0WkhlZXVqUE1vNkg5NG82bXFOSU9zWUFvZ3J1VnM1a3RUVmxpMjVKN1VTaDVtV0NHaVotT0trOWgyeEVSN2xuTm51RkFFV1oyZ2kxWS1Cbm9qUG9wTHdBWElEX1VWZFVuUjFXczFoTERuWEtBSEVFNzY1cEZQUHlDSTFTTy1OVWdxUXNSTzBvM0QwTkM4M3dOOGlEYmRabUNUUUJhNWhIbVdfLVdZbmc3TDFPTlIwVnNRdHFYc3ZaSnhzVHBfR2NlSWJFcmxaRmxtcUlHUU92dFI0b0lpU05iZ2luaENZR3lDLTlsSm1iNFJEVjFaLTBkNnFxa3ZPUi0ydGxkVjV0bUtOSDA0UXlQQTVSUHVfcTVKZURGN1JqZjlaSDFyaVJvV1NkdUgxd0pPZU40WWU4NTNEV3FhR3pERG9nQUE=' 
Name ='ESTSAUTH_2' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='ESTSAUTH2'*/
	/*web_reg_save_param_regexp(
		"ParamName=ESTSAUTH",
		"RegExp=ESTSAUTH=(.*?);",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Cookies",
		//"RequestUrl=*///login*",
		//LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='AQABAAEAAABHh4kmS_aKT5XrjzxRAtHzPZm1MYNTgJkR0ENWh7EsFKQsqOzHD3DZROhcSgKb6xruSof5y-47kpjrRBJ4NE511aOsDTo3Xp0fdZixdwhnP7OXbMVzaa5EHuW5-wRcHZvZtTE4G4cOW6fXkVVdwbfFu6gGvivZ8Vxlf4rYmxop05pRFAWVZF2hrSGTT5xoDBYHwdbesmbys8V5-JPG82DeSNH6mf1YssO2HsgmwYgMFhylASCFOYCq9haUvWmH-o8IbuF6jdyjgsbxfpzdkCFQErpv1Vt8lThFHiV-26csvsH59jlcWEN4F7McR7cxILe5cvAL0eYLeilj0ZHSTfMhgdkt9tWP-3sOVAr2qqgD2D5LURwuUrQp9LYnxBTLy4GtOMZElnWzjgxX1M6Qw6AvAPqllIYcSvCZF6BRCdhUc_g8GcCHGeNrblk3n5NnUmVwjKITemJxTLRzDnj6waWRWF3v5OqZ1HVomSHnY4uZs98zLlBKUFL_3tvJZdxmSNhSYojzprezi8mXtrxGxJ3pHo9pH3NWFikD3FpzRHN0NQNftFVRRL0nf1CN1ug14x4c67Ad8LvbMQIJmO6Y406OQ0vIL3bdwcmx2yAUm4OQEX6VZMa1WrT_RsGpap4LomIvNa3vy0c5_od1iPpqSqKeIAA' 
Name ='flowToken_1_1' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='flowtoken2'*/
	web_reg_save_param_regexp(
		"ParamName=flowToken_1",
		"RegExp=@dhhsvicgovau\\.onmicrosoft\\.com\",\"sFT\":\"(.*?)\",",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/login*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='rQIIAZ1SPW_TUBSNmzQqUaRWTAwMDDQSQrafP-LaERFBbRJSJQ5JHax4c96zY8exX3h-CUkGJkBiY2YsYgEmNvgJnbrSkQmYUMXAhDAVZQKpinSHe4_ux9G5J5cqcR6lk7jE824886aDsR8FE4LRxB9jykESKhxaRHbow5iDOOTJ5dyW8fjEv_v2feXwjVrdfPJFes3sni-BYzxFxEE-cSDF5B8L6vydKfW6f1r4RoScOWfHk_kxw3xmmJO1vBnXHOQQm_o4epH-vjYh5Yex-xcqkLB8dm5bsrdFN4kLMU_6CmS68uRi1ckExGToo7LmDARNszUWiaLAyhLaYVUEBHYHAEUBAtIgFAoRjqBT3u22zINEBO6s5BRJKSqCIguqIomCoKkKZ4UdoW3eH7VGHaovA9BfANDag1LTCIots0-tUU9sG8OFbrbm_dGwmOSyvldd6kZALcML-z4AfbEqNc1aaNV71AprI93oLa16q2iZ--N36esQOCDh5bLAtSEryxpkNaiqrC0AGcrOQHNF9VP6RiIEdWI6jR0iVZDnxTMfDvHMnnI4SnQgOMYu_S3GcSb3NZMH6dLGRnYrfSV1LfUjwxyuJ346vdr7eevRaeXV5suP4CmTOlrnD4LFDPMdYzwOms2qYx_oXnjP1Ie0TRsPlrOb-yTwG2g0lLqNslISnmfzR9nUt2zqw6VnzIW9WJJl6f9-vH2OGXjF3_8C0' 
Name ='ctx_1_1' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='ctx1'*/
	web_reg_save_param_regexp(
		"ParamName=ctx_1",
		"RegExp=\"sCtx\":\"(.*?)\",",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/login*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='Skyvo/QTllkLLEeaSNhmPWNgtOtIqzv+JrkiIdjg3RI=9:1' 
Name ='canary_1_1' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='apicanary1'*/
	web_reg_save_param_regexp(
		"ParamName=canary_1",
		"RegExp=\"apiCanary\":\"(.*?)\",",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/login*",
		LAST);

	web_submit_data("login",
		"Action=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/login",
		"Method=POST",
		"RecContentType=text/html",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t887.inf",
		"Mode=HTTP",
		ITEMDATA,
		"Name=i13", "Value=0", ENDITEM,
		"Name=login", "Value={param_UserID}@dhhsvicgovau.onmicrosoft.com", ENDITEM,
		"Name=loginfmt", "Value={param_UserID}@dhhsvicgovau.onmicrosoft.com", ENDITEM,
		"Name=type", "Value=11", ENDITEM,
		"Name=LoginOptions", "Value=3", ENDITEM,
		"Name=lrt", "Value=", ENDITEM,
		"Name=lrtPartition", "Value=", ENDITEM,
		"Name=hisRegion", "Value=", ENDITEM,
		"Name=hisScaleUnit", "Value=", ENDITEM,
		"Name=passwd", "Value={param_Password}", ENDITEM,
		"Name=ps", "Value=2", ENDITEM,
		"Name=psRNGCDefaultType", "Value=", ENDITEM,
		"Name=psRNGCEntropy", "Value=", ENDITEM,
		"Name=psRNGCSLK", "Value=", ENDITEM,
		"Name=canary", "Value={canary_3}", ENDITEM,
		"Name=ctx", "Value={ctx_3}", ENDITEM,
		"Name=hpgrequestid", "Value={hpgrequestid_3}", ENDITEM,
		"Name=flowToken", "Value={flowToken_3}", ENDITEM,
		"Name=PPSX", "Value=", ENDITEM,
		"Name=NewUser", "Value=1", ENDITEM,
		"Name=FoundMSAs", "Value=", ENDITEM,
		"Name=fspost", "Value=0", ENDITEM,
		"Name=i21", "Value=0", ENDITEM,
		"Name=CookieDisclosure", "Value=0", ENDITEM,
		"Name=IsFidoSupported", "Value=0", ENDITEM,
		"Name=i2", "Value=102", ENDITEM,
		"Name=i17", "Value=", ENDITEM,
		"Name=i18", "Value=", ENDITEM,
		"Name=i19", "Value=36910", ENDITEM,
		LAST);

	//web_add_cookie("ESTSAUTHPERSISTENT={ESTSAUTHPERSISTENT}; DOMAIN=login.microsoftonline.com");

	//web_add_cookie("ESTSAUTH={ESTSAUTH}; DOMAIN=login.microsoftonline.com");

/*Correlation comment: Automatic rules - Do not change!  
Original value='AQABAAEAAADX8GCi6Js6SK82TsD2Pb7r1M2KQtZZ5Pru9nKbDG32nD1w7y4ibWxN_zMogQEarRI5PvoaoXD-yBfWWIekBmvvLl1rvYJXb-4XjfGR0k2Tmim0IhYZ3AtWf4IfuRno9aLmT9LgblVazg_RIfSU77-9H2T5i4vBKrZD0_RuwBYoNyJfNmqnBEfLEAMCKyN0mefxILSdTRakRo84Y410ZvUXZTuvrS03JqaCBlOjcToJvgMQzs-q8t-gtgGa7ICnFELiRh3tKW0uh5V1P-BS64n0EsCGuPAYA9XWKWb3gVD-twAHDcaclWLTzfexGuE3MpMmDqooDDdSw5ysTTshA4lPkyQIucNZCBOm8tl_GHX0BgTmrwiaaUVfuNCGeojp8a45cZzNjte76bm2PQAgKCnzellVjUR1y2mjHg7VZrjuWCAA' 
Name ='ESTSAUTHPERSISTENT_6' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='ESTSAUTHPERSISTENT2'*/
	web_reg_save_param_regexp(
		"ParamName=ESTSAUTHPERSISTENT_6",
		"RegExp=ESTSAUTHPERSISTENT=(.*?);",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Cookies",
		"RequestUrl=*/kmsi*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='QVFBQkFBRUFBQURYOEdDaTZKczZTSzgyVHNEMlBiN3IyeV9qRHFHSk1MMzVtTERFV0RrSGpBenBnbWRFSVExY0xjX0hzYzFrMm5YM25ZT3QxNkFKYnYxbDhZcDJIYWV6MGtnNGhIMlRkVkE0WU16WjN5NG9JWnpnTnZDTTZrVHFaT05FRGVIQ29JN2xFemtsemlBZFdrRHJRMWxqUHVoSEVnN3BFcTJoYXpXOVE0cnV0SVFMbUk5Z1FZcjVJRlVRamhBM0hianhfR1lzdHZvM2U2S3lEUEMzb29HZVJlZ1VwaUlpTml5THZrRW9MQUtXWW5TUnh5YllrSFQ2Q042VE04eGIxSFhvQ1RLVmEzczlwZTR4Q2o5SDd0Y1VMeXFWNWFFTzJXdXhZclFLTVVhSmJGcVM1eXgzSXhnTWgxYzdrR0IxcS1URG45WGszcFJsX05xLWNDYjA0d3oxRE5CT0VMblRwZEhCN1VwMzBXbERCZWExNHJWV0t4TENoRXo2bkwwY0RtNmJtY1UyNlZZUVBoRzU1WWJpRFEzMF9OVUhjMzZ3UERLSF83U2hlOTNUZ2VTWHV2OGUyd3RZbnVJbnRCOXFtSXhyQWk0cnBTMFpSdjZoeXRDa0JkMFRabWo5eDNVVkpCRDJERFJCNGpCUGhqSDhwY0NUVUpGWlVuaERqa2JFdTNIa0J1YmdIZWg4SlZ4Sk5UaldZVUxHZmZlT1NxSl9XQkptRTQtZnExRlJYOE44eWpnZzRJUmRoMTl4MkFodEllMjBJb1lnQUE=' 
Name ='ESTSAUTH_2' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='ESTSAUTH2'*/
	web_reg_save_param_regexp(
		"ParamName=ESTSAUTH_2",
		"RegExp=ESTSAUTH=(.*?);",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Cookies",
		"RequestUrl=*/kmsi*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='2018-04-17T06:33:08.971Z' 
Name ='CorrelationParameter_25' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='wct21'*/
	web_reg_save_param_ex(
		"ParamName=CorrelationParameter_25",
		"LB/IC=xsd&quot;>",
		"RB/IC=&lt",
		"DFEs=Xml",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='2018-04-17T07:33:08.971Z' 
Name ='CorrelationParameter_26' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='wct21'*/
	web_reg_save_param_ex(
		"ParamName=CorrelationParameter_26",
		"LB/IC=xsd&quot;>",
		"RB/IC=&lt",
		"DFEs=Xml",
		"Ordinal=2",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='ff2bcc22-8f29-40e1-9be1-db1764f1e054' 
Name ='CorrelationParameter_27' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='quot1'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_27",
		"RegExp=quot;_(.*?)&quot",
		"DFEs=Xml",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='2018-04-17T06:38:08.971Z' 
Name ='CorrelationParameter_28' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='wct4'*/
	web_reg_save_param_ex(
		"ParamName=CorrelationParameter_28",
		"LB/IC=IssueInstant=&quot;",
		"RB/IC=&quot;",
		"DFEs=Xml",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='UQH2ii67KMDBKM05rOObzYEPTBihKGr4EwAVjk+fXhY=' 
Name ='DigestValue_2' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='DigestValue'*/
	web_reg_save_param_ex(
		"ParamName=DigestValue_2",
		"LB/IC=;DigestValue>",
		"RB/IC=&lt",
		"DFEs=Xml",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='pZDnGCNK4uuU6P26jKrG+P0rFrOtSZwvZ4/BPIir0usGGcLqjCOOZRE3dsP86QD3iqZWYszwIWuaQv5M+R6phxbIN0lDUQu4lIKmaWyYNCRKi/YAxbnWCZTy5DN1Rdsg9MlBMuF2v7wNYqWEWWm/h2DCNC3S4Vj4QDdZJyNf6Wc7nshKMcJGLt+ymcUiFeEjpDszc0MVe/vWIYamw/XMibmOfHD8740Llyf7mzxUkOxEk77mwwH0+i/o76urSWE4uTg15Q4hGsFDD2+URyEwgYVlo5J2QUfPiQNS2/mtVLKrQS4qzQr/8/8nvZclFC866Z8ITppj0uO30cgNDBMrzg==' 
Name ='SignatureValue_2' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='SignatureValue'*/
	web_reg_save_param(
		"SignatureValue_2",
		"LB/IC=SignatureValue>",
		"RB/IC=&lt;/SignatureValue",
		LAST);
	
/*Correlation comment: Automatic rules - Do not change!  
Original value='2018-04-17T06:38:08.940Z' 
Name ='CorrelationParameter_29' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='wct3'*/
	web_reg_save_param_ex(
		"ParamName=CorrelationParameter_29",
		"LB/IC=AuthnInstant=&quot;",
		"RB/IC=&quot;",
		"DFEs=Xml",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		LAST);

	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_7_1",
		"RegExp=lt;X509Data>&lt;X509Certificate>(.*?)&lt",
		"DFEs=Xml",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		LAST);
	web_reg_save_param_ex(
		"ParamName=CorrelationParameter_8_1",
		"LB/IC=persistent&quot;>",
		"RB/IC=&lt;/NameID>",
		"DFEs=Xml",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='c76e778c-4ca5-45d8-a83d-ed2ff2c1603d' 
Name ='AttributeValue' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='ObjectIdentifier1'*/
	web_reg_save_param_ex(
		"ParamName=AttributeValue_1",
		"LB/IC=objectidentifier&quot;>&lt;AttributeValue>",
		"RB/IC=&lt;/AttributeValue>&lt;",
		"DFEs=Xml",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='10037FFEA68187D5' 
Name ='CorrelationParameter_9' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='uid1'*/
	web_reg_save_param_ex(
		"ParamName=CorrelationParameter_9_1",
		"LB/IC=puid&quot;>&lt;AttributeValue>",
		"RB/IC=&lt;/AttributeValue>&lt;",
		"DFEs=Xml",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		LAST);

//surname&quot;>&lt;AttributeValue>2&lt;/AttributeValue>
	
	web_reg_save_param(
		"corr_surname",
		"LB/IC=surname&quot;>&lt;AttributeValue>",
		"RB/IC=&lt;/AttributeValue>",
		LAST);
	
//givenname&quot;>&lt;AttributeValue>Fsvtestuser&lt;/AttributeValue>
	
	web_reg_save_param(
		"corr_givenname",
		"LB/IC=givenname&quot;>&lt;AttributeValue>",
		"RB/IC=&lt;/AttributeValue>",
		LAST);
	
//displayname&quot;>&lt;AttributeValue>Fsvtestuser2&lt;/AttributeValue>
	
	web_reg_save_param(
		"corr_displayname",
		"LB/IC=displayname&quot;>&lt;AttributeValue>",
		"RB/IC=&lt;/AttributeValue>",
		LAST);

	lr_start_transaction("CRM_01_b_SignIn");

	web_submit_data("kmsi",
		"Action=https://login.microsoftonline.com/kmsi",
		"Method=POST",
		"RecContentType=text/html",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/login",
		"Snapshot=t21.inf",
		"Mode=HTTP",
		ITEMDATA,
		"Name=LoginOptions", "Value=0", ENDITEM,
		"Name=ctx", "Value={ctx_1}", ENDITEM,
		"Name=flowToken", "Value={flowToken_1}", ENDITEM,
		"Name=canary", "Value={canary_1}", ENDITEM,
		"Name=i2", "Value=", ENDITEM,
		"Name=i17", "Value=", ENDITEM,
		"Name=i18", "Value=", ENDITEM,
		"Name=i19", "Value=7705", ENDITEM,
		LAST);

	web_submit_data("Index.aspx",
		"Action=https://cloudredirector.crm6.dynamics.com/G/AuthRedirect/Index.aspx?RedirectTo=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2fmain.aspx%3fappid%3dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Method=POST",
		"RecContentType=text/html",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/login",
		"Snapshot=t888.inf",
		"Mode=HTTP",
		ITEMDATA,
		"Name=wa", "Value=wsignin1.0", ENDITEM,
		"Name=wresult", "Value=<t:RequestSecurityTokenResponse xmlns:t=\"http://schemas.xmlsoap.org/ws/2005/02/trust\"><t:Lifetime><wsu:Created xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">{CorrelationParameter_25}</wsu:Created><wsu:Expires xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">{CorrelationParameter_26}</wsu:Expires></t:Lifetime><wsp:AppliesTo xmlns:wsp=\"http://schemas.xmlsoap.org/ws/2004/09/policy\"><wsa:EndpointReference xmlns:wsa=\"http://www.w3.org/2005/08/addressing\"><wsa:Address>https://{param_URL}.crm6.dynamics.com/</wsa:Address></wsa:EndpointReference></wsp:AppliesTo><t:RequestedSecurityToken><Assertion ID=\"_{CorrelationParameter_27}\" IssueInstant=\"{CorrelationParameter_28}\" Version=\"2.0\" xmlns=\"urn:oasis:names:tc:SAML:2.0:assertion\"><Issuer>https://sts.windows.net/c0e0601f-0fac-449c-9c88-a104c4eb9f28/</Issuer><Signature xmlns=\"http://www.w3.org/2000/09/xmldsig#\"><SignedInfo><CanonicalizationMeth"
		"od Algorithm=\"http://www.w3.org/2001/10/xml-exc-c14n#\" /><SignatureMethod Algorithm=\"http://www.w3.org/2001/04/xmldsig-more#rsa-sha256\" /><Reference URI=\"#_{CorrelationParameter_27}\"><Transforms><Transform Algorithm=\"http://www.w3.org/2000/09/xmldsig#enveloped-signature\" /><Transform Algorithm=\"http://www.w3.org/2001/10/xml-exc-c14n#\" /></Transforms><DigestMethod Algorithm=\"http://www.w3.org/2001/04/xmlenc#sha256\" /><DigestValue>{DigestValue_2}</DigestValue></Reference></SignedInfo><SignatureValue>{SignatureValue_2}</SignatureValue><KeyInfo><X509Data><X509Certificate>{CorrelationParameter_7_1}</X509Certificate></X509Data></KeyInfo></Signature><Subject><NameID Format=\"urn:oasis:names:tc:SAML:2.0:nameid-format:persistent\">{CorrelationParameter_8_1}</NameID><SubjectConfirmation Method=\"urn:oasis:names:tc:SAML:2.0:cm:bearer\" /></Subject><Conditions NotBefore=\"{CorrelationParameter_25}\" NotOnOrAfter=\"{CorrelationParameter_26}\"><AudienceRestriction><Audience>https://fsvhublinkprodpilot.crm6.dy"
		"namics.com/</Audience></AudienceRestriction></Conditions><AttributeStatement><Attribute Name=\"http://schemas.microsoft.com/identity/claims/tenantid\"><AttributeValue>c0e0601f-0fac-449c-9c88-a104c4eb9f28</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/identity/claims/objectidentifier\"><AttributeValue>{AttributeValue_1}</AttributeValue></Attribute><Attribute Name=\"http://schemas.xmlsoap.org/ws/2005/05/identity/claims/name\"><AttributeValue>{param_UserID2}@dhhsvicgovau.onmicrosoft.com</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/identity/claims/puid\"><AttributeValue>{CorrelationParameter_9_1}</AttributeValue></Attribute><Attribute Name=\"http://schemas.xmlsoap.org/ws/2005/05/identity/claims/surname\"><AttributeValue>{corr_surname}</AttributeValue></Attribute><Attribute Name=\"http://schemas.xmlsoap.org/ws/2005/05/identity/claims/givenname\"><AttributeValue>{corr_givenname}</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/identity/cla"
		"ims/displayname\"><AttributeValue>{corr_displayname}</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/identity/claims/identityprovider\"><AttributeValue>https://sts.windows.net/c0e0601f-0fac-449c-9c88-a104c4eb9f28/</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/claims/authnmethodsreferences\"><AttributeValue>http://schemas.microsoft.com/ws/2008/06/identity/authenticationmethod/password</AttributeValue></Attribute></AttributeStatement><AuthnStatement AuthnInstant=\"{CorrelationParameter_29}\"><AuthnContext><AuthnContextClassRef>urn:oasis:names:tc:SAML:2.0:ac:classes:Password</AuthnContextClassRef></AuthnContext></AuthnStatement></Assertion></t:RequestedSecurityToken><t:RequestedAttachedReference><SecurityTokenReference d3p1:TokenType=\"http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLV2.0\" xmlns:d3p1=\"http://docs.oasis-open.org/wss/oasis-wss-wssecurity-secext-1.1.xsd\" xmlns=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecuri"
		"ty-secext-1.0.xsd\"><KeyIdentifier ValueType=\"http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLID\">_{CorrelationParameter_27}</KeyIdentifier></SecurityTokenReference></t:RequestedAttachedReference><t:RequestedUnattachedReference><SecurityTokenReference d3p1:TokenType=\"http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLV2.0\" xmlns:d3p1=\"http://docs.oasis-open.org/wss/oasis-wss-wssecurity-secext-1.1.xsd\" xmlns=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd\"><KeyIdentifier ValueType=\"http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLID\">_{CorrelationParameter_27}</KeyIdentifier></SecurityTokenReference></t:RequestedUnattachedReference><t:TokenType>http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLV2.0</t:TokenType><t:RequestType>http://schemas.xmlsoap.org/ws/2005/02/trust/Issue</t:RequestType><t:KeyType>http://schemas.xmlsoap.org/ws/2005/05/identity/NoProofKey</t:KeyType></t:RequestSecurityToke"
		"nResponse>", ENDITEM,
		"Name=wctx", "Value=pr=wsfederation&rm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&ru=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2fmain.aspx%3fappid%3dab18c93f-61e6-e711-a848-000d3ad117e3&ry=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2fmain.aspx%3fappid%3dab18c93f-61e6-e711-a848-000d3ad117e3&crmorgid=9eb199a9-d221-43d7-8d01-7006601d9cc1&nonce=CRMWSFed.nonce.{CorrelationParameter_22}", ENDITEM,
		LAST);

	lr_end_transaction("CRM_01_b_SignIn",LR_AUTO);
	
	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("favicon.ico", 
		"URL=https://cloudredirector.crm6.dynamics.com/favicon.ico", 
		"Resource=1", 
		"RecContentType=image/x-icon", 
		"Referer=", 
		"Snapshot=t889.inf", 
		LAST);

	/*web_add_cookie("ReqClientId=e5c3c14d-4a65-41ef-86af-87590f9ba6b9; DOMAIN={param_URL}.crm6.dynamics.com");

	web_add_cookie("orgId=9eb199a9-d221-43d7-8d01-7006601d9cc1; DOMAIN={param_URL}.crm6.dynamics.com");

	web_add_cookie("ai_user=ffZ43|2018-04-17T05:06:26.101Z; DOMAIN={param_URL}.crm6.dynamics.com");

	web_add_cookie("ai_session=2lCDh|1523946105098.685|1523946105098.685; DOMAIN={param_URL}.crm6.dynamics.com");*/

/*Correlation comment: Automatic rules - Do not change!  
Original value='7608e1f5-75de-4695-b5dd-aee1c8d6973c' 
Name ='CorrelationParameter_30' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/
	
	web_reg_save_param(
		"CorrelationParameter_30",
		"LB/IC=REQ_ID:",
		"RB/IC=\r\nX-Ua-Compatible:",
		LAST);
	
/*Correlation comment: Automatic rules - Do not change!  
Original value='462d2695-18e7-484b-83e9-3af296a53985' 
Name ='CorrelationParameter_31' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='LoginCorrelationId'*/
	/*web_reg_save_param(
		"CorrelationParameter_31",
		"LB==",
		"RB/IC=';\\r\\nvar REMIND_AUTH_EXPIRATION", 
		LAST);*/
	
	web_reg_save_param(
		"tstamp",
		"LB/IC=?tstamp=",
		"RB/IC=&amp",
		LAST);

	web_reg_save_param(
		"updateTimeStamp",
		"LB/IC=updateTimeStamp=",
		"RB/IC=&amp",
		LAST);

	web_reg_save_param(
		"userts",
		"LB/IC=USER_TIMESTAMP = '",
		"RB/IC='",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_112",
		"RegExp=\\{Token:\\ '(.*?)',\\ Timestamp:\\ ",
		"Ordinal=4",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/main.aspx*",
		LAST);
	
//VkuMD\x2fyOEeeoMgANOuDrjlZjSIhpS0SjrFtFvQ26dXiaK3BIDCcu5R6JY1Y\x2fp4Ny
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_1121",
		"RegExp=\\{Token:\\ '(.*?)',\\ Timestamp:\\ ",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/main.aspx*",
		LAST);

	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_1111",
		"RegExp=,\\ Timestamp:\\ \"(.*?)\"}",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/main.aspx*",
		LAST);
		
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_2122",
		"RegExp=\\{Token:\\ '(.*?)',\\ Timestamp:\\ ",
		"Ordinal=2",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/main.aspx*",
		LAST);

	web_reg_save_param(
		"CorrelationParameter_51",
		"LB/IC=REQ_ID:",
		"RB/IC=\r\nX-Ua-Compatible:",
		LAST);

/*Correlation comment - Do not change!  Original value='77u/PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0idXRmLTgiPz48U2VjdXJpdHlDb250ZXh0VG9rZW4gcDE6SWQ9Il84N2JhYTYxZi1kNDQzLTRlNzAtOTVhYS1lOGY4YzVkODcyZTUtNkU5QUMxOTI3REE3M0Y0NTcyNjE4MzdENUYwQURDMTIiIHhtbG5zOnAxPSJodHRwOi8vZG9jcy5vYXNpcy1vcGVuLm9yZy93c3MvMjAwNC8wMS9vYXNpcy0yMDA0MDEtd3NzLXdzc2VjdXJpdHktdXRpbGl0eS0xLjAueHNkIiB4bWxucz0iaHR0cDovL2RvY3Mub2FzaXMtb3Blbi5vcmcvd3Mtc3gvd3Mtc2VjdXJlY29udmVyc2F0aW9uLzIwMDUxMiI+PElkZW50aWZpZXI+dXJuOnV1aWQ6OGYxNDdmZWMtMjVlNy00MWY3LTkyMTMtYWUyMDJmMDk5Yjk0PC9JZGVudGlmaWVyPjxDb29raWUgeG1sbnM9Imh0dHA6Ly9zY2hlbWFzLm1pY3Jvc29mdC5jb20vd3MvMjAwNi8wNS9zZWN1cml0eSI+QUFFQUFFM1IybGpseExiQzhYeHpDR2xuOFB0RFNOcHUyQXgvVElic2JPZjZoSHV4VjNvOTBFdU50UThROGE4Skp2VTNKYnYzbTFET05HYURlZW1BVmd2Yy9CTm8yYVFQZkFvZFliRzk4cndIWVFLcnBXTEF3TzdXOFh4RFFDR21QdThFbnNIdXpkZ1NEUWEzNWlrdE11Um5BeHhBK0hYUHcvRXZZNXRhV1JhOW5aZS81NEg5aG5mU2hTR0VRQUhPNXAxSHdMVVJ2TGJOZTNvVllzODhrMkg5MkN2WXVEMTdqcEV1dUZ2REN1N0w2VFBzb2RieWlaQnBlRStUSUVaSHBKT2w0S1RWOC9sVUYzN1g0SllQRGNHM1ArUmdLWkdkY3hwOEMyN3RpWVVkaFFrOGRTTVVDTEN0dk1qSW56ekVlTHU3VktJMVAwL3dUb21jTDQ4MDZBUzdtbTQ5U0V4aUxUSkF5YkFsZlAwOHVJSnRqOU5MdTR2WHFKekZTdnE1TDRaVUpnQUJBQUJzL1NuUDVuUnAyQzlyMTdueW53OSsxMTRZMFZEcHpYODBpVHBoenJEbTRIYlhoUHU4cUllcnRMUjNGQURveHZiYjV1cTV0OTlyWXZGWVZXUk5wVmYwZVlCRmxjUk9ScFBrYWRZdXdOekl1azlFMndrVmNWY09Od3JDWHo3Rnk3YjdDNmtFWUc1RVFMY0tZTHhkU0dudFNkSXpzekRSc3hDMEdmTGVEa1ExUXY0Mk44a1h6UlpJRkJCOXVsbHRxTDRnR1V0VkZORXU5WHZLYkI5M1AwUnJRc2czOSs5STdzTlQxUGk1R3plL1JwV01pcU0zQVg0QzIwOTJoTWZ5SnRmQVhWbzFPMGMzaXg5NjBSZHNpYXd5RXhmZXN2TGp3aGVNOG9Wck9pWDcyQkRtS1EzTDBGWHpOYXFtbG0rZG5lZXQranQ4a1N4dzF2M05RTmRKQTF4VzBBTUFBQ1EvSjRBWndRSmFRVUdIOUU4VTdBcTNSK0dTS0R0V2dlMXpldEtzZnRZa1J6bmVMYi9hdTNlTVJ4djAzNDlEdGk5by9YcUxNZUlmdEtyOTlMREl6bGFER2pNMlk5bzJUcjB1Q0ZnemRLQVMwVjVmZFMraXZScm9leTZzQW9wOVpTQWxoVGtGOWhmUy80UjFlTFdmTk9CMDZYbVZ4bWNmcU4yU0MxL3A3eG41TFpGVUZYdlZGTXc4bWVmTmZmc0o2MHl0LzZHQUZUYk9nMjJ6ZjNHcVJWem1Hai9Nc1pVT0hWc0Uya3F5QldUTlhyV2dnR3RKYm92cXJ3U093VjJqWldoL0NUdTA3R3loT1h5ZGdPaVowRmFiNXhoNGxUS0krVTBQdjBWaUMyaDFvcEt6U0lrdGY1eHgvK3VZOW9W' Name ='CorrelationParameter_2123' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_2123",
		"RegExp=MSISAuth=(.*?);",
		SEARCH_FILTERS,
		"Scope=Cookies",
		"IgnoreRedirections=No",
		"RequestUrl=*/main.aspx*",
		LAST);

/*Correlation comment - Do not change!  Original value='b3crSHBnVWlyZTVBZnFuT0R0T2xQUS80QzFFbzErMm1aenp6UURobTN3a1NMU1k1NTF6R3pzWk12cllWaDlNLzAzWDhIbldaSVVKUCtnTk1pMUVFZW5XOFUwRTBNQVJGRFNEUjRjdGtySUt4d053cmMwZkF1OFAzK0dMUnFucmF2MzVkV0pFWTg0QWp4c3BuYS91U2lIaFpncWV2QzB5cVNjODhEVzZJVGJpQUJIQ3dkeFlZMGhrTlAwRWNLdGtCTUhmS0tmUk9oQ1ZZVmovRE5LT3hSdEpwSEUyTkMvZkNaMEVoSW84cW5rMkd4SktJblJrSmZIZXJwVlMyNDI1akgyQ3JDQWdMV3VjSGsrcGRNVmVQeXY1QlJTb0cyc1JXRTZNaWx1aVFtd0ViNEZMc1VVWis2U0ZLcEdVa0xUUllxdVpvWEJEZHhMQjhGNjgvU1AwMEx4cGY0ZVpVVDZOSVBLTlVjUlQrMEJVYVRVUHBKOHJNYi9DZzJUTytaeHFZdHlyQTB2L1hUeEo0alVMZlVyQUsrRGhCYkFWL0crRkZ5aEMveWcwS3hGZXhGcy95MVRFeU8yZDJLMlJoaGxqS09VZ3p0RHNoTnlkVDUrY09OaUtjUnk2N05zSXN3V2R4eDRaWStRa1htWGgvZ09LUFFna0gxSjZCV2s1bXRHWjQ1YmNHcStiR3B1dUU2N21hTW9UVGt2c1lmczA5eUpyWnFReTVHVnRaV1hQUXJoT283QWdWVk9ieURiMzYwckhaWEJhTFZYNmdpSStZV1M3TDBHM0tPV29wa1VSUjJINUlKc1YyU0N4MWhuM3ZISDhLVmJIN20yd1pHZXM0YnVUZ1hONndidm1JcUMySTZHTFNxZWE0WGk5UXB4S2x5T0pFZGxFQ1ZzVllMNWx3bDVhYXhvekE5OThNQitBSDVtcHBtdHYzUlhBTTFVR2UwWFYyWGZEbFArT1d1MXZWL0puZnVzdnphTjlic2REV0k5WmkvN1NjS0JROXpRVTNCWnNxc0pvWDRJRStzRkJXNVd1TFBWODVob2FzTGdrcHRSOEdNaXA5MlVwZVQyRG5Ca0dyc2ExOTFKdGlIVExIc0VGVzdNeGVQNlF5cU1qbU5LYWMzMVJoVUdRRWx2VUt5SEFYMVlHcmtUTWVjNUt6TmJqalpGdHIycFp5QjFhSDJ2eEhsYjZNRmwvWEl2d2tSTEVEb1dYNlp2MGFCSElGL3pUMmM5WUFRUDIxeVA1VjhUQ1pJWjhwalA5YVhQVmhkYmloa3RoSWFJdE5mT282eEEvWHN2NkdreldrPTwvQ29va2llPjwvU2VjdXJpdHlDb250ZXh0VG9rZW4+' Name ='CorrelationParameter_2124' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_2124",
		"RegExp=MSISAuth1=(.*?);",
		SEARCH_FILTERS,
		"Scope=Cookies",
		"IgnoreRedirections=No",
		"RequestUrl=*/main.aspx*",
		LAST);

/*Correlation comment - Do not change!  Original value='99cade58-31fe-49e7-9aa8-5b03f74db21c' Name ='CorrelationParameter_2125' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_2125",
		"RegExp==\\ '(.*?)';\\\r\\\nvar\\ REMIND_AUTH_EXPIRATION\\ ",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/main.aspx*",
		LAST);

//themeId=
	web_reg_save_param(
		"themeID",
		"LB/IC=themeId=",
		"RB/IC=&amp",
		LAST);

//?lcid={lcid1}&amp;ver=
	web_reg_save_param(
		"lcid1",
		"LB/IC=?lcid=",
		"RB/IC=&amp;ver=",
		LAST);

//&amp;ver=-1919334392"
	web_reg_save_param(
		"verID1",
		"LB/IC=&amp;ver=",
		"RB/IC=\"",
		LAST);

//"/%7B636645955890000441%7D/WebResources/msdyn_LoadNPSSurvey.
web_reg_save_param(
		"msdyn_Load1",
		"LB/IC=%7B",
		"RB/IC=%7D/WebResources/msdyn_LoadNPSSurvey",
		LAST);

	web_reg_save_param("userguid","LB=USER_GUID = '\\x7b","RB=\\x7d';",LAST);

	lr_start_transaction("CRM_01_c_DashBoard");

	web_submit_data("main.aspx_2",
		"Action=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3",
		"Method=POST",
		"RecContentType=text/html",
		"Referer=https://cloudredirector.crm6.dynamics.com/G/AuthRedirect/Index.aspx?RedirectTo=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2fmain.aspx%3fappid%3dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t890.inf",
		"Mode=HTTP",
		ITEMDATA,
		"Name=wa", "Value=wsignin1.0", ENDITEM,
		"Name=wresult", "Value=<t:RequestSecurityTokenResponse xmlns:t=\"http://schemas.xmlsoap.org/ws/2005/02/trust\"><t:Lifetime><wsu:Created xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">{CorrelationParameter_25}</wsu:Created><wsu:Expires xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">{CorrelationParameter_26}</wsu:Expires></t:Lifetime><wsp:AppliesTo xmlns:wsp=\"http://schemas.xmlsoap.org/ws/2004/09/policy\"><wsa:EndpointReference xmlns:wsa=\"http://www.w3.org/2005/08/addressing\"><wsa:Address>https://{param_URL}.crm6.dynamics.com/</wsa:Address></wsa:EndpointReference></wsp:AppliesTo><t:RequestedSecurityToken><Assertion ID=\"_{CorrelationParameter_27}\" IssueInstant=\"{CorrelationParameter_28}\" Version=\"2.0\" xmlns=\"urn:oasis:names:tc:SAML:2.0:assertion\"><Issuer>https://sts.windows.net/c0e0601f-0fac-449c-9c88-a104c4eb9f28/</Issuer><Signature xmlns=\"http://www.w3.org/2000/09/xmldsig#\"><SignedInfo><CanonicalizationMeth"
		"od Algorithm=\"http://www.w3.org/2001/10/xml-exc-c14n#\" /><SignatureMethod Algorithm=\"http://www.w3.org/2001/04/xmldsig-more#rsa-sha256\" /><Reference URI=\"#_{CorrelationParameter_27}\"><Transforms><Transform Algorithm=\"http://www.w3.org/2000/09/xmldsig#enveloped-signature\" /><Transform Algorithm=\"http://www.w3.org/2001/10/xml-exc-c14n#\" /></Transforms><DigestMethod Algorithm=\"http://www.w3.org/2001/04/xmlenc#sha256\" /><DigestValue>{DigestValue_2}</DigestValue></Reference></SignedInfo><SignatureValue>{SignatureValue_2}</SignatureValue><KeyInfo><X509Data><X509Certificate>{CorrelationParameter_7_1}</X509Certificate></X509Data></KeyInfo></Signature><Subject><NameID Format=\"urn:oasis:names:tc:SAML:2.0:nameid-format:persistent\">{CorrelationParameter_8_1}</NameID><SubjectConfirmation Method=\"urn:oasis:names:tc:SAML:2.0:cm:bearer\" /></Subject><Conditions NotBefore=\"{CorrelationParameter_25}\" NotOnOrAfter=\"{CorrelationParameter_26}\"><AudienceRestriction><Audience>https://fsvhublinkprodpilot.crm6.dy"
		"namics.com/</Audience></AudienceRestriction></Conditions><AttributeStatement><Attribute Name=\"http://schemas.microsoft.com/identity/claims/tenantid\"><AttributeValue>c0e0601f-0fac-449c-9c88-a104c4eb9f28</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/identity/claims/objectidentifier\"><AttributeValue>{AttributeValue_1}</AttributeValue></Attribute><Attribute Name=\"http://schemas.xmlsoap.org/ws/2005/05/identity/claims/name\"><AttributeValue>{param_UserID2}@dhhsvicgovau.onmicrosoft.com</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/identity/claims/puid\"><AttributeValue>{CorrelationParameter_9_1}</AttributeValue></Attribute><Attribute Name=\"http://schemas.xmlsoap.org/ws/2005/05/identity/claims/surname\"><AttributeValue>{corr_surname}</AttributeValue></Attribute><Attribute Name=\"http://schemas.xmlsoap.org/ws/2005/05/identity/claims/givenname\"><AttributeValue>{corr_givenname}</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/identity/cla"
		"ims/displayname\"><AttributeValue>{corr_displayname}</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/identity/claims/identityprovider\"><AttributeValue>https://sts.windows.net/c0e0601f-0fac-449c-9c88-a104c4eb9f28/</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/claims/authnmethodsreferences\"><AttributeValue>http://schemas.microsoft.com/ws/2008/06/identity/authenticationmethod/password</AttributeValue></Attribute></AttributeStatement><AuthnStatement AuthnInstant=\"{CorrelationParameter_29}\"><AuthnContext><AuthnContextClassRef>urn:oasis:names:tc:SAML:2.0:ac:classes:Password</AuthnContextClassRef></AuthnContext></AuthnStatement></Assertion></t:RequestedSecurityToken><t:RequestedAttachedReference><SecurityTokenReference d3p1:TokenType=\"http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLV2.0\" xmlns:d3p1=\"http://docs.oasis-open.org/wss/oasis-wss-wssecurity-secext-1.1.xsd\" xmlns=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecuri"
		"ty-secext-1.0.xsd\"><KeyIdentifier ValueType=\"http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLID\">_{CorrelationParameter_27}</KeyIdentifier></SecurityTokenReference></t:RequestedAttachedReference><t:RequestedUnattachedReference><SecurityTokenReference d3p1:TokenType=\"http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLV2.0\" xmlns:d3p1=\"http://docs.oasis-open.org/wss/oasis-wss-wssecurity-secext-1.1.xsd\" xmlns=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd\"><KeyIdentifier ValueType=\"http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLID\">_{CorrelationParameter_27}</KeyIdentifier></SecurityTokenReference></t:RequestedUnattachedReference><t:TokenType>http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLV2.0</t:TokenType><t:RequestType>http://schemas.xmlsoap.org/ws/2005/02/trust/Issue</t:RequestType><t:KeyType>http://schemas.xmlsoap.org/ws/2005/05/identity/NoProofKey</t:KeyType></t:RequestSecurityToke"
		"nResponse>", ENDITEM,
		"Name=wctx", "Value=pr=wsfederation&rm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&ru=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2fmain.aspx%3fappid%3dab18c93f-61e6-e711-a848-000d3ad117e3&ry=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2fmain.aspx%3fappid%3dab18c93f-61e6-e711-a848-000d3ad117e3&crmorgid=9eb199a9-d221-43d7-8d01-7006601d9cc1&nonce=CRMWSFed.nonce.{CorrelationParameter_22}", ENDITEM,
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_concurrent_start(NULL);

	web_url("fonts.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_common/styles/fonts.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t891.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("appmessagebar.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_controls/AppMessageBar/appmessagebar.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t892.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("EncodeDecode.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/EncodeDecode.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t893.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("configurabletheme.aspx",
		"URL=https://{param_URL}.crm6.dynamics.com/_common/styles/configurabletheme.aspx?themeId={themeID}&updateTimeStamp={updateTimeStamp}&ver=-239230285",
		"Resource=1",
		"RecContentType=text/css",
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t894.inf",
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("jquery-2.1.1.min.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/jquery-2.1.1.min.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t895.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("crminternalutility.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/crminternalutility.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t896.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("entitypropertiesutil.js.aspx",
		"URL=https://{param_URL}.crm6.dynamics.com/_common/entityproperties/entitypropertiesutil.js.aspx?tstamp={tstamp}&ver=-239230285",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t897.inf",
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("EntitiesCustomizedHelp.js.aspx",
		"URL=https://{param_URL}.crm6.dynamics.com/_common/EntitiesCustomizedHelp/EntitiesCustomizedHelp.js.aspx?tstamp={tstamp}&ver=-239230285",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t898.inf",
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("main.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_common/styles/main.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t899.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("widgetmanager.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/widgetmanager.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t900.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("main.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/main.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t901.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("postmessagecommunication.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/postmessagecommunication.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t902.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("theme.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_common/styles/theme.css.aspx?{lcid1}&theme=Outlook15White&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t903.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("autotooltip.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/styles/autotooltip.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t904.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("msdyn_LoadNPSSurvey.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/%7B{msdyn_Load1}%7D/WebResources/msdyn_LoadNPSSurvey.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/jscript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t905.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("maincontrols.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/maincontrols.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t906.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("maxsessionmonitor.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/maxsessionmonitor.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t907.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("salescrmsoapproxyservice.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/salescrmsoapproxyservice.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t908.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("salescommonframework.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/salescommonframework.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t909.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("date.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/datetime/date.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t910.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("lookupmrulist.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/lookupmru/lookupmrulist.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t911.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("inlineeditcommon.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/inlineeditcommon.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t912.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("navbar.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/navbar/navbar.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t913.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("inlineeditmodel.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/inlineedit/inlineeditmodel.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t914.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("controls.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_forms/controls/controls.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t915.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("jquery_ui_1.8.21.min.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/jquery_ui_1.8.21.min.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t916.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("globalmru.aspx",
		"URL=https://{param_URL}.crm6.dynamics.com/_root/globalmru.aspx?mdts={tstamp}&ver=-239230285",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t917.inf",
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("appmessagebar.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/appmessagebar/appmessagebar.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t918.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("appswitchershell.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/appswitchershell/appswitchershell.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t919.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("datetime.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_forms/datetime.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t920.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("flyoutdialog.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/flyoutdialog/flyoutdialog.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t921.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("global.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_common/styles/global.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t922.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("mscrm.caching.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/mscrm.caching.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t923.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("globalquickcreatebehavior.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/globalquickcreate/globalquickcreatebehavior.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t924.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("ribbon.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/ribbon/ribbon.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t925.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("performance.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/performance.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t926.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("formcontrols.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/form/formcontrols.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t927.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("ribbonactions.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/ribbonactions.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t928.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("RibbonLayout.js.aspx",
		"URL=https://{param_URL}.crm6.dynamics.com/_controls/ribbon/RibbonLayout.js.aspx?cb=true&hierarchy=00000000-0000-0000-0000-000000000000&id=Mscrm.BasicHomeTab&ie=1&ise=1&{lcid1}&mver={tstamp}&oc=0&page=%2fMAIN.ASPX&rver=990654873&ver=-239230285&wrdepver=00000000000000000000000000000000",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t929.inf",
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("commandbaractions.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/commandbaractions.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t930.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("navbar.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_controls/navbar/navbar.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t931.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("presence.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/presence.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t932.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("Cancel_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/Cancel_16.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t933.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("flyoutdialog.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_controls/refreshform/flyoutdialog.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t934.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("cui.css", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/css/1033/cui.css?ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t935.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("global.ashx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_common/global.ashx?ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t936.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("jquery.tmpl.min.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/jquery.tmpl.min.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t937.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("pageloader.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/pageloader.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t938.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_revert_auto_header("Accept-Language");

	web_revert_auto_header("Cache-Control");

	web_add_auto_header("Accept", 
		"*/*");

	web_add_auto_header("User-Agent", 
		"Mozilla/5.0 (Windows NT 6.3; Win64; x64; Trident/7.0; rv:11.0) like Gecko");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate, peerdist");

	web_add_header("UA-CPU", 
		"AMD64");

	web_add_auto_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_auto_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");
/*
	web_url("Windows7-EnterpriseMode-LIST-PROD.xml", 
		"URL=http://n516.service.csv.au/EM/Windows7-EnterpriseMode-LIST-PROD.xml", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t939.inf", 
		"Mode=HTTP", 
		LAST);
*/
	web_add_auto_header("Accept", 
		"text/css, */*");

	web_add_auto_header("Accept-Language", 
		"en-AU");

	web_add_auto_header("User-Agent", 
		"Mozilla/5.0 (Windows NT 6.3; WOW64; Trident/7.0; rv:11.0) like Gecko");

	web_url("sessionmanagement.css", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/styles/sessionmanagement.css?ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t940.inf", 
		LAST);

	web_add_auto_header("Accept", 
		"application/javascript, */*;q=0.8");

	web_url("Microsoft.Crm.Client.Core.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/Microsoft.Crm.Client.Core.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t941.inf", 
		LAST);

	web_url("MicrosoftAjax.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/MicrosoftAjax.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t942.inf", 
		LAST);

	web_concurrent_start(NULL);

	/*web_url("ScriptResx.ashx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_common/ScriptResx.ashx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t943.inf", 
		LAST);*/

	web_url("CrmServiceProxy.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/CrmServiceProxy.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t944.inf", 
		LAST);

	web_url("CrmServiceProxyFramework.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/CrmServiceProxyFramework.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t945.inf", 
		LAST);

	web_url("organizations(9EB199A9-D221-43D7-8D01-7006601D9CC1)", 
		"URL=https://{param_URL}.crm6.dynamics.com/api/data/v9.0/organizations(9EB199A9-D221-43D7-8D01-7006601D9CC1)?$select=%20postmessagewhitelistdomains", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t946.inf", 
		LAST);

	web_url("NavBarDivider.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/NavBar/NavBarDivider.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t947.inf", 
		LAST);

	web_url("Theme_NavBarLogo.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/oobwebresource/Theme_NavBarLogo.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t948.inf", 
		LAST);

	web_url("JsProvider.ashx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_common/JsProvider.ashx?ids=346338581-1481678315&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t949.inf", 
		LAST);

	web_url("emptyuserimage.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/navbar/emptyuserimage.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t950.inf", 
		LAST);

	web_add_header("Origin", 
		"https://{param_URL}.crm6.dynamics.com");

	web_url("seguisb.woff", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/seguisb.woff", 
		"Resource=1", 
		"RecContentType=font/x-woff", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t951.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_add_auto_header("Accept", 
		"*/*");

	web_add_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("OfficeWaffleInfo.ashx", 
		"URL=https://{param_URL}.crm6.dynamics.com/Handlers/OfficeWaffleInfo.ashx", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t952.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Origin", 
		"https://{param_URL}.crm6.dynamics.com");

	web_concurrent_start(NULL);

	web_url("D365Shell.woff", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/D365Shell.woff", 
		"Resource=1", 
		"RecContentType=font/x-woff", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t953.inf", 
		LAST);

	web_url("control_imgs.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/imagestrips/control_imgs.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t954.inf", 
		LAST);

	web_url("NavBarAppSwitcher.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/NavBar/NavBarAppSwitcher.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t955.inf", 
		LAST);

	web_url("commandbarmenudown.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/commandbarmenudown.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t956.inf", 
		LAST);

	web_url("more_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/more_16.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t957.inf", 
		LAST);

	web_url("navbar_header.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/imagestrips/navbar_header.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t958.inf", 
		LAST);

	web_url("ribbonhomepage.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/imagestrips/ribbonhomepage.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t959.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_add_auto_header("Accept", 
		"text/html, application/xhtml+xml, */*");

/*Correlation comment: Automatic rules - Do not change!  
Original value='123e71cb-6298-45cb-b81a-99bc58afadd1' 
Name ='CorrelationParameter_32' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/

	web_reg_save_param(
		"CorrelationParameter_32",
		"LB/IC=REQ_ID:",
		"RB/IC=\r\nX-Ua-Compatible:",
		LAST);
	

	web_reg_save_param("userguid","LB=USER_GUID = '\\x7b","RB=\\x7d';",LAST);

	web_url("home_dashboards.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t960.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("form.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_forms/controls/form.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t961.inf", 
		LAST);

	web_url("select.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_common/styles/select.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t962.inf", 
		LAST);

	web_url("menu.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_nav/menu.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t963.inf", 
		LAST);

	web_url("CompositeControl.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_controls/CompositeControl/CompositeControl.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t964.inf", 
		LAST);

	web_url("appgrid.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_grid/appgrid.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t965.inf", 
		LAST);

	web_url("tabs.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_nav/tabs.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t966.inf", 
		LAST);

	web_url("read.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_forms/styles/read.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t967.inf", 
		LAST);

	web_url("activitycontainer.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/activitycontainer/activitycontainer.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t968.inf", 
		LAST);

	web_url("visualization.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/visualization/visualization.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t969.inf", 
		LAST);

	web_url("dashboardselector.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/dashboardselector.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t970.inf", 
		LAST);

	web_url("lookupbehavior.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_forms/lookupbehavior.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t971.inf", 
		LAST);

	web_url("GridControl.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_grid/GridControl.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t972.inf", 
		LAST);

	web_url("form.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_forms/form.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t973.inf", 
		LAST);

	web_url("menuselector.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/menuselector/menuselector.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t974.inf", 
		LAST);

	web_url("select.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_forms/select.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t975.inf", 
		LAST);

	web_url("stage.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/stage.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t976.inf", 
		LAST);

	web_url("glowingimage.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/glowingimage.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t977.inf", 
		LAST);

	web_url("HintText.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/HintText/HintText.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t978.inf", 
		LAST);

	web_url("visualizationactions.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/visualization/visualizationactions.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t979.inf", 
		LAST);

	web_url("es6-shim.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/es6-shim.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t980.inf", 
		LAST);

	web_url("visualizationpane.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/pane/visualizationpane.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t981.inf", 
		LAST);

	web_url("DataSetControl.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_grid/DataSetControl.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t982.inf", 
		LAST);

	web_url("checkbox.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_forms/checkbox.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t983.inf", 
		LAST);

	web_url("ActivityCommandBar.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/ActivityContainer/ActivityCommandBar.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t984.inf", 
		LAST);

	web_url("RibbonLayout.js.aspx_2",
		"URL=https://{param_URL}.crm6.dynamics.com/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=dhhs_screening&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cdhhs_screening%7cNoRelationship%7c&ie=1&ise=1&{lcid1}&mver={tstamp}&oc=0&page=%2fWORKPLACE%2fHOME_DASHBOARDS.ASPX&relName=&relType=NoRelationship&rver=990654873&ver=-239230285&wrdepver=00000000000000000000000000000000",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t985.inf",
		LAST);

	web_url("details.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/details.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t986.inf", 
		LAST);

	web_url("RibbonLayout.js.aspx_3",
		"URL=https://{param_URL}.crm6.dynamics.com/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=incident&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cincident%7cNoRelationship%7c&ie=1&ise=1&{lcid1}&mver={tstamp}&oc=0&page=%2fWORKPLACE%2fHOME_DASHBOARDS.ASPX&relName=&relType=NoRelationship&rver=990654873&ver=-239230285&wrdepver=00000000000000000000000000000000",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t987.inf",
		LAST);

	web_url("action.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_grid/action.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t988.inf", 
		LAST);

	web_url("lookup.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/lookup/lookup.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t989.inf", 
		LAST);

	web_url("RibbonLayout.js.aspx_4",
		"URL=https://{param_URL}.crm6.dynamics.com/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=activitypointer&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cactivitypointer%7cNoRelationship%7c&ie=1&ise=1&{lcid1}&mver={tstamp}&oc=0&page=%2fWORKPLACE%2fHOME_DASHBOARDS.ASPX&relName=&relType=NoRelationship&rver=990654873&ver=-239230285&wrdepver=00000000000000000000000000000000",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t990.inf",
		LAST);

	web_url("addrelated.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_forms/addrelated.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t991.inf", 
		LAST);

	web_url("RibbonLayout.js.aspx_5",
		"URL=https://{param_URL}.crm6.dynamics.com/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=queueitem&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cqueueitem%7cNoRelationship%7c&ie=1&ise=1&{lcid1}&mver={tstamp}&oc=0&page=%2fWORKPLACE%2fHOME_DASHBOARDS.ASPX&relName=&relType=NoRelationship&rver=990654873&ver=-239230285&wrdepver=00000000000000000000000000000000",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t992.inf",
		LAST);

	web_url("popupmenu.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/popupmenu/popupmenu.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t993.inf", 
		LAST);

	web_url("time.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/datetime/time.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t994.inf", 
		LAST);

	web_url("addphone_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addphone_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t995.inf", 
		LAST);

	web_url("addemail_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addemail_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t996.inf", 
		LAST);

	web_url("addtask_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addtask_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t997.inf", 
		LAST);

	web_url("addappointment_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addappointment_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t998.inf", 
		LAST);

	web_url("addcampaignresponse_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addcampaignresponse_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t999.inf", 
		LAST);

	web_url("addactivity_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addactivity_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1000.inf", 
		LAST);

	web_url("addfax_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addfax_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1001.inf", 
		LAST);

	web_url("addletter_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addletter_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1002.inf", 
		LAST);

	web_url("addserviceactivity_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addserviceactivity_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1003.inf", 
		LAST);

	web_url("Calendar_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/%7B{msdyn_Load1}%7D/WebResources/msdyn_/fps/Icons/Entity/Calendar_16.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1004.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_add_auto_header("Accept", 
		"*/*");

	web_add_auto_header("ReferrerReqId",
		"{CorrelationParameter_32}");

	web_url("RenderGridView.aspx",
		"URL=https://{param_URL}.crm6.dynamics.com/_grid/RenderGridView.aspx?autoExpand=0&deleteAction=&em=1&enableContextualActions=&eventManagerId=crmEventManager&expandable=1&gridType=SubGrid&id=Component17fb94f&isGridHidden=false&isSubGridLite=1&jumpbar=0&{lcid1}&loadOnDemand=0&maxRows=12&mdts={tstamp}&oType=&recsPerPage=8&relationshipType=0&relName=&ribbonContext=SubGridStandard&roleOrd=-1&tabIndex=0&teamTmplId=&ver=-239230285&viewid=%7bB65269AA-5ACB-E711-A844-000D3AD11148%7d&viewts=3144135&viewtype=1039",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t1005.inf",
		"Mode=HTTP",
		LAST);

	web_url("RenderGridView.aspx_2",
		"URL=https://{param_URL}.crm6.dynamics.com/_grid/RenderGridView.aspx?autoExpand=0&deleteAction=&em=1&enableContextualActions=&eventManagerId=crmEventManager&expandable=1&gridType=SubGrid&id=Componentb177617&isGridHidden=false&isSubGridLite=1&jumpbar=0&{lcid1}&loadOnDemand=0&maxRows=12&mdts={tstamp}&oType=&recsPerPage=8&relationshipType=0&relName=&ribbonContext=SubGridStandard&roleOrd=-1&tabIndex=0&teamTmplId=&ver=-239230285&viewid=%7bE87C42AF-07D0-E711-A826-000D3AE0A7F8%7d&viewts=3144254&viewtype=1039",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t1006.inf",
		"Mode=HTTP",
		LAST);

	web_url("RenderGridView.aspx_3",
		"URL=https://{param_URL}.crm6.dynamics.com/_grid/RenderGridView.aspx?autoExpand=0&deleteAction=&em=1&enableContextualActions=&eventManagerId=crmEventManager&expandable=1&gridType=SubGrid&id=Component376145d&isGridHidden=false&isSubGridLite=1&jumpbar=0&{lcid1}&loadOnDemand=0&maxRows=24&mdts={tstamp}&oType=&recsPerPage=20&relationshipType=0&relName=&ribbonContext=SubGridStandard&roleOrd=-1&tabIndex=0&teamTmplId=&ver=-239230285&viewid=%7bAD7A2839-61CB-E711-A844-000D3AD11148%7d&viewts=3143913&viewtype=1039",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t1007.inf",
		"Mode=HTTP",
		LAST);

	web_url("RenderGridView.aspx_4",
		"URL=https://{param_URL}.crm6.dynamics.com/_grid/RenderGridView.aspx?autoExpand=0&deleteAction=&em=1&enableContextualActions=&eventManagerId=crmEventManager&expandable=1&gridType=SubGrid&id=Componenta3058e5&isGridHidden=false&isSubGridLite=1&jumpbar=0&{lcid1}&loadOnDemand=0&maxRows=12&mdts={tstamp}&oType=&recsPerPage=8&relationshipType=0&relName=&ribbonContext=SubGridStandard&roleOrd=-1&tabIndex=0&teamTmplId=&ver=-239230285&viewid=%7b4962E489-10D0-E711-A826-000D3AE0A7F8%7d&viewts=3142834&viewtype=1039",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t1008.inf",
		"Mode=HTTP",
		LAST);

	web_url("grid_ctrl_imgs.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/imagestrips/grid_ctrl_imgs.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1009.inf", 
		LAST);

	web_revert_auto_header("X-P2P-PeerDist");

	web_revert_auto_header("X-P2P-PeerDistEx");

	web_add_header("SOAPAction",
		"http://schemas.microsoft.com/crm/2009/WebServices/GetDashboardWrpcTokens");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate");

	web_add_auto_header("Cache-Control", 
		"no-cache");

	web_convert_from_formatted("FormattedData=<?xml version=\"1.0\" encoding=\"utf-8\"?><HP_EXTENSION name=\"Xml\"><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetDashboardWrpcTokens xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"></GetDashboardWrpcTokens></soap:Body></soap:Envelope></HP_EXTENSION>", 
		"TargetParam=DFE_BODY_1", 
		LAST);

	web_custom_request("DashboardWebService.asmx",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/DashboardWebService.asmx",
		"Method=POST",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t1010.inf",
		"Mode=HTTP",
		"EncType=text/xml; charset=utf-8",
		"Body={DFE_BODY_1}",
		LAST);

	web_add_header("SOAPAction",
		"http://schemas.microsoft.com/crm/2009/WebServices/GetDefaultDashboardId");

	web_convert_from_formatted("FormattedData=<?xml version=\"1.0\" encoding=\"utf-8\"?><HP_EXTENSION name=\"Xml\"><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetDefaultDashboardId xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><siteMapPath>NewArea_6370afe4&#124;group_myWork&#124;NewSubArea_cb6d1642</siteMapPath><appid>ab18c93f-61e6-e711-a848-000d3ad117e3</appid></GetDefaultDashboardId></soap:Body></soap:Envelope></HP_EXTENSION>", 
		"TargetParam=DFE_BODY_2", 
		LAST);

	web_custom_request("DashboardWebService.asmx_2",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/DashboardWebService.asmx",
		"Method=POST",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t1011.inf",
		"Mode=HTTP",
		"EncType=text/xml; charset=utf-8",
		"Body={DFE_BODY_2}",
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("Dashboard_library.js",
		"URL=https://{param_URL}.crm6.dynamics.com/%7B{msdyn_Load1}%7D/WebResources/Dashboard_library.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=-239230285",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t1012.inf",
		LAST);

	web_add_header("SOAPAction",
		"http://schemas.microsoft.com/crm/2009/WebServices/GetUserDashboardListHash");

	web_convert_from_formatted("FormattedData=<?xml version=\"1.0\" encoding=\"utf-8\"?><HP_EXTENSION name=\"Xml\"><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetUserDashboardListHash xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"></GetUserDashboardListHash></soap:Body></soap:Envelope></HP_EXTENSION>", 
		"TargetParam=DFE_BODY_3", 
		LAST);

	web_custom_request("DashboardWebService.asmx_3",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/DashboardWebService.asmx",
		"Method=POST",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t1013.inf",
		"Mode=HTTP",
		"EncType=text/xml; charset=utf-8",
		"Body={DFE_BODY_3}",
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("Ribbon_main_system_library.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/%7B{msdyn_Load1}%7D/WebResources/Ribbon_main_system_library.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1014.inf", 
		LAST);

	web_revert_auto_header("ReferrerReqId");

	web_add_auto_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_convert_from_formatted("FormattedData=<HP_EXTENSION name=\"JsonXml,Xml\"><object><object name=\"request\"><array name=\"MetricsCollections\"><object><pair name=\"RequestId\" type=\"str\">d22513f8-328b-4666-a9fc-ac30b6ca9689</pair><array name=\"Metrics\"><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946071739</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"num\">1523946067099</pair><pair name=\"componentId\" type=\"str\">main.aspx</pair><pair name=\"componentInfo\" type=\"str\">precise</pair><pair name=\"marker\" type=\"str\">loadStart</pair><pair name=\"navigation\" type=\"num\">0</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946071740</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"num\">1523946068908</pair><pair name=\"componentId\" type=\"str\">main.aspx</pair><pair name=\"componentInfo\" type=\"str\"></pair><pair name=\"marker\" type=\"str\">responseStart</pair><pair name=\"navigation\" type=\"num\">0</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946071740</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"num\">1523946068918</pair><pair name=\"componentId\" type=\"str\">main.aspx</pair><pair name=\"componentInfo\" type=\"str\"></pair><pair name=\"marker\" type=\"str\">responseEnd</pair><pair name=\"navigation\" type=\"num\">0</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946071740</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"num\">1523946071740</pair><pair name=\"componentId\" type=\"str\">main.aspx</pair><pair name=\"componentInfo\" type=\"str\"></pair><pair name=\"marker\" type=\"str\">loaded</pair><pair name=\"navigation\" type=\"num\">0</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">pagenavigations</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946071908</pair><object name=\"p\"><pair name=\"navigatedAt\" type=\"str\">\\/Date(1523946071907)\\/</pair><pair name=\"navigationCounter\" type=\"num\">1</pair><pair name=\"navigationUri\" type=\"str\">/workplace/home_dashboards.aspx?sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642</pair><pair name=\"tabSessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946071908</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"str\">\\/Date(1523946071908)\\/</pair><pair name=\"componentId\" type=\"str\">pagenavigations</pair><pair name=\"componentInfo\" type=\"str\">/workplace/home_dashboards.aspx?sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642</pair><pair name=\"marker\" type=\"str\">navigationStart</pair><pair name=\"navigation\" type=\"num\">1</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946071934</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"str\">\\/Date(1523946071934)\\/</pair><pair name=\"componentId\" type=\"str\">pagenavigations</pair><pair name=\"componentInfo\" type=\"str\">/workplace/home_dashboards.aspx?sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642</pair><pair name=\"marker\" type=\"str\">navigationEnd</pair><pair name=\"navigation\" type=\"num\">1</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommand.Execute</pair><pair name=\"v\" type=\"num\">2259</pair><pair name=\"t\" type=\"num\">1523946073800</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">MessageBar</pair><pair name=\"ReqId\" type=\"str\">44eb6a18-749e-45bb-b320-89d42ad52c0e</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommand.Execute</pair><pair name=\"v\" type=\"num\">186</pair><pair name=\"t\" type=\"num\">1523946096716</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">RecentlyViewedWebService</pair><pair name=\"ReqId\" type=\"str\">679de8a0-89fa-4e37-a6c3-52a895eecec1</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommand.Execute</pair><pair name=\"v\" type=\"num\">1109</pair><pair name=\"t\" type=\"num\">1523946134611</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">LookupMruWebService</pair><pair name=\"ReqId\" type=\"str\">12a8b43c-bc9e-43e6-a460-9981231e6362</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommand.Execute</pair><pair name=\"v\" type=\"num\">1123</pair><pair name=\"t\" type=\"num\">1523946134599</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">RecentlyViewedWebService</pair><pair name=\"ReqId\" type=\"str\">1aa90dcc-f030-48d5-aaba-733d7458173c</pair></object></object></array><pair name=\"IsExistingActivity\" type=\"bool\">true</pair></object><object><pair name=\"RequestId\" type=\"str\">c2d0993d-de6a-48c7-9c20-7db152668f0f</pair><array name=\"Metrics\"><object><pair name=\"n\" type=\"str\">RemoteCommand.Execute</pair><pair name=\"v\" type=\"num\">321</pair><pair name=\"t\" type=\"num\">1523946096541</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">DashboardWebService</pair><pair name=\"ReqId\" type=\"str\">32b8f6cf-f1dc-46c3-9fef-d04bb3543dbe</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommand.Execute</pair><pair name=\"v\" type=\"num\">334</pair><pair name=\"t\" type=\"num\">1523946096539</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">DashboardWebService</pair><pair name=\"ReqId\" type=\"str\">b56f42fa-c9f7-4fad-9f5f-1e2d6010a0dc</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommand.Execute</pair><pair name=\"v\" type=\"num\">345</pair><pair name=\"t\" type=\"num\">1523946096533</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">DashboardWebService</pair><pair name=\"ReqId\" type=\"str\">95992587-6955-4120-8d97-6b0aa4ee6765</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommandXml.Execute</pair><pair name=\"v\" type=\"num\">353</pair><pair name=\"t\" type=\"num\">1523946110613</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">AppGridWebService</pair><pair name=\"ReqId\" type=\"str\">83b97765-6706-4fd1-a41b-2af10fa5d718</pair></object></object><object><pair name=\"n\" type=\"str\">SubGrid</pair><pair name=\"v\" type=\"num\">429</pair><pair name=\"t\" type=\"num\">1523946110602</pair><object name=\"p\"><pair name=\"id\" type=\"str\">Component17fb94f</pair><pair name=\"IsAsync\" type=\"bool\">true</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946111031</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"num\">1523946111031</pair><pair name=\"componentId\" type=\"str\">Component17fb94f</pair><pair name=\"componentInfo\" type=\"str\"></pair><pair name=\"marker\" type=\"str\">loaded</pair><pair name=\"navigation\" type=\"num\">1</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommandXml.Execute</pair><pair name=\"v\" type=\"num\">202</pair><pair name=\"t\" type=\"num\">1523946110833</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">AppGridWebService</pair><pair name=\"ReqId\" type=\"str\">e1ca3ea1-a5f2-4f7e-a8d3-84d35705ff12</pair></object></object><object><pair name=\"n\" type=\"str\">SubGrid</pair><pair name=\"v\" type=\"num\">335</pair><pair name=\"t\" type=\"num\">1523946110826</pair><object name=\"p\"><pair name=\"id\" type=\"str\">Component376145d</pair><pair name=\"IsAsync\" type=\"bool\">true</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946111162</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"num\">1523946111161</pair><pair name=\"componentId\" type=\"str\">Component376145d</pair><pair name=\"componentInfo\" type=\"str\"></pair><pair name=\"marker\" type=\"str\">loaded</pair><pair name=\"navigation\" type=\"num\">1</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommandXml.Execute</pair><pair name=\"v\" type=\"num\">318</pair><pair name=\"t\" type=\"num\">1523946110905</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">AppGridWebService</pair><pair name=\"ReqId\" type=\"str\">6e93d49c-091d-4e78-9948-129faa7e3042</pair></object></object><object><pair name=\"n\" type=\"str\">SubGrid</pair><pair name=\"v\" type=\"num\">359</pair><pair name=\"t\" type=\"num\">1523946110899</pair><object name=\"p\"><pair name=\"id\" type=\"str\">Componentb177617</pair><pair name=\"IsAsync\" type=\"bool\">true</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946111259</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"num\">1523946111259</pair><pair name=\"componentId\" type=\"str\">Componentb177617</pair><pair name=\"componentInfo\" type=\"str\"></pair><pair name=\"marker\" type=\"str\">loaded</pair><pair name=\"navigation\" type=\"num\">1</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommandXml.Execute</pair><pair name=\"v\" type=\"num\">389</pair><pair name=\"t\" type=\"num\">1523946110871</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">AppGridWebService</pair><pair name=\"ReqId\" type=\"str\">b521f550-327f-44b6-b6a6-c4e3b64b4f83</pair></object></object><object><pair name=\"n\" type=\"str\">SubGrid</pair><pair name=\"v\" type=\"num\">465</pair><pair name=\"t\" type=\"num\">1523946110864</pair><object name=\"p\"><pair name=\"id\" type=\"str\">Componenta3058e5</pair><pair name=\"IsAsync\" type=\"bool\">true</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946111330</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"num\">1523946111330</pair><pair name=\"componentId\" type=\"str\">Componenta3058e5</pair><pair name=\"componentInfo\" type=\"str\"></pair><pair name=\"marker\" type=\"str\">loaded</pair><pair name=\"navigation\" type=\"num\">1</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object></array><pair name=\"IsExistingActivity\" type=\"bool\">true</pair></object></array></object></object></HP_EXTENSION>", 
		"TargetParam=DFE_BODY_4", 
		LAST);

	web_custom_request("Report", 
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/MetricsReportingService.asmx/Report", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1015.inf", 
		"Mode=HTTP", 
		"EncType=application/json; charset=utf-8", 
		"Body={DFE_BODY_4}", 
		LAST);

	lr_save_string(lr_eval_string("{CorrelationParameter_112}"), "path1");
	
	crmwrpctoken();
	
	/*lr_output_message ("path is %s", lr_eval_string("{path1}"));
	lr_save_string("\\", "separators");
	//lr_think_time(2);
   	// Get the first token
   	token = (char *)strtok(lr_eval_string("{path1}"), lr_eval_string("{separators}"));
   
    lr_output_message ("token is %s", token);
    
    strcat(crmwrpctoken1,token);
    	  
    lr_output_message ("fullpath is %s",crmwrpctoken1);
    
    if (!token) 
	    {
	        
	    	lr_save_string("token", "crmwrpctoken1");
	        lr_output_message ("No tokens found in string!");
	        lr_output_message ("Full path of file is %s", crmwrpctoken1);
	        //return( -1 );
	    }
	
    else{
			    // While valid tokens are returned
			    do      
				    {    	    
						lr_output_message ("Full path of file is %s", crmwrpctoken1);			
				        lr_output_message ("%s", token );
				      // Get the next token
				        token = (char *)strtok(NULL, separators);
				        lr_output_message ("%s", token );
				        if(token != NULL)
				        {
										lr_save_string(token, "token1");
										lr_output_message ("%s", lr_eval_string("{token1}") );
								        lr_save_string("x2b", "word");
								        pch = (char *)strstr(lr_eval_string("{token1}"), lr_eval_string("{word}"));
				
				        }
										if(pch)
											{
											if(token)
										        {
											        lr_output_message ("%s", token );
											        	        
											        strcat(crmwrpctoken1, "+");
											   	 	lr_output_message ("Full path of file is %s", crmwrpctoken1);
											   	 	lr_save_string(token, "crmwrpctoken3");
											   	 	token = lr_eval_string("{crmwrpctoken3}") + 3;
											   	 	strcat(crmwrpctoken1,token);	   	 	
										        }
							
											}
								        else
								        	{
											if(token)
										        {
											        lr_output_message ("%s", token );
											        	        
											        strcat(crmwrpctoken1, "/");
											   	 	lr_output_message ("Full path of file is %s", crmwrpctoken1);
											   	 	lr_save_string(token, "crmwrpctoken3");
											   	 	token = lr_eval_string("{crmwrpctoken3}") + 3;
											   	 	strcat(crmwrpctoken1,token);	   	 	
										        }
										        
								        	}
										       
								    	    
				}while (token != NULL );
			    
    	}

    lr_output_message ("Full path of file is %s", crmwrpctoken1);
   	 	
	lr_save_string(crmwrpctoken1,"path1");*/

	web_add_header("ReferrerReqId",
		"{CorrelationParameter_30}");

	web_add_header("CRMWRPCToken", 
		lr_eval_string("{path1}"));

	web_add_header("CRMWRPCTokenTimeStamp", 
		"{CorrelationParameter_1111}");

	web_add_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/GetAllMessages");

	web_convert_from_formatted("FormattedData="
			"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
			"<HP_EXTENSION name=\"Xml\">"
				"<soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">"
					"<soap:Body>"
						"<GetAllMessages xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\">"
							"<clientType>0</clientType>"
							"<contextType>Global</contextType>"
						"</GetAllMessages>"
					"</soap:Body>"
				"</soap:Envelope>"
			"</HP_EXTENSION>", 
		"TargetParam=DFE_BODY_5", 
		LAST);

	web_custom_request("MessageBar.asmx", 
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/MessageBar.asmx", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1016.inf", 
		"Mode=HTTP", 
		"EncType=text/xml; charset=utf-8", 
		"Body={DFE_BODY_5}", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_concurrent_start(NULL);

	web_url("process.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/%7B{msdyn_Load1}%7D/WebResources/mag_/js/process.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/jscript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1017.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("dhhs_case", 
		"URL=https://{param_URL}.crm6.dynamics.com/%7B{msdyn_Load1}%7D/WebResources/dhhs_case?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Resource=1", 
		"RecContentType=text/jscript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1018.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("Main_system_library.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/%7B{msdyn_Load1}%7D/WebResources/Main_system_library.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1019.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_revert_auto_header("LoginRequestCorrelationId");

	web_add_auto_header("ReferrerReqId",
		"{CorrelationParameter_32}");

	web_convert_from_formatted("FormattedData="
			"<HP_EXTENSION name=\"Xml\">"
				"<grid>"
					"<sortColumns>statuscode&#58;0</sortColumns>"
					"<pageNum>1</pageNum>"
					"<recsPerPage>8</recsPerPage>"
					"<dataProvider>Microsoft.Crm.Application.Platform.Grid.GridDataProviderQueryBuilder</dataProvider>"
					"<uiProvider>Microsoft.Crm.Application.Controls.GridUIProvider</uiProvider>"
					"<cols></cols>"
					"<max>1</max>"
					"<refreshAsync>True</refreshAsync>"
					"<pagingCookie></pagingCookie>"
					"<enableMultiSort>true</enableMultiSort>"
					"<enablePagingWhenOnePage>true</enablePagingWhenOnePage>"
					"<refreshCalledFromRefreshButton>1</refreshCalledFromRefreshButton>"
					"<returntotalrecordcount>true</returntotalrecordcount>"
					"<getParameters>getFetchXmlForFilters</getParameters>"
					"<parameters>"
						"<viewid>&#123;B65269AA-5ACB-E711-A844-000D3AD11148&#125;</viewid>"
						"<RenderAsync>0</RenderAsync>"
						"<LoadOnDemand>0</LoadOnDemand>"
						"<deleteAction></deleteAction>"
						"<autorefresh>1</autorefresh>"
						"<isGridHidden>false</isGridHidden>"
						"<LayoutStyle>LiteGridList</LayoutStyle>"
						"<maxselectableitems>1</maxselectableitems>"
						"<isGridFilteringEnabled>1</isGridFilteringEnabled>"
						"<viewtype>1039</viewtype>"
						"<viewts>3144135</viewts>"
						"<RecordsPerPage>8</RecordsPerPage>"
						"<viewTitle>My cases</viewTitle>"
						"<layoutXml>&#60;grid name&#61;&#34;resultset&#34; jump&#61;&#34;title&#34; select&#61;&#34;1&#34; preview&#61;&#34;1&#34; icon&#61;&#34;1&#34; object&#61;&#34;112&#34;&#62;&#60;row id&#61;&#34;incidentid&#34; name&#61;&#34;result&#34;&#62;&#60;cell name&#61;&#34;title&#34; width&#61;&#34;300&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;customerid&#34; width&#61;&#34;100&#34; &#47;&#62;&#60;cell name&#61;&#34;modifiedon&#34; width&#61;&#34;125&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;statuscode&#34; width&#61;&#34;150&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;&#47;row&#62;&#60;&#47;grid&#62;</layoutXml>"
						"<otc>112</otc>"
						"<otn>incident</otn>"
						"<entitydisplayname>Case</entitydisplayname>"
						"<titleformat>&#123;0&#125; &#123;1&#125;</titleformat>"
						"<entitypluraldisplayname>Cases</entitypluraldisplayname>"
						"<expandable>1</expandable>"
						"<showjumpbar>0</showjumpbar>"
						"<maxrowsbeforescroll>12</maxrowsbeforescroll>"
						"<tabindex>0</tabindex>"
						"<refreshasynchronous>1</refreshasynchronous>"
						"<subgridAutoExpand>0</subgridAutoExpand>"
						"<relName></relName>"
						"<roleOrd>-1</roleOrd>"
						"<relationshipType>0</relationshipType>"
						"<ribbonContext>SubGridStandard</ribbonContext>"
						"<GridType>SubGrid</GridType>"
						"<enableContextualActions>True</enableContextualActions>"
						"<teamTemplateId></teamTemplateId>"
						"<isWorkflowSupported>true</isWorkflowSupported>"
						"<enableFilters></enableFilters>"
						"<isTurboForm>0</isTurboForm>"
					"</parameters>"
					"<columns>"
						"<column width=\"300\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Case&#32;title\" fieldname=\"title\" entityname=\"incident\" renderertype=\"Crm.PrimaryField\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">title</column>"
						"<column width=\"100\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Client\" fieldname=\"customerid\" entityname=\"incident\" type=\"Customer\" sourcetype=\"0\">customerid</column>"
						"<column width=\"125\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Modified&#32;on\" fieldname=\"modifiedon\" entityname=\"incident\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"DateTime.datetime\" sourcetype=\"0\">modifiedon</column>"
						"<column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Status\" fieldname=\"statuscode\" entityname=\"incident\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Status\" sourcetype=\"0\">statuscode</column>"
					"</columns>"
				"</grid>"
			"</HP_EXTENSION>", 
		"TargetParam=DFE_BODY_6", 
		LAST);

	web_custom_request("AppGridWebService.ashx", 
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/AppGridWebService.ashx?operation=Refresh", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1020.inf", 
		"Mode=HTTP", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={DFE_BODY_6}", 
		LAST);

	web_convert_from_formatted("FormattedData="
			"<HP_EXTENSION name=\"Xml\">"
				"<grid>"
					"<sortColumns>createdon&#58;0</sortColumns>"
					"<pageNum>1</pageNum>"
					"<recsPerPage>20</recsPerPage>"
					"<dataProvider>Microsoft.Crm.Application.Platform.Grid.GridDataProviderQueryBuilder</dataProvider>"
					"<uiProvider>Microsoft.Crm.Application.Controls.GridUIProvider</uiProvider>"
					"<cols></cols>"
					"<max>1</max>"
					"<refreshAsync>True</refreshAsync>"
					"<pagingCookie></pagingCookie>"
					"<enableMultiSort>true</enableMultiSort>"
					"<enablePagingWhenOnePage>true</enablePagingWhenOnePage>"
					"<refreshCalledFromRefreshButton>1</refreshCalledFromRefreshButton>"
					"<returntotalrecordcount>true</returntotalrecordcount>"
					"<getParameters>getFetchXmlForFilters</getParameters>"
					"<parameters>"
						"<viewid>&#123;AD7A2839-61CB-E711-A844-000D3AD11148&#125;</viewid>"
						"<RenderAsync>0</RenderAsync>"
						"<LoadOnDemand>0</LoadOnDemand>"
						"<deleteAction></deleteAction>"
						"<autorefresh>1</autorefresh>"
						"<isGridHidden>false</isGridHidden>"
						"<LayoutStyle>LiteGridList</LayoutStyle>"
						"<maxselectableitems>1</maxselectableitems>"
						"<isGridFilteringEnabled>1</isGridFilteringEnabled>"
						"<viewtype>1039</viewtype>"
						"<viewts>3143913</viewts>"
						"<RecordsPerPage>20</RecordsPerPage>"
						"<viewTitle>Screening list</viewTitle>"
						"<layoutXml>&#60;grid name&#61;&#34;resultset&#34; icon&#61;&#34;1&#34; preview&#61;&#34;1&#34; select&#61;&#34;1&#34; jump&#61;&#34;dhhs_name&#34; object&#61;&#34;10247&#34;&#62;&#60;row id&#61;&#34;dhhs_screeningid&#34; name&#61;&#34;result&#34;&#62;&#60;cell name&#61;&#34;dhhs_name&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; imageproviderfunctionname&#61;&#34;&#34; width&#61;&#34;200&#34; &#47;&#62;&#60;cell name&#61;&#34;createdon&#34; width&#61;&#34;125&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_childreninfamily&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; imageproviderfunctionname&#61;&#34;&#34; width&#61;&#34;125&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_contactmethod&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; imageproviderfunctionname&#61;&#34;&#34; width&#61;&#34;125&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_contacttype&#34; width&#61;&#34;100&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_dateandtimeofincident&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; imageproviderfunctionname&#61;&#34;&#34; width&#61;&#34;150&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_referrergivennames&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; imageproviderfunctionname&#61;&#34;&#34; width&#61;&#34;150&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_referrerlastname&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; imageproviderfunctionname&#61;&#34;&#34; width&#61;&#34;125&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_organisation&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; imageproviderfunctionname&#61;&#34;&#34; width&#61;&#34;150&#34; &#47;&#62;&#60;&#47;row&#62;&#60;&#47;grid&#62;</layoutXml>"
						"<otc>10247</otc>"
						"<otn>dhhs_screening</otn>"
						"<entitydisplayname>Screening</entitydisplayname>"
						"<titleformat>&#123;0&#125; &#123;1&#125;</titleformat>"
						"<entitypluraldisplayname>Screenings</entitypluraldisplayname>"
						"<expandable>1</expandable>"
						"<showjumpbar>0</showjumpbar>"
						"<maxrowsbeforescroll>24</maxrowsbeforescroll>"
						"<tabindex>0</tabindex>"
						"<refreshasynchronous>1</refreshasynchronous>"
						"<subgridAutoExpand>0</subgridAutoExpand>"
						"<relName></relName>"
						"<roleOrd>-1</roleOrd>"
						"<relationshipType>0</relationshipType>"
						"<ribbonContext>SubGridStandard</ribbonContext>"
						"<GridType>SubGrid</GridType>"
						"<enableContextualActions>True</enableContextualActions>"
						"<teamTemplateId></teamTemplateId>"
						"<isWorkflowSupported>true</isWorkflowSupported>"
						"<enableFilters></enableFilters>"
						"<isTurboForm>0</isTurboForm>"
					"</parameters>"
					"<columns>"
						"<column width=\"200\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Reference&#32;number\" fieldname=\"dhhs_name\" entityname=\"dhhs_screening\" renderertype=\"Crm.PrimaryField\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">dhhs_name</column>"
						"<column width=\"125\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Created&#32;On\" fieldname=\"createdon\" entityname=\"dhhs_screening\" type=\"DateTime.datetime\" sourcetype=\"0\">createdon</column>"
						"<column width=\"125\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Children&#32;in&#32;family\" fieldname=\"dhhs_childreninfamily\" entityname=\"dhhs_screening\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Picklist\" sourcetype=\"0\">dhhs_childreninfamily</column>"
						"<column width=\"125\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Contact&#32;method\" fieldname=\"dhhs_contactmethod\" entityname=\"dhhs_screening\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Picklist\" sourcetype=\"0\">dhhs_contactmethod</column>"
						"<column width=\"100\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Contact&#32;type\" fieldname=\"dhhs_contacttype\" entityname=\"dhhs_screening\" type=\"Picklist\" sourcetype=\"0\">dhhs_contacttype</column>"
						"<column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Date&#32;and&#32;time&#32;of&#32;incident\" fieldname=\"dhhs_dateandtimeofincident\" entityname=\"dhhs_screening\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"DateTime.datetime\" sourcetype=\"0\">dhhs_dateandtimeofincident</column>"
						"<column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Referrer&#32;given&#32;names\" fieldname=\"dhhs_referrergivennames\" entityname=\"dhhs_screening\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">dhhs_referrergivennames</column>"
						"<column width=\"125\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Referrer&#32;last&#32;name\" fieldname=\"dhhs_referrerlastname\" entityname=\"dhhs_screening\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">dhhs_referrerlastname</column>"
						"<column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Referrer&#32;organisation\" fieldname=\"dhhs_organisation\" entityname=\"dhhs_screening\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Lookup\" sourcetype=\"0\">dhhs_organisation</column>"
					"</columns>"
				"</grid>"
			"</HP_EXTENSION>", 
		"TargetParam=DFE_BODY_7", 
		LAST);

	web_custom_request("AppGridWebService.ashx_2", 
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/AppGridWebService.ashx?operation=Refresh", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1021.inf", 
		"Mode=HTTP", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={DFE_BODY_7}", 
		LAST);

	web_convert_from_formatted("FormattedData="
			"<HP_EXTENSION name=\"Xml\">"
				"<grid>"
					"<sortColumns>createdon&#58;1&#59;scheduledend&#58;0</sortColumns>"
					"<pageNum>1</pageNum>"
					"<recsPerPage>8</recsPerPage>"
					"<dataProvider>Microsoft.Crm.Application.Platform.Grid.GridDataProviderQueryBuilder</dataProvider>"
					"<uiProvider>Microsoft.Crm.Application.Controls.GridUIProvider</uiProvider>"
					"<cols></cols>"
					"<max>1</max>"
					"<refreshAsync>True</refreshAsync>"
					"<pagingCookie></pagingCookie>"
					"<enableMultiSort>true</enableMultiSort>"
					"<enablePagingWhenOnePage>true</enablePagingWhenOnePage>"
					"<refreshCalledFromRefreshButton>1</refreshCalledFromRefreshButton>"
					"<returntotalrecordcount>true</returntotalrecordcount>"
					"<getParameters>getFetchXmlForFilters</getParameters>"
					"<parameters>"
						"<viewid>&#123;4962E489-10D0-E711-A826-000D3AE0A7F8&#125;</viewid>"
						"<RenderAsync>0</RenderAsync>"
						"<LoadOnDemand>0</LoadOnDemand>"
						"<deleteAction></deleteAction>"
						"<autorefresh>1</autorefresh>"
						"<isGridHidden>false</isGridHidden>"
						"<LayoutStyle>LiteGridList</LayoutStyle>"
						"<maxselectableitems>1</maxselectableitems>"
						"<isGridFilteringEnabled>1</isGridFilteringEnabled>"
						"<viewtype>1039</viewtype>"
						"<viewts>3142834</viewts>"
						"<RecordsPerPage>8</RecordsPerPage>"
						"<viewTitle>My open activities</viewTitle>"
						"<layoutXml>&#60;grid name&#61;&#34;resultset&#34; jump&#61;&#34;subject&#34; select&#61;&#34;1&#34; icon&#61;&#34;1&#34; preview&#61;&#34;1&#34; object&#61;&#34;4200&#34;&#62;&#60;row name&#61;&#34;result&#34; id&#61;&#34;activityid&#34; multiobjectidfield&#61;&#34;activitytypecode&#34;&#62;&#60;cell name&#61;&#34;createdon&#34; width&#61;&#34;100&#34; &#47;&#62;&#60;cell name&#61;&#34;activitytypecode&#34; width&#61;&#34;100&#34; &#47;&#62;&#60;cell name&#61;&#34;subject&#34; width&#61;&#34;125&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;regardingobjectid&#34; width&#61;&#34;100&#34; &#47;&#62;&#60;cell name&#61;&#34;scheduledend&#34; width&#61;&#34;140&#34; &#47;&#62;&#60;cell name&#61;&#34;instancetypecode&#34; width&#61;&#34;100&#34; ishidden&#61;&#34;1&#34; &#47;&#62;&#60;cell name&#61;&#34;community&#34; width&#61;&#34;100&#34; ishidden&#61;&#34;1&#34; &#47;&#62;&#60;&#47;row&#62;&#60;&#47;grid&#62;</layoutXml>"
						"<otc>4200</otc>"
						"<otn>activitypointer</otn>"
						"<entitydisplayname>Activity</entitydisplayname>"
						"<titleformat>&#123;0&#125; &#123;1&#125;</titleformat>"
						"<entitypluraldisplayname>Activities</entitypluraldisplayname>"
						"<expandable>1</expandable>"
						"<showjumpbar>0</showjumpbar>"
						"<maxrowsbeforescroll>12</maxrowsbeforescroll>"
						"<tabindex>0</tabindex>"
						"<refreshasynchronous>1</refreshasynchronous>"
						"<subgridAutoExpand>0</subgridAutoExpand>"
						"<relName></relName>"
						"<roleOrd>-1</roleOrd>"
						"<relationshipType>0</relationshipType>"
						"<ribbonContext>SubGridStandard</ribbonContext>"
						"<GridType>SubGrid</GridType>"
						"<enableContextualActions>True</enableContextualActions>"
						"<teamTemplateId></teamTemplateId>"
						"<isWorkflowSupported>true</isWorkflowSupported>"
						"<enableFilters></enableFilters>"
						"<isTurboForm>0</isTurboForm>"
					"</parameters>"
					"<columns>"
						"<column width=\"100\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Date&#32;Created\" fieldname=\"createdon\" entityname=\"activitypointer\" type=\"DateTime.datetime\" sourcetype=\"0\">createdon</column>"
						"<column width=\"100\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Activity&#32;Type\" fieldname=\"activitytypecode\" entityname=\"activitypointer\" type=\"Picklist\" sourcetype=\"0\">activitytypecode</column>"
						"<column width=\"125\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Subject\" fieldname=\"subject\" entityname=\"activitypointer\" renderertype=\"Crm.PrimaryField\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">subject</column>"
						"<column width=\"100\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Regarding\" fieldname=\"regardingobjectid\" entityname=\"activitypointer\" type=\"Lookup.regarding\" sourcetype=\"0\">regardingobjectid</column>"
						"<column width=\"140\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Due&#32;Date\" fieldname=\"scheduledend\" entityname=\"activitypointer\" type=\"DateTime.datetime\" sourcetype=\"0\">scheduledend</column>"
						"<column width=\"0\" isHidden=\"true\" isMetadataBound=\"true\" isSortable=\"false\" label=\"Recurring&#32;Instance&#32;Type\" fieldname=\"instancetypecode\" entityname=\"activitypointer\" type=\"Picklist\" sourcetype=\"0\">instancetypecode</column>"
						"<column width=\"0\" isHidden=\"true\" isMetadataBound=\"true\" isSortable=\"false\" label=\"Social&#32;Channel\" fieldname=\"community\" entityname=\"activitypointer\" type=\"Picklist\" sourcetype=\"0\">community</column>"
					"</columns>"
				"</grid>"
			"</HP_EXTENSION>", 
		"TargetParam=DFE_BODY_8", 
		LAST);

	web_custom_request("AppGridWebService.ashx_3", 
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/AppGridWebService.ashx?operation=Refresh", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1022.inf", 
		"Mode=HTTP", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={DFE_BODY_8}", 
		LAST);

	web_convert_from_formatted("FormattedData="
			"<HP_EXTENSION name=\"Xml\">"
				"<grid>"
					"<sortColumns>enteredon&#58;1&#59;queueitemid&#58;1</sortColumns>"
					"<pageNum>1</pageNum>"
					"<recsPerPage>8</recsPerPage>"
					"<dataProvider>Microsoft.Crm.Application.Platform.Grid.GridDataProviderQueryBuilder</dataProvider>"
					"<uiProvider>Microsoft.Crm.Application.Controls.GridUIProvider</uiProvider>"
					"<cols></cols>"
					"<max>1</max>"
					"<refreshAsync>True</refreshAsync>"
					"<pagingCookie></pagingCookie>"
					"<enableMultiSort>true</enableMultiSort>"
					"<enablePagingWhenOnePage>true</enablePagingWhenOnePage>"
					"<refreshCalledFromRefreshButton>1</refreshCalledFromRefreshButton>"
					"<returntotalrecordcount>true</returntotalrecordcount>"
					"<getParameters>getFetchXmlForFilters</getParameters>"
					"<parameters>"
						"<viewid>&#123;E87C42AF-07D0-E711-A826-000D3AE0A7F8&#125;</viewid>"
						"<RenderAsync>0</RenderAsync>"
						"<LoadOnDemand>0</LoadOnDemand>"
						"<deleteAction></deleteAction>"
						"<autorefresh>1</autorefresh>"
						"<isGridHidden>false</isGridHidden>"
						"<LayoutStyle>LiteGridList</LayoutStyle>"
						"<maxselectableitems>1</maxselectableitems>"
						"<isGridFilteringEnabled>1</isGridFilteringEnabled>"
						"<viewtype>1039</viewtype>"
						"<viewts>3144254</viewts>"
						"<RecordsPerPage>8</RecordsPerPage>"
						"<viewTitle>My team&#8217;s queue</viewTitle>"
						"<layoutXml>&#60;grid name&#61;&#34;resultset&#34; jump&#61;&#34;title&#34; select&#61;&#34;1&#34; preview&#61;&#34;1&#34; icon&#61;&#34;1&#34; object&#61;&#34;2029&#34;&#62;&#60;row name&#61;&#34;result&#34; id&#61;&#34;objectid&#34; multiobjectidfield&#61;&#34;objecttypecode&#34;&#62;&#60;cell name&#61;&#34;queueitemid&#34; ishidden&#61;&#34;1&#34; width&#61;&#34;150&#34; &#47;&#62;&#60;cell name&#61;&#34;a_6bb8740e28cae711a82d000d3ae0e155.title&#34; width&#61;&#34;150&#34; disableSorting&#61;&#34;1&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; relatedentityname&#61;&#34;incident&#34; relatedentityattr&#61;&#34;incidentid&#34; primaryentityattr&#61;&#34;objectid&#34; relationshipid&#61;&#34;&#123;2ddced70-5349-4b98-940f-790cee328038&#125;&#34; relationshipname&#61;&#34;Incident_QueueItem&#34; &#47;&#62;&#60;cell name&#61;&#34;a_6bb8740e28cae711a82d000d3ae0e155.customerid&#34; width&#61;&#34;150&#34; disableSorting&#61;&#34;1&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; relatedentityname&#61;&#34;incident&#34; relatedentityattr&#61;&#34;incidentid&#34; primaryentityattr&#61;&#34;objectid&#34; relationshipid&#61;&#34;&#123;2ddced70-5349-4b98-940f-790cee328038&#125;&#34; relationshipname&#61;&#34;Incident_QueueItem&#34; &#47;&#62;&#60;cell name&#61;&#34;enteredon&#34; width&#61;&#34;150&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;queueid&#34; width&#61;&#34;150&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;&#47;row&#62;&#60;&#47;grid&#62;</layoutXml>"
						"<otc>2029</otc>"
						"<otn>queueitem</otn>"
						"<entitydisplayname>Queue Item</entitydisplayname>"
						"<titleformat>&#123;0&#125; &#123;1&#125;</titleformat>"
						"<entitypluraldisplayname>Queue Items</entitypluraldisplayname>"
						"<expandable>1</expandable>"
						"<showjumpbar>0</showjumpbar>"
						"<maxrowsbeforescroll>12</maxrowsbeforescroll>"
						"<tabindex>0</tabindex>"
						"<refreshasynchronous>1</refreshasynchronous>"
						"<subgridAutoExpand>0</subgridAutoExpand>"
						"<relName></relName>"
						"<roleOrd>-1</roleOrd>"
						"<relationshipType>0</relationshipType>"
						"<ribbonContext>SubGridStandard</ribbonContext>"
						"<GridType>SubGrid</GridType>"
						"<enableContextualActions>True</enableContextualActions>"
						"<teamTemplateId></teamTemplateId>"
						"<isWorkflowSupported>true</isWorkflowSupported>"
						"<enableFilters></enableFilters>"
						"<isTurboForm>0</isTurboForm>"
					"</parameters>"
					"<columns>"
						"<column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Case&#32;title&#32;&#40;Object&#41;\" fieldname=\"title\" entityname=\"incident\" imageproviderwebresource=\"&#36;webresource&#58;\" relationshipname=\"Incident_QueueItem\" type=\"String.text\" sourcetype=\"0\">a_6bb8740e28cae711a82d000d3ae0e155.title</column>"
						"<column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Client&#32;&#40;Object&#41;\" fieldname=\"customerid\" entityname=\"incident\" imageproviderwebresource=\"&#36;webresource&#58;\" relationshipname=\"Incident_QueueItem\" type=\"Customer\" sourcetype=\"0\">a_6bb8740e28cae711a82d000d3ae0e155.customerid</column>"
						"<column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Entered&#32;queue\" fieldname=\"enteredon\" entityname=\"queueitem\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"DateTime.datetime\" sourcetype=\"0\">enteredon</column>"
						"<column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Queue\" fieldname=\"queueid\" entityname=\"queueitem\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Lookup\" sourcetype=\"0\">queueid</column>"
						"<column width=\"0\" isHidden=\"true\" isMetadataBound=\"true\" isSortable=\"false\" label=\"Queue&#32;Item\" fieldname=\"queueitemid\" entityname=\"queueitem\" type=\"PrimaryKey\" sourcetype=\"0\">queueitemid</column>"
					"</columns>"
				"</grid>"
			"</HP_EXTENSION>", 
		"TargetParam=DFE_BODY_9", 
		LAST);

	web_custom_request("AppGridWebService.ashx_4", 
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/AppGridWebService.ashx?operation=Refresh", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1023.inf", 
		"Mode=HTTP", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={DFE_BODY_9}", 
		LAST);

	lr_end_transaction("CRM_01_c_DashBoard",LR_AUTO);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_concurrent_start(NULL);

	web_url("default.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/EmptyStates/default.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1024.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("shellbootstrapperg2css_2712f627.css", 
		"URL=https://r1.res.office365.com/o365/versionless/shellbootstrapperg2css_2712f627.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1025.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("shellbootstrapperg2_3d2cf9ac.js", 
		"URL=https://r1.res.office365.com/o365/versionless/shellbootstrapperg2_3d2cf9ac.js", 
		"Resource=1", 
		"RecContentType=application/x-javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1026.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("shellg2coremincss_d80e5125.css", 
		"URL=https://r1.res.office365.com/o365/versionless/shellg2coremincss_d80e5125.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1027.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("shellcoreming2am_13f489f6.js", 
		"URL=https://r1.res.office365.com/o365/versionless/shellcoreming2am_13f489f6.js", 
		"Resource=1", 
		"RecContentType=application/x-javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1028.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("shellg2strings_1cfbc784.js", 
		"URL=https://r1.res.office365.com/o365/versionless/shellg2strings_1cfbc784.js", 
		"Resource=1", 
		"RecContentType=application/x-javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1029.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("shellg2coreminthemecss_fa4e44fb.css", 
		"URL=https://r1.res.office365.com/o365/versionless/shellg2coreminthemecss_fa4e44fb.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1030.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("o365shellarialogger_3cefa9b2.js", 
		"URL=https://r1.res.office365.com/o365/versionless/o365shellarialogger_3cefa9b2.js", 
		"Resource=1", 
		"RecContentType=application/x-javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1031.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("fwlink",
		"URL=https://go.microsoft.com/fwlink/?linkid=851737",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t1032.inf",
		LAST);

	web_add_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("DynamicsNPSConfig.json", 
		"URL=https://crmprodnpssurvey.azureedge.net/survey/DynamicsNPSConfig.json", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1033.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("favicon.ico_2", 
		"URL=https://{param_URL}.crm6.dynamics.com/favicon.ico", 
		"Resource=1", 
		"RecContentType=image/x-icon", 
		"Referer=", 
		"Snapshot=t1034.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("NPSSurvey.js", 
		"URL=https://crmprodnpssurvey.azureedge.net/survey/NPSSurvey.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1035.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("applicationinsights.js", 
		"URL=https://crmprodnpssurvey.azureedge.net/survey/applicationinsights.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1036.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("NPSTelemetry.js", 
		"URL=https://crmprodnpssurvey.azureedge.net/survey/NPSTelemetry.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1037.inf", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_add_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("WhoAmI", 
		"URL=https://{param_URL}.crm6.dynamics.com/api/data/V9.0/WhoAmI", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1038.inf", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_add_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("appmodules(ab18c93f-61e6-e711-a848-000d3ad117e3)", 
		"URL=https://{param_URL}.crm6.dynamics.com/api/data/V9.0/appmodules(ab18c93f-61e6-e711-a848-000d3ad117e3)", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1039.inf", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_add_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	//\"","azureactivedirectoryobjectid":"{azureactivedirectoryobjectid}","systemuserid":
	//web_reg_save_param("azureactivedirectoryobjectid","LB=\"azureactivedirectoryobjectid\":\"","RB=\",\"systemuserid",LAST);

	web_url("systemusers()", 
		"URL=https://{param_URL}.crm6.dynamics.com/api/data/V9.0/systemusers()?$select=azureactivedirectoryobjectid&$filter=systemuserid%20eq%20{userguid}", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1040.inf", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_add_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("RetrieveTenantInfo", 
		"URL=https://{param_URL}.crm6.dynamics.com/api/data/V9.0/RetrieveTenantInfo", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1041.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_add_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("manifest", 
		"URL=https://home.dynamics.com/api/manifest?v=fb4569f0-90f6-4092-927d-18bd8015a933", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1042.inf", 
		LAST);

	web_add_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_reg_save_param("MASTER","LB/IC=MASTER\",\"version\":\"","RB=\"}","Ord=All",LAST);

	web_url("config", 
		"URL=https://home.dynamics.com/api/config", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1043.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_concurrent_start(NULL);

	web_url("NPSSurvey.css", 
		"URL=https://crmprodnpssurvey.azureedge.net/survey/NPSSurvey.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1044.inf", 
		LAST);

	/*web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("sdk.css", 
		"URL=https://d365prod-sdk.azureedge.net/assets/MASTER-{MASTER_1}/client/dist/sdk.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1045.inf", 
		LAST);*/

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("ai.0.js", 
		"URL=https://az416426.vo.msecnd.net/scripts/a/ai.0.js", 
		"Resource=1", 
		"RecContentType=application/x-javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1046.inf", 
		LAST);

	/*web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("sdk.js", 
		"URL=https://d365prod-sdk.azureedge.net/assets/MASTER-{MASTER_1}/client/dist/sdk.js", 
		"Resource=1", 
		"RecContentType=application/x-javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1047.inf", 
		LAST);

	web_add_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("glyphs-sprite.svg", 
		"URL=https://d365prod-sdk.azureedge.net/assets/MASTER-{MASTER_1}/resources/images/glyphs-sprite.svg", 
		"Resource=1", 
		"RecContentType=image/svg+xml", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1048.inf", 
		LAST);*/

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("Legacy_Crm_Icon.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/%7B{msdyn_Load1}%7D/WebResources/msdyn_/Images/Legacy_Crm_Icon.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1049.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("msdyn_Dynamics_icons_Sales", 
		"URL=https://{param_URL}.crm6.dynamics.com/%7B{msdyn_Load1}%7D/WebResources/msdyn_Dynamics_icons_Sales", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1050.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("msdyn_Dynamics_icons_Customer_service", 
		"URL=https://{param_URL}.crm6.dynamics.com/%7B{msdyn_Load1}%7D/WebResources/msdyn_Dynamics_icons_Customer_service", 
		"Resource=1", 
		"RecContentType=image/svg+xml", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1051.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("CustomerServiceHubIcon.svg", 
		"URL=https://{param_URL}.crm6.dynamics.com/%7B{msdyn_Load1}%7D/WebResources/CustomerServiceHub/_imgs/AppIcon/CustomerServiceHubIcon.svg", 
		"Resource=1", 
		"RecContentType=image/svg+xml", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1052.inf", 
		LAST);

	/*web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("filmstrip.png", 
		"URL=https://d365prod-sdk.azureedge.net/assets/MASTER-{MASTER_1}/resources/images/taskpane/loading/filmstrip.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1053.inf", 
		LAST);*/

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("ProjectServiceAppModule_Icon.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/%7B{msdyn_Load1}%7D/WebResources/msdyn_/Images/ProjectServiceAppModule_Icon.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1054.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("FieldServiceAppModule_Icon.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/%7B{msdyn_Load1}%7D/WebResources/msdyn_/Images/FieldServiceAppModule_Icon.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1055.inf", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("AppModule_Default_Icon.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/%7B{msdyn_Load1}%7D/WebResources/msdyn_/Images/AppModule_Default_Icon.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1056.inf", 
		LAST);

	web_concurrent_end(NULL);

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	web_add_cookie("ESTSAUTHPERSISTENT={ESTSAUTHPERSISTENT_6}; DOMAIN=login.microsoftonline.com");

	web_add_cookie("ESTSAUTH={ESTSAUTH_2}; DOMAIN=login.microsoftonline.com");

	web_revert_auto_header("Cache-Control");

	web_revert_auto_header("ReferrerReqId");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate, peerdist");

	web_add_auto_header("Accept", 
		"text/html, application/xhtml+xml, */*");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

/*Correlation comment: Automatic rules - Do not change!  
Original value='JM_HZLKIqcsirxAueo8dSkoXCeic0VqUcIkHboX_nax2LRhIIomAe_ZFoE9c8okArOrLa0NW-GHvlXH0jMjbdWFHV7p7VctJcT8HSHHShRhLG3Ua0xkOKzV0svBMGwFn96tt1GepdLikfKdbovZUVlK5idQTf8RpWpC6-jleZx5Gpwigu-NukB1OYz5I9l2PlORMEoHZ4omTXA7zpjU0XkkkGOHGyGiwQmegh2eYAryurBpgsJsCHxBN4RUSji2e' 
Name ='CorrelationParameter_33' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='state1'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_33",
		"RegExp=state=OpenIdConnect.AuthenticationProperties%3d(.*?)&nonce",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"RequestUrl=*/signon*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='636595439199225474.ZDM3YTY5YTUtMjhjOS00MTJjLWI2YzEtMDU5MDMwOGViZjY2MTcyYzg3ZjgtOWI1Yi00ZGFkLTg4ZjUtOWZkYjYzZTE2MmI4&redirect_uri=https%3a%2f%2fhome.dynamics.com%2fproxy%2fsignon&post_logout_redirect_uri=https%3a%2f%2fhome.dynamics.com&prompt=none' 
Name ='nonce_3' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='nounce'*/
	web_reg_save_param_regexp(
		"ParamName=nonce_3",
		"RegExp=nonce=(.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"RequestUrl=*/signon*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='636595439199225474.ZDM3YTY5YTUtMjhjOS00MTJjLWI2YzEtMDU5MDMwOGViZjY2MTcyYzg3ZjgtOWI1Yi00ZGFkLTg4ZjUtOWZkYjYzZTE2MmI4' 
Name ='nonce_4' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='nonce2'*/
	web_reg_save_param_regexp(
		"ParamName=nonce_4",
		"RegExp=nonce=(.*?)&amp",
		"DFEs=Xml",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/authorize*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='3890497d-c997-47d1-8362-fc6107488192' 
Name ='session_state_2' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='sessionstate1'*/
	web_reg_save_param_regexp(
		"ParamName=session_state_2",
		"RegExp=name=\"session_state\"\\ value=\"(.*?)\"\\ ",
		"DFEs=Xml",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/authorize*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='AQABAAIAAADX8GCi6Js6SK82TsD2Pb7r4yE2NQNABBdeIhOygFfCrFSx4ZhwtNt77ho0l1IP13N8MvfnJXcqYJGee7Ub5egUpz1wdMypQPfgYLuzYJXgIGU_koLHewltNhZzq56plPn_2IrQYaYcU9UVOqoY6zx8QMlYJzhVTcMeobrYBVHfIVvdYpupLoq8stzAnysAZfGKc47qwQWI1kv-zvr5Q6XH5PqflMNvCH9jfqpAFaMZS9qIOEkAvo3NF6eKiUfFA1WpiKljY3DQAsjArcdEv5AUfhV_otmU-3b85ApTTM75umJc5beobWwTuO5ZmXOfRAdegzlkOuwt7Q_AhDyZQ6FzkqYZ6JrVuWTP7rIZqAknJXNIhNmFUV3Pz97tQIEGDawafmr4dwUv4oIm7uQoDw_Lg4rx5v10CwSyDuF8yQlvgIyHPM0GoPkqoIcAEMQS_vuXLFY8Bw54LNWahtLzXCY0niOaEF1PEXgt7eYqba-aWkN9mq2uPSWL2oFn7p8haSBGw3IdDO_WGVoi3WgnlgSguUAwxSY-w_AnV3PGuQquFT2_HGTu8bNC_7dnrqRKajayyXtpPV4-6i-BXpqvW7l6e8hibo7ZBms4QJYqhdsTW2G8guScUH4YRTDNhPoBwK5xLUqPlM3wIUnPgZVkInzqXWWA4Qpf5_fmKeSO3kqIDwgs_8J22svmauKu4DuNpoAgAA' 
Name ='code_2' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='code1'*/
	web_reg_save_param_regexp(
		"ParamName=code_2",
		"RegExp=name=\"code\"\\ value=\"(.*?)\"\\ ",
		"DFEs=Xml",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/authorize*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiIsIng1dCI6IkZTaW11RnJGTm9DMHNKWEdtdjEzbk5aY2VEYyIsImtpZCI6IkZTaW11RnJGTm9DMHNKWEdtdjEzbk5aY2VEYyJ9.eyJhdWQiOiJiYWI0NzU1NS0wMzhhLTQ0MzQtYTkzMS05NmNjNjA5MWNkZDciLCJpc3MiOiJodHRwczovL3N0cy53aW5kb3dzLm5ldC9jMGUwNjAxZi0wZmFjLTQ0OWMtOWM4OC1hMTA0YzRlYjlmMjgvIiwiaWF0IjoxNTIzOTQ2ODI3LCJuYmYiOjE1MjM5NDY4MjcsImV4cCI6MTUyMzk1MDcyNywiYW1yIjpbInB3ZCJdLCJjX2hhc2giOiJSVGpYM2lhRDI2NXpLV2ctTDNnVmJnIiwiZmFtaWx5X25hbWUiOiJGc3Z0ZXN0dXNlcjEiLCJnaXZlbl9uYW1lIjoiRnN2dGVzdHVzZXIxIiwiaXBhZGRyIjoiMjAzLjEyLjE5NC4yNDAiLCJuYW1lIjoiRnN2dGVzdHVzZXIxIiwibm9uY2UiOiI2MzY1OTU0MzkxOTkyMjU0NzQuWkRNM1lUWTVZVFV0TWpoak9TMDBNVEpqTFdJMll6RXRNRFU1TURNd09HVmlaalkyTVRjeVl6ZzNaamd0T1dJMVlpMDBaR0ZrTFRnNFpqVXRPV1prWWpZelpURTJNbUk0Iiwib2lkIjoiYzc2ZTc3OGMtNGNhNS00NWQ4LWE4M2QtZWQyZmYyYzE2MDNkIiwicHVpZCI6IjEwMDM3RkZFQTY4MTg3RDUiLCJzdWIiOiJ2Q094cUZ3dG5vczVSRFFyOV9pcEhpNlBiYzVRZzVHSkFUY3VvMzNvejRnIiwidGlkIjoiYzBlMDYwMWYtMGZhYy00NDljLTljODgtYTEwNGM0ZWI5ZjI4IiwidW5pcXVlX25hbWUiOiJGc3Z0ZXN0dXNlcjFAZGhoc3ZpY2dvdmF1Lm9ubWljcm9zb2Z0LmNvbSIsInVwbiI6IkZzdnRlc3R1c2VyMUBkaGhzdmljZ292YXUub25taWNyb3NvZnQuY29tIiwidXRpIjoiU3JlNGFUODFkRUNpVHBZOVNGdzZBQSIsInZlciI6IjEuMCJ9.MPhvHoEc1vaUBhgUzuIK5pRcpJC7qziiSR3jmVU6ZCfqOyfClANh66ES6uHWviLQcdLS_C6Z6WQxrdWgJpKWpu_whoKw8jfhTus5PZUPqr0GqVYFSqSquOjKo65aM_1r19LALJfOK0Kf9Wyp1ZS6dDoqjYyjXYDKeGNvHTPhvwK5bp1XTygL7ty2yElkTKzl3FxeriC--5ED8p9IlkHLTjC2KD72uRsTcDrym7u3FuJ3Ys2UXwOWTTfhzTU2p8f59-_6pRYFQL_i9bIslSJScPnK3fRCcVmIQlR4GlZrD9NVfEcaFKewGOKTovqT92OMm5L1U1we_po7pQBFWXpFdg' 
Name ='CorrelationParameter_34' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='tokenid2'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_34",
		"RegExp=name=\"id_token\"\\ value=\"(.*?)\"\\ ",
		"DFEs=Xml",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/authorize*",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=client_id_1",
		"RegExp=client_id=(.*?)&response_mode",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"RequestUrl=*/signon*",
		LAST);

	web_url("signon", 
		"URL=https://home.dynamics.com/proxy/signon?d365FrameChannelId=6b5c3763-3251-49f7-bff1-25f475cb19a5", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1057.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate");

	web_add_auto_header("Cache-Control", 
		"no-cache");

/*Correlation comment: Automatic rules - Do not change!  
Original value='sZE7136_OLnnMxocnh1Lgc91fkbS-jqCs8ZaBmAH_aZgezBZhGDLkw7bCov_ltfpSZBUP8hKeRT0M5Tj9ckTsQ6130tpy0naNQLdNRa3sG3KphLGWNXKTpTiXg2EIC2o-8s6hrJTtWXtDvk2RRjwEA2' 
Name ='CorrelationParameter_35' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='RequestVerToken1'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_35",
		"RegExp=type=\"hidden\"\\ value=\"(.*?)\"\\ ",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/proxy*",
		LAST);

	web_reg_save_param_regexp(
		"ParamName=v_1",
		"RegExp=src=\"/bundles/proxy\\?v=(.*?)\"></script",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/proxy*",
		LAST);

	web_submit_data("signon_2",
		"Action=https://home.dynamics.com/proxy/signon",
		"Method=POST",
		"RecContentType=text/html",
		"Referer=https://login.microsoftonline.com/common/oauth2/authorize?client_id={client_id_1}&response_mode=form_post&response_type=code+id_token&scope=openid+profile&state=OpenIdConnect.AuthenticationProperties%3d{CorrelationParameter_33}&nonce={nonce_3}",
		"Snapshot=t1058.inf",
		"Mode=HTTP",
		ITEMDATA,
		"Name=code", "Value={code_2}", ENDITEM,
		"Name=id_token", "Value={CorrelationParameter_34}", ENDITEM,
		"Name=state", "Value=OpenIdConnect.AuthenticationProperties={CorrelationParameter_33}", ENDITEM,
		"Name=session_state", "Value={session_state_2}", ENDITEM,
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("proxy",
		"URL=https://home.dynamics.com/bundles/proxy?v={v_1}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer=https://home.dynamics.com/proxy?d365FrameChannelId=6b5c3763-3251-49f7-bff1-25f475cb19a5",
		"Snapshot=t1059.inf",
		LAST);

	web_add_auto_header("Accept", 
		"*/*");

	web_add_header("__requestverificationtoken",
		"{CorrelationParameter_35}");

	web_custom_request("refreshAccessToken", 
		"URL=https://home.dynamics.com/authentication/refreshAccessToken?audience=https%3A%2F%2Fservice.powerapps.com%2F", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://home.dynamics.com/proxy?d365FrameChannelId=6b5c3763-3251-49f7-bff1-25f475cb19a5", 
		"Snapshot=t1060.inf", 
		"Mode=HTTP", 
		"EncType=", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("healthCheck", 
		"URL=https://home.dynamics.com/api/healthCheck", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://home.dynamics.com/proxy?d365FrameChannelId=6b5c3763-3251-49f7-bff1-25f475cb19a5", 
		"Snapshot=t1061.inf", 
		LAST);

	web_convert_from_formatted("FormattedData=<HP_EXTENSION name=\"JsonXml,Xml\"><array><object><object name=\"data\"><pair name=\"data\" type=\"str\">{\\&quot;serviceName\\&quot;:\\&quot;\\&quot;,\\&quot;appId\\&quot;:\\&quot;9eb199a9-d221-43d7-8d01-7006601d9cc1\\&quot;,\\&quot;time\\&quot;:74}</pair><pair name=\"eventName\" type=\"str\">appActiveSet</pair><pair name=\"eventTimeStamp\" type=\"str\">2018-04-17T06:38:51.089Z</pair><pair name=\"eventType\" type=\"str\">TelemetryAction</pair><pair name=\"objectId\" type=\"str\">{AttributeValue_1}</pair><pair name=\"principalId\" type=\"str\">{CorrelationParameter_9_1}</pair><pair name=\"region\" type=\"str\">westus</pair><pair name=\"sessionId\" type=\"str\">be66a651-c43d-4bf3-bee8-a6d30b5a4dc7</pair><pair name=\"tenantId\" type=\"str\">c0e0601f-0fac-449c-9c88-a104c4eb9f28</pair><pair name=\"trackingId\" type=\"str\">00000000-0000-0000-0000-000000000000</pair><pair name=\"userAgent\" type=\"str\">Mozilla/5.0 (Windows NT 6.3; WOW64; Trident/7.0; .NET4.0E; .NET4.0C; .NET CLR 3.5.30729; .NET CLR 2.0.50727; .NET CLR 3.0.30729; InfoPath.3; .NET CLR 1.1.4322; rv:11.0) like Gecko</pair><pair name=\"userHash\" type=\"str\">{AttributeValue_1}</pair></object><pair name=\"name\" type=\"str\">ClientTelemetry</pair></object></array></HP_EXTENSION>", 
		"TargetParam=DFE_BODY_10", 
		LAST);

	web_custom_request("LogTrace", 
		"URL=https://home.dynamics.com/api/logging/LogTrace", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://home.dynamics.com/proxy?d365FrameChannelId=6b5c3763-3251-49f7-bff1-25f475cb19a5", 
		"Snapshot=t1062.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={DFE_BODY_10}", 
		LAST);

	web_convert_from_formatted("FormattedData=<HP_EXTENSION name=\"JsonXml,Xml\"><array><object><object name=\"data\"><pair name=\"data\" type=\"str\">{\\&quot;viewportWidth\\&quot;:1920,\\&quot;viewportHeight\\&quot;:963,\\&quot;referrerUrl\\&quot;:\\&quot;https://cloudredirector.crm6.dynamics.com/G/AuthRedirect/Index.aspx?RedirectTo=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2fmain.aspx%3fappid%3dab18c93f-61e6-e711-a848-000d3ad117e3\\&quot;,\\&quot;hasHeader\\&quot;:false,\\&quot;hasTaskpane\\&quot;:true,\\&quot;inFocusMode\\&quot;:false,\\&quot;product\\&quot;:\\&quot;unknown\\&quot;,\\&quot;time\\&quot;:10520}</pair><pair name=\"eventName\" type=\"str\">shellLoaded</pair><pair name=\"eventTimeStamp\" type=\"str\">2018-04-17T06:38:51.089Z</pair><pair name=\"eventType\" type=\"str\">TelemetryAction</pair><pair name=\"objectId\" type=\"str\">{AttributeValue_1}</pair><pair name=\"principalId\" type=\"str\">{CorrelationParameter_9_1}</pair><pair name=\"region\" type=\"str\">westus</pair><pair name=\"sessionId\" type=\"str\">be66a651-c43d-4bf3-bee8-a6d30b5a4dc7</pair><pair name=\"tenantId\" type=\"str\">c0e0601f-0fac-449c-9c88-a104c4eb9f28</pair><pair name=\"trackingId\" type=\"str\">00000000-0000-0000-0000-000000000000</pair><pair name=\"userAgent\" type=\"str\">Mozilla/5.0 (Windows NT 6.3; WOW64; Trident/7.0; .NET4.0E; .NET4.0C; .NET CLR 3.5.30729; .NET CLR 2.0.50727; .NET CLR 3.0.30729; InfoPath.3; .NET CLR 1.1.4322; rv:11.0) like Gecko</pair><pair name=\"userHash\" type=\"str\">{AttributeValue_1}</pair></object><pair name=\"name\" type=\"str\">ClientTelemetry</pair></object></array></HP_EXTENSION>", 
		"TargetParam=DFE_BODY_11", 
		LAST);

	web_custom_request("LogTrace_2", 
		"URL=https://home.dynamics.com/api/logging/LogTrace", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://home.dynamics.com/proxy?d365FrameChannelId=6b5c3763-3251-49f7-bff1-25f475cb19a5", 
		"Snapshot=t1063.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={DFE_BODY_11}", 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	/*web_concurrent_start(NULL);

	web_url("d365portal",
		"URL=https://management.azure.com/providers/Microsoft.BusinessAppDiscovery/objectIds/{AttributeValue_1}/userSettings/d365portal?api-version=2016-11-01",
		"Resource=1",
		"RecContentType=application/json",
		"Referer=https://home.dynamics.com/proxy?d365FrameChannelId=6b5c3763-3251-49f7-bff1-25f475cb19a5",
		"Snapshot=t1064.inf",
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_url("apps", 
		"URL=https://management.azure.com/providers/Microsoft.BusinessAppDiscovery/apps?api-version=2016-11-01&$expand=lastAccessTime,isPinned,timePinned,recentLocations", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://home.dynamics.com/proxy?d365FrameChannelId=6b5c3763-3251-49f7-bff1-25f475cb19a5", 
		"Snapshot=t1065.inf", 
		LAST);

	web_concurrent_end(NULL);*/

	web_convert_from_formatted("FormattedData=<HP_EXTENSION name=\"JsonXml,Xml\"><array><object><object name=\"data\"><pair name=\"data\" type=\"str\">{\\&quot;isNewUser\\&quot;:false,\\&quot;uiLocation\\&quot;:\\&quot;taskpane\\&quot;,\\&quot;time\\&quot;:28237}</pair><pair name=\"eventName\" type=\"str\">appsInitialized</pair><pair name=\"eventTimeStamp\" type=\"str\">2018-04-17T06:39:07.741Z</pair><pair name=\"eventType\" type=\"str\">TelemetryAction</pair><pair name=\"objectId\" type=\"str\">{AttributeValue_1}</pair><pair name=\"principalId\" type=\"str\">{CorrelationParameter_9_1}</pair><pair name=\"region\" type=\"str\">westus</pair><pair name=\"sessionId\" type=\"str\">be66a651-c43d-4bf3-bee8-a6d30b5a4dc7</pair><pair name=\"tenantId\" type=\"str\">c0e0601f-0fac-449c-9c88-a104c4eb9f28</pair><pair name=\"trackingId\" type=\"str\">00000000-0000-0000-0000-000000000000</pair><pair name=\"userAgent\" type=\"str\">Mozilla/5.0 (Windows NT 6.3; WOW64; Trident/7.0; .NET4.0E; .NET4.0C; .NET CLR 3.5.30729; .NET CLR 2.0.50727; .NET CLR 3.0.30729; InfoPath.3; .NET CLR 1.1.4322; rv:11.0) like Gecko</pair><pair name=\"userHash\" type=\"str\">{AttributeValue_1}</pair></object><pair name=\"name\" type=\"str\">ClientTelemetry</pair></object></array></HP_EXTENSION>", 
		"TargetParam=DFE_BODY_12", 
		LAST);

	web_custom_request("LogTrace_3", 
		"URL=https://home.dynamics.com/api/logging/LogTrace", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://home.dynamics.com/proxy?d365FrameChannelId=6b5c3763-3251-49f7-bff1-25f475cb19a5", 
		"Snapshot=t1066.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={DFE_BODY_12}", 
		LAST);

	lr_think_time(3);

	/*lr_start_transaction("CRM_01_PersonSearch_03_GoToPeople");

	web_custom_request("3.0_2",
		"URL=https://browser.pipe.aria.microsoft.com/Collector/3.0/?qsp=true&content-type=application%2Fbond-compact-binary&client-id=NO_AUTH&sdk-version=ACT-Web-JS-2.9.0&x-apikey={x-apikey}",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t26.inf",
		"Mode=HTML",
		"EncType=",
		"BodyBinary=+\n"
		"\\x01I\\x11JS_default_source\\xA9$4ad4035d-ceaf-b0c2-4316-b733ba5d8673\\xD1\\x06\\xCA\\x8F\\xEB\\xCC\\xBEX\\xCB\\x08\n"
		"\\x01)$d701f784-e456-229e-4c7e-ae8bac7105cbq\\xB0\\x8F\\xEB\\xCC\\xBEX\\xA9\\x0Bperformance\\xC9\\x06\\x0Bperformance\\xCD\r\t\t)\\x10EventInfo.Source\\x11JS_default_source\\x10EventInfo.InitId$006cd9dd-d350-f036-72a7-3d04875a50f3\\x12EventInfo.Sequence\\x012\\x0EEventInfo.Name\\x0Bperformance\\x0EEventInfo.Time\\x182018-03-05T06:15:56.632Z\\x14EventInfo.SdkVersion\\x10ACT-Web-JS-2.9.0\\x10AppInfo.Language\\x02en\\x11UserInfo.Language\\x05en-AU\\x11UserInfo.TimeZone\\x08+0-11:00\\x16DeviceInfo.BrowserName\\x04MSIE\\x19DeviceInfo.BrowserVersion\\x0411.0\\x11DeviceInfo.OsName\\x07Windows\\x14DeviceInfo.OsVersion\\x038.1\n"
		"AppInfo.Id\\x07G2Shell\\x0FAppInfo.Version\\x0E16.00.2194.000\\x0BContext_Env\\x07seaprod\\x0CContext_Site\\x0BDynamics365\\x11Context_SiteSubId\\x08ShellCRM\\x15Context_WorkloadAppId\\x03CRM\\x0CContext_Pagelhttps://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3#856683060\\x0BContext_SID$5f54b8ca-cee9-4912-8ca1-468eb04610b7\\x0BContext_CID$0c563f04-55b3-4aa9-a92c-fc9391b3d643\\x0BContext_PID!1520230496624_0.40394404036515063\\x0BContext_TID$c0e0601f-0fac-449c-9c88-a104c4eb9f28\\x14UserInfo.OMSTenantId$c0e0601f-0fac-449c-9c88-a104c4eb9f28\\x0BContext_UID$990775f1-fb32-4958-ac6e-98d58c8422ec\\x0CContext_PUID\\x101003BFFDA67E8408\\x0BUserInfo.Id\\x101003BFFDA67E8408\\x0FUserInfo.IdType\\x015\\x12Context_IsConsumer\\x05false\\x0FContext_Flights\\x91\\x0315GA,SE371649NFDOnO365SuiteService,SE371770SystemAlertsHistoryDisabled,SE371882EnableFormsForNewServicePlans,SE371903ShellAppsLaunchData,SE371933IgnoreProvisioningStatusForExchange,SE371934IgnoreProvisioningStatusForW"
		"AC,SE371935IgnoreProvisioningStatusForAllApps,SE371940ShowTodo,SE371944ShellAppLauncherV3,SE371948ShowStaffHubLink,SE371950EnableScopeAdminUnits,SE371966RestoreOneDriveEnabled,Exp9015C\\x03BOT\\x0517606\\x03LRS\\x03118\\x03LRC\\x03188\\x03MFL\\x03188\\x03AFL\\x03189\\x03OUT\\x0560259\\x03BLS\\x010\\x03BLC\\x010\\x03MLS\\x0263\\x03MLC\\x0265\\x00\\x00\\x00",
		LAST);

	lr_end_transaction("CRM_01_PersonSearch_03_GoToPeople",LR_AUTO);*/

	lr_think_time(3);

	web_revert_auto_header("Cache-Control");

	web_revert_auto_header("LoginRequestCorrelationId");

return 0;
}
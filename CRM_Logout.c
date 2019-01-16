CRM_Logout()
{
	#include <string.h>
	char path1[1024],path2[1024],path3[1024];
    	char separators[] = "\\"; 
   	char * token,* token1,* pch;
   	char word[] = "x2b";
   	char crmwrpctoken1[1024],crmwrpctoken2[1024],crmwrpctoken3[1024],crmwrpctoken4[1024];

	lr_think_time(3);
	
	/*lr_output_message ("path is %s", lr_eval_string("{path2}"));
	lr_save_string("\\", "separators");
	
	// Get the first token
   	token = (char *)strtok(lr_eval_string("{path2}"), lr_eval_string("{separators}"));
   
    lr_output_message ("token is %s", token);
    
    strcat(crmwrpctoken2, token);
    	  
    lr_output_message ("fullpath is %s", crmwrpctoken2);
    
    if (!token) 
	    {
	        
	    	lr_save_string("token", "crmwrpctoken2");
	        lr_output_message ("No tokens found in string!");
	        lr_output_message ("Full path of file is %s", crmwrpctoken2);
	        //return( -1 );
	    }
	
    else{
			    // While valid tokens are returned
			    do      
				    {    	    
						lr_output_message ("Full path of file is %s", crmwrpctoken2);			
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
											        	        
											        strcat(crmwrpctoken2, "+");
											   	 	lr_output_message ("Full path of file is %s", crmwrpctoken2);
											   	 	lr_save_string(token, "crmwrpctoken3");
											   	 	token = lr_eval_string("{crmwrpctoken3}") + 3;
											   	 	strcat(crmwrpctoken2, token);	   	 	
										        }
							
											}
								        else
								        	{
											if(token)
										        {
											        lr_output_message ("%s", token );
											        	        
											        strcat(crmwrpctoken2, "/");
											   	 	lr_output_message ("Full path of file is %s", crmwrpctoken2);
											   	 	lr_save_string(token, "crmwrpctoken3");
											   	 	token = lr_eval_string("{crmwrpctoken3}") + 3;
											   	 	strcat(crmwrpctoken2, token);	   	 	
										        }
										        
								        	}
										      
								    	    
				}while (token != NULL );
			    
    	}

    lr_output_message ("Full path of file is %s", crmwrpctoken2);
   	 	
	lr_save_string(crmwrpctoken2, "path2");*/

	lr_save_string(lr_eval_string("{CorrelationParameter_2122}"), "path1");
	
	crmwrpctoken();

	/*lr_output_message ("path is %s", lr_eval_string("{path3}"));
	lr_save_string("\\", "separators");
	
	// Get the first token
   	token = (char *)strtok(lr_eval_string("{path3}"), lr_eval_string("{separators}"));
   
    lr_output_message ("token is %s", token);
    
    strcat(crmwrpctoken4, token);
    	  
    lr_output_message ("fullpath is %s", crmwrpctoken4);
    
    if (!token) 
	    {
	        
	    	lr_save_string("token", "crmwrpctoken2");
	        lr_output_message ("No tokens found in string!");
	        lr_output_message ("Full path of file is %s", crmwrpctoken4);
	        //return( -1 );
	    }
	
    else{
			    // While valid tokens are returned
			    do      
				    {    	    
						lr_output_message ("Full path of file is %s", crmwrpctoken4);			
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
											        strcat(crmwrpctoken4, "+");
											   	 	lr_output_message ("Full path of file is %s", crmwrpctoken4);
											   	 	lr_save_string(token, "crmwrpctoken3");
											   	 	token = lr_eval_string("{crmwrpctoken3}") + 3;
											   	 	strcat(crmwrpctoken4, token);	   	 	
										        }
							
											}
								        else
								        	{
											if(token)
										        {
											        lr_output_message ("%s", token );
				        	        		        strcat(crmwrpctoken4, "/");
											   	 	lr_output_message ("Full path of file is %s", crmwrpctoken4);
											   	 	lr_save_string(token, "crmwrpctoken3");
											   	 	token = lr_eval_string("{crmwrpctoken3}") + 3;
											   	 	strcat(crmwrpctoken4, token);	   	 	
										        }
										        
								        	}
									    	    
				}while (token != NULL );
			    
    	}

    lr_output_message ("Full path of file is %s", crmwrpctoken4);
   	 	
	lr_save_string(crmwrpctoken4, "path3");*/

	web_add_cookie("MSISAuth={CorrelationParameter_2123}; DOMAIN={param_URL}.crm6.dynamics.com");

	web_add_cookie("MSISAuth1={CorrelationParameter_2124}; DOMAIN={param_URL}.crm6.dynamics.com");

	web_add_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/RetrieveLookupMruData");

	web_add_header("CRMWRPCToken", 
		lr_eval_string("{path1}"));

	web_add_auto_header("Accept", 
		"*/*");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate");

	web_add_auto_header("CRMWRPCTokenTimeStamp", 
		"{CorrelationParameter_1111}");

	web_add_auto_header("Cache-Control", 
		"no-cache");

	web_add_auto_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_add_auto_header("ReferrerReqId", 
		"{CorrelationParameter_30}");

	lr_start_transaction("CRM_01_d_SignOut");

	web_custom_request("LookupMruWebService.asmx", 
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/LookupMruWebService.asmx", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t54.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=utf-8", 
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><RetrieveLookupMruData xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"></RetrieveLookupMruData></soap:Body></soap:Envelope>", 
		LAST);

	lr_save_string(lr_eval_string("{CorrelationParameter_1121}"), "path1");
	
	crmwrpctoken();

	web_add_header("CRMWRPCToken", 
		lr_eval_string("{path1}"));

	web_add_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/UploadRecentlyViewed");

	web_custom_request("RecentlyViewedWebService.asmx_2", 
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/RecentlyViewedWebService.asmx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t55.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=utf-8", 
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><UploadRecentlyViewed xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><recentlyViewedXml>&#60;RecentlyViewedData&#62;&#60;RecentlyViewedEntityData etc&#61;&#39;2&#39;&#62;&#60;RecentlyViewedItem&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;Type&#62;0&#60;&"
		"#47;Type&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;ObjectId&#62;&#38;&#35;123&#59;000D2941-80D3-E711-A845-000D3AD117E3&#38;&#35;125&#59;&#60;&#47;ObjectId&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;EntityTypeCode&#62;2&#60;&#47;EntityTypeCode&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;EntityTypeName&#62;contact&#60;&#47;EntityTypeName&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;DisplayName&#62;Person&#60;&#47;DisplayName&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;Title&#62;Prasad Udawatte&#60;&#47"
		";Title&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;Action&#62;&#60;&#47;Action&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;IconPath&#62;&#60;&#47;IconPath&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;LastAccessed&#62;03&#38;&#35;47&#59;05&#38;&#35;47&#59;2018 06&#38;&#35;58&#59;17&#38;&#35;58&#59;46&#60;&#47;LastAccessed&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;PinStatus&#62;false&#60;&#47;PinStatus&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#60;&#47;RecentlyViewedItem&#62;&#60;&#47;RecentlyViewedEntityData"
		"&#62;&#60;RecentlyViewedEntityData etc&#61;&#39;1030&#39;&#62;&#60;RecentlyViewedItem&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;Type&#62;0&#60;&#47;Type&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;ObjectId&#62;&#38;&#35;123&#59;d4e8c796-0dd0-e711-a826-000d3ae0a7f8&#38;&#35;125&#59;&#60;&#47;ObjectId&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;EntityTypeCode&#62;1030&#60;&#47;EntityTypeCode&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;EntityTypeName&#62;&#60;&#47;EntityTypeName&#62;&#13;&#10;&#9;&#9;&"
		"#9;&#9;&#9;&#9;&#60;DisplayName&#62;System Form&#60;&#47;DisplayName&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;Title&#62;Hub worker dashboard&#60;&#47;Title&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;Action&#62;pagemode&#38;&#35;61&#59;iframe&#38;&#35;38&#59;sitemappath&#38;&#35;61&#59;SFA&#38;&#35;37&#59;7cMyWork&#38;&#35;37&#59;7cnav_dashboards&#60;&#47;Action&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;IconPath&#62;&#60;&#47;IconPath&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;LastAccessed&#62;"
		"03&#38;&#35;47&#59;05&#38;&#35;47&#59;2018 06&#38;&#35;58&#59;01&#38;&#35;58&#59;49&#60;&#47;LastAccessed&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#9;&#60;PinStatus&#62;false&#60;&#47;PinStatus&#62;&#13;&#10;&#9;&#9;&#9;&#9;&#9;&#60;&#47;RecentlyViewedItem&#62;&#60;&#47;RecentlyViewedEntityData&#62;&#60;&#47;RecentlyViewedData&#62;</recentlyViewedXml><retrieveAfterUpdated>true</retrieveAfterUpdated></UploadRecentlyViewed></soap:Body></soap:Envelope>", 
		LAST);

	web_add_auto_header("Accept", 
		"text/html, application/xhtml+xml, */*");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate, peerdist");

	web_add_auto_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_auto_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

/*Correlation comment: Automatic rules - Do not change!  
Original value='AQABAAEAAABHh4kmS_aKT5XrjzxRAtHz1MFS19_KtGkrQF0DZgsR_Ul1-xw_xwDfjWUQjtBnxhB-bCbc5VkPHR2cHRCEJ2yFHRI9IeuCDRZXkUu_8M9aAeXOh0fhek9oX7Q3BN9HSuTBJJlg6xtEviDgTit1ANUT3l8MmaDJvtJdQTKrvEZ7ZtX-8K8QG7yIwjoCyk44TlHNxqgqsSmUbDgpC4GTqiV-G-sH6nyqYfKVfVa1sfOdbX4sS4w-vxTs6CvfwtUAM6XkvtK-zgG3G3pj_KmpcvMWv2HWaTc2t85NtiEo-0P-FyMIif-R-_51LwEHeDiK3fWpwizn1FdaHw3xfgWfPTE5tuCSNMGUHEtQ-OXmrAvc8SSEwrv125mJvEt-4TJAlIF8211dz5nQIcbIomZrLCiyAQ7lqWLSVkvnfaluueCxU2-W-aPokU3O-UMBBo_TH-wJLhjUoRVlYcesIplLmByuoY25NCu0Z397gorg_MX5no51OUns5s3bhHSFJbScw-ydS4q1uw-38kLCjwjtyrnuPIQ841u8EazUN-4Niw7JFojst7RPHSyByapg0xYjVXeuSSeAP-NT8rCXHiXTOpqrKUtCEO75s5MzYPsv5tvsc56lRfQhp0zblm8akB5diBQKydMRT3ehphi_0ZiHiQK0Kh7LxpQPeURomV3NWkQTV9E9DDusHi1D4_O9ixK4DynZhyqmzjDTVFbQYclo5NlMWZrg9Ijn5NfGSceP_cbpL4obJNfZciP7vb3beKriBV8gAA' 
Name ='ESTSAUTHPERSISTENT' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='ESTSAUTHPERSISTENT2'*/
	web_reg_save_param_regexp(
		"ParamName=ESTSAUTHPERSISTENT",
		"RegExp=ESTSAUTHPERSISTENT=(.*?);",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Cookies",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='QVFBQkFBRUFBQUJIaDRrbVNfYUtUNVhyanp4UkF0SHo1akZGSEh1U0trTlhDSW1lbFNXR0ZtY2ticWFvTlpscDVmejROWUU5NTg1MVlTMHdnZHR5SkRxM2YzdGFvTU9GRlBPaGtPTGxGQlBxVy1qZnJGaURPeUFB' 
Name ='ESTSAUTH_1' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='ESTSAUTH2'*/
	web_reg_save_param_regexp(
		"ParamName=ESTSAUTH_1",
		"RegExp=ESTSAUTH=(.*?);",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Cookies",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		LAST);

	web_url("main.aspx_3", 
		"URL=https://{param_URL}.crm6.dynamics.com/main.aspx?signout=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t204.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Accept", 
		"application/javascript, */*;q=0.8");

	web_url("jquery.1.11.min.js", 
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7293.16/content/cdnbundles/jquery.1.11.min.js", 
		"Resource=1", 
		"RecContentType=application/x-javascript", 
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignout1.0&wreply=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f", 
		"Snapshot=t205.inf", 
		LAST);

	web_add_cookie("ESTSAUTHPERSISTENT={ESTSAUTHPERSISTENT}; DOMAIN=login.microsoftonline.com");

	web_add_cookie("ESTSAUTH={ESTSAUTH_1}; DOMAIN=login.microsoftonline.com");

	web_add_auto_header("Accept", 
		"text/html, application/xhtml+xml, */*");

	web_url("{param_URL}.crm6.dynamics.com", 
		"URL=https://{param_URL}.crm6.dynamics.com/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignout1.0&wreply=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f", 
		"Snapshot=t210.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("CRM_01_d_SignOut",LR_AUTO);

	lr_think_time(3);

return 0;
}
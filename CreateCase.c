CreateCase()
{
	char crmwrpctoken5[1024]="",crmwrpctoken6[1024]="";
	int temp,ord,var1;
	
	var1 = DATE_NOW;
	
	lr_save_datetime("%d%m%Y", var1 , "param_ClientDate");
	lr_think_time(5);

/*Correlation comment: Automatic rules - Do not change!  
Original value='ce4a9f91-ce28-4c59-89d6-da01ae2151d0' 
Name ='CorrelationParameter_38' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_38",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"RequestUrl=*/LookupService.asmx*",
		LAST);

//oid="{C8243179-3633-E811-A831-000D3AE0B82E}" oname="PerfTest
	web_reg_save_param("ClientFN","LB/IC=\" oname=\"","RB/IC= ","Ord=All","NotFound=Warning",LAST);
	web_reg_save_param("ClientLN","LB/IC= ","RB/IC=\" otypename=\"contact\"","Ord=All","NotFound=Warning",LAST);
	web_reg_save_param("ClientOid","LB=oid=\"{","RB=}\" oname=\"","Ord=All","NotFound=Warning",LAST);
	
	web_add_header("SOAPAction","http://schemas.microsoft.com/crm/2009/WebServices/RetrieveInlineSearchResults");
	
	lr_start_transaction("CRM_06_CreateCase_04_EnterDetails1");

	web_custom_request("LookupService.asmx_3",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/LookupService.asmx",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t48.inf",
		"Mode=HTML",
		"EncType=text/xml; charset=utf-8",
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><RetrieveInlineSearchResults xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><typesArray><int>2</int></typesArray><bindingColumns></bindingColumns><additionalParameters>&#38;IsInlineLookup&#61;true&#38;customFilter&#61;&#38;customFilterTypes&#61;</additionalParameters><positions><int>0</int></positions><resolveEmailAddress>false</resolveEmailAddress><sortResults>true</sortResults><lookupValues><string>{param_ClientUser}{param_ClientNumber}</string></lookupValues><defaultViewId></defaultViewId></RetrieveInlineSearchResults></soap:Body></soap:Envelope>",
		LAST);

	if(atoi(lr_eval_string("{ClientOid_count}")) == 0)
	{
	
	lr_end_transaction("CRM_06_CreateCase_04_EnterDetails1",LR_FAIL);
	
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	
	}
	
	else
	{
		ord= rand() % (atoi(lr_eval_string("{ClientOid_count}")) + 1 - 1) + 1;
		lr_output_message("%d",ord);
		lr_save_string(lr_paramarr_idx("ClientOid", ord),"ClientOid");
		lr_save_string(lr_paramarr_idx("ClientLN", ord),"ClientLN");
		lr_save_string(lr_paramarr_idx("ClientFN", ord),"ClientFN");		
	}
	
	web_add_auto_header("Cache-Control", 
		"no-cache");

	web_add_auto_header("FormLoadId", 
		"{90e54e86-12d1-3a6b-32ae-82426864576d}");

	web_add_auto_header("ReferrerReqId",
		"{CorrelationParameter_36}");

	web_add_auto_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/QuerySipInfo");

/*Correlation comment: Automatic rules - Do not change!  
Original value='8466fe0d-3a64-4b29-ae2b-c8b66ecfd583' 
Name ='CorrelationParameter_39' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_39",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		LAST);

	web_custom_request("PresenceService.asmx_2",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/PresenceService.asmx",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t49.inf",
		"Mode=HTML",
		"EncType=text/xml; charset=utf-8",
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><QuerySipInfo xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><entityListXml>&#60;grid&#62;&#60;row oid&#61;&#34;&#38;&#35;123&#59;{ClientOid}&#38;&#35;125&#59;&#34; otype&#61;&#34;2&#34;&#47;&#62;&#60;&#47;grid&#62;</entityListXml></QuerySipInfo></soap:Body></soap:Envelope>",
		LAST);

	web_revert_auto_header("Cache-Control");

	web_revert_auto_header("FormLoadId");

	web_revert_auto_header("ReferrerReqId");

	web_revert_auto_header("SOAPAction");

/*Correlation comment: Automatic rules - Do not change!  
Original value='34887912-56b9-49b6-b621-b77666d4fced' 
Name ='CorrelationParameter_40' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_40",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"RequestUrl=*/PresenceService.asmx*",
		LAST);

	web_custom_request("PresenceService.asmx_3",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/PresenceService.asmx",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t50.inf",
		"Mode=HTML",
		"EncType=text/xml; charset=utf-8",
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><QuerySipInfo xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><entityListXml>&#60;grid&#62;&#60;row oid&#61;&#34;&#38;&#35;123&#59;{ClientOid}&#38;&#35;125&#59;&#34; otype&#61;&#34;2&#34;&#47;&#62;&#60;&#47;grid&#62;</entityListXml></QuerySipInfo></soap:Body></soap:Envelope>",
		LAST);

	lr_save_string(lr_eval_string("{CorrelationParameter_2128}"), "path2");

	crmwrpctokencase();

	lr_save_string(lr_eval_string("{path2}"), "path3");

	/*lr_output_message ("path is %s", lr_eval_string("{path4}"));
	lr_save_string("\\", "separators");
	
	// Get the first token
   	token = (char *)strtok(lr_eval_string("{path4}"), lr_eval_string("{separators}"));
   
    lr_output_message ("token is %s", token);
    
    strcat(crmwrpctoken5, token);
    	  
    lr_output_message ("fullpath is %s", crmwrpctoken5);
    
    if (!token) 
	    {
	        
	    	lr_save_string("token", "crmwrpctoken5");
	        lr_output_message ("No tokens found in string!");
	        lr_output_message ("Full path of file is %s", crmwrpctoken5);
	        //return( -1 );
	    }
	
    else{
			    // While valid tokens are returned
			    do      
				    {    	    
  	    
						lr_output_message ("Full path of file is %s", crmwrpctoken5);			
				        lr_output_message ("%s", token );
				      // Get the next token
				        token = (char *)strtok(NULL, separators);
				        lr_output_message ("%s", token );
				        if(token != NULL)
				        {
				        	lr_output_message ("%s", token );
							//strcat(crmwrpctoken6, "+");
							
							//lr_save_string(token, "crmwrpctoken3");
							//token = lr_eval_string("{crmwrpctoken3}") + 3;
							strcat(crmwrpctoken5, token);
							lr_output_message ("Full path of file is %s", crmwrpctoken5);
				        }
				}while (token != NULL );
			    
    	}

    lr_output_message ("Full path of file is %s", crmwrpctoken5);
   	 	
	lr_save_string(crmwrpctoken5, "path4");*/

	lr_save_string(lr_eval_string("{CorrelationParameter_2129}"), "path2");
		
	crmwrpctokencase();

	lr_save_string(lr_eval_string("{path2}"),"path4");

	/*lr_output_message ("path is %s", lr_eval_string("{path5}"));
	lr_save_string("\\", "separators");
	
	// Get the first token
   	token = (char *)strtok(lr_eval_string("{path5}"), lr_eval_string("{separators}"));
   
    lr_output_message ("token is %s", token);
    
    strcat(crmwrpctoken6, token);
    	  
    lr_output_message ("fullpath is %s", crmwrpctoken6);
    
    if (!token) 
	    {
	        
	    	lr_save_string("token", "crmwrpctoken6");
	        lr_output_message ("No tokens found in string!");
	        lr_output_message ("Full path of file is %s", crmwrpctoken6);
	        //return( -1 );
	    }
	
    else{
			    // While valid tokens are returned
			    do      
				    {    	    
						lr_output_message ("Full path of file is %s", crmwrpctoken6);			
				        lr_output_message ("%s", token );
				      // Get the next token
				        token = (char *)strtok(NULL, separators);
				        lr_output_message ("%s", token );
				        if(token != NULL)
				        {
				        	lr_output_message ("%s", token );
							//strcat(crmwrpctoken6, "+");
							
							//lr_save_string(token, "crmwrpctoken3");
							//token = lr_eval_string("{crmwrpctoken3}") + 3;
							strcat(crmwrpctoken6, token);
							lr_output_message ("Full path of file is %s", crmwrpctoken6);							
						}
									    	    
				}while (token != NULL );
			    
    	}

    lr_output_message ("Full path of file is %s", crmwrpctoken6);
   	 	
	lr_save_string(crmwrpctoken6, "path5");*/

	web_add_header("CRMWRPCToken", 
		lr_eval_string("{path4}"));

	web_add_auto_header("CRMWRPCTokenTimeStamp",
		"{CorrelationParameter_53}");

	web_add_auto_header("Cache-Control", 
		"no-cache");

	web_add_auto_header("FormLoadId", 
		"{90e54e86-12d1-3a6b-32ae-82426864576d}");

	web_add_auto_header("ReferrerReqId",
		"{CorrelationParameter_36}");

	web_add_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/Execute");

/*Correlation comment: Automatic rules - Do not change!  
Original value='2eec5d39-7588-4707-b415-125158ca0c83' 
Name ='CorrelationParameter_41' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_41",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"RequestUrl=*/InlineEditWebService.asmx*",
		LAST);

	web_custom_request("InlineEditWebService.asmx",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/InlineEditWebService.asmx",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t51.inf",
		"Mode=HTML",
		"EncType=text/xml; charset=utf-8",
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><Execute xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><command>208</command><commandXml>&#60;Input&#62;&#60;id&#62;&#38;&#35;123&#59;{ClientOid}&#38;&#35;125&#59;&#60;&#47;id&#62;&#60;name&#62;contact&#60;&#47;name&#62;&#60;formId&#62;959892a7-a898-44ed-83ca-63e7ce1850d4&#60;&#47;formId&#62;&#60;processId&#62;{process}&#60;&#47;processId&#62;&#60;businessProcessInstanceId&#62;00000000-0000-0000-0000-000000000000&#60;&#47;businessProcessInstanceId&#62;&#60;&#47;Input&#62;</commandXml><encodeValues>false</encodeValues></Execute></soap:Body></soap:Envelope>",
		LAST);

	web_add_auto_header("CRMWRPCToken", 
		lr_eval_string("{path3}"));

/*Correlation comment: Automatic rules - Do not change!  
Original value='aca9550e-0986-4ef0-b445-419ae19e0636' 
Name ='CorrelationParameter_42' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_42",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		LAST);

	web_custom_request("AppGridWebService.ashx_5",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/AppGridWebService.ashx?operation=Refresh",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t52.inf",
		"Mode=HTML",
		"EncType=text/plain;charset=UTF-8",
		"Body=<grid><sortColumns>record2roleid&#58;1</sortColumns><pageNum>1</pageNum><recsPerPage>10</recsPerPage><dataProvider>Microsoft.Crm.Application.Platform.Grid.GridDataProviderQueryBuilder</dataProvider><uiProvider>Microsoft.Crm.Application.Controls.GridUIProvider</uiProvider><cols/><max>1</max><refreshAsync>True</refreshAsync><pagingCookie/><enableMultiSort>true</enableMultiSort><enablePagingWhenOnePage>true</enablePagingWhenOnePage><refreshCalledFromRefreshButton>1</refreshCalledFromRefreshButton><returntotalrecordcount>true</returntotalrecordcount><getParameters>getFetchXmlForFilters</getParameters><parameters><viewid>&#123;BED5F444-0BD0-E711-A826-000D3AE0A6CF&#125;</viewid><RenderAsync>0</RenderAsync><LoadOnDemand>1</LoadOnDemand><autorefresh>1</autorefresh><isGridHidden>false</isGridHidden><LayoutStyle>LiteGridList</LayoutStyle><maxselectableitems>1</maxselectableitems><isGridFilteringEnabled>1</isGridFilteringEnabled><viewtype>1039</viewtype><viewts>3142864</viewts><RecordsPerPage>10</RecordsPerPage><v"
		"iewTitle>Connections - Personal connections on Case</viewTitle><layoutXml>&#60;grid name&#61;&#34;resultset&#34; jump&#61;&#34;name&#34; select&#61;&#34;1&#34; preview&#61;&#34;1&#34; icon&#61;&#34;1&#34; object&#61;&#34;3234&#34;&#62;&#60;row id&#61;&#34;connectionid&#34; name&#61;&#34;result&#34;&#62;&#60;cell name&#61;&#34;record2roleid&#34; width&#61;&#34;200&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;record2id&#34; width&#61;&#34;200&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_liveswithperson&#34; width&#61;&#34;200&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_source_ofsupport&#34; width&#61;&#34;150&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &"
		"#47;&#62;&#60;cell name&#61;&#34;dhhs_accesscustodydetails&#34; width&#61;&#34;200&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;effectivestart&#34; width&#61;&#34;150&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;effectiveend&#34; width&#61;&#34;150&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;&#47;row&#62;&#60;&#47;grid&#62;</layoutXml><otc>3234</otc><otn>connection</otn><entitydisplayname>Connection</entitydisplayname><titleformat>&#123;0&#125; &#123;1&#125;</titleformat><entitypluraldisplayname>Connections</entitypluraldisplayname><expandable>1</expandable><showjumpbar>0</showjumpbar><maxrowsbeforescroll>12</maxrowsbeforescroll><tabindex>10</tabindex><refreshasynchronous>1</refreshasynchronous><subgridAutoExpand>0</subgridAutoExpand><relName"
		">contact_connections1</relName><roleOrd>-1</roleOrd><oType>2</oType><relationshipType>1</relationshipType><ribbonContext>SubGridStandard</ribbonContext><GridType>SubGrid</GridType><enableContextualActions>true</enableContextualActions><teamTemplateId></teamTemplateId><isWorkflowSupported>true</isWorkflowSupported><LoadOnDemand_GridEmptyMessage>To load &#123;0&#125; records, click here.</LoadOnDemand_GridEmptyMessage><enableFilters></enableFilters><InnerGridDisabled>0</InnerGridDisabled><oId>&#123;{ClientOid}&#125;</oId><isTurboForm>1</isTurboForm></parameters><columns><column width=\"200\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Role&#32;&#40;To&#41;\" fieldname=\"record2roleid\" entityname=\"connection\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Lookup\" sourcetype=\"0\">record2roleid</column><column width=\"200\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Connected&#32;to\" fieldname=\"record2id\" entityn"
		"ame=\"connection\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Lookup.connection\" sourcetype=\"0\">record2id</column><column width=\"200\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Lives&#32;with&#32;person\" fieldname=\"dhhs_liveswithperson\" entityname=\"connection\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">dhhs_liveswithperson</column><column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Source&#32;of&#32;support\" fieldname=\"dhhs_source_ofsupport\" entityname=\"connection\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Picklist\" sourcetype=\"0\">dhhs_source_ofsupport</column><column width=\"200\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Access&#47;Custody&#32;details\" fieldname=\"dhhs_accesscustodydetails\" entityname=\"connection\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">dhhs_ac"
		"cesscustodydetails</column><column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Start&#32;date\" fieldname=\"effectivestart\" entityname=\"connection\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"DateTime.date\" sourcetype=\"0\">effectivestart</column><column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"End&#32;date\" fieldname=\"effectiveend\" entityname=\"connection\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"DateTime.date\" sourcetype=\"0\">effectiveend</column></columns></grid>",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='3f71e2d9-31ea-4281-9dda-ad74e32c1ee5' 
Name ='CorrelationParameter_43' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_43",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		LAST);

	web_custom_request("AppGridWebService.ashx_6",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/AppGridWebService.ashx?operation=Refresh",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t53.inf",
		"Mode=HTML",
		"EncType=text/plain;charset=UTF-8",
		"Body=<grid><sortColumns>dhhs_name&#58;1</sortColumns><pageNum>1</pageNum><recsPerPage>10</recsPerPage><dataProvider>Microsoft.Crm.Application.Platform.Grid.GridDataProviderQueryBuilder</dataProvider><uiProvider>Microsoft.Crm.Application.Controls.GridUIProvider</uiProvider><cols/><max>1</max><refreshAsync>True</refreshAsync><pagingCookie/><enableMultiSort>true</enableMultiSort><enablePagingWhenOnePage>true</enablePagingWhenOnePage><refreshCalledFromRefreshButton>1</refreshCalledFromRefreshButton><returntotalrecordcount>true</returntotalrecordcount><getParameters>getFetchXmlForFilters</getParameters><parameters><viewid>&#123;F271F05E-2DD3-E711-A825-000D3AE0CB84&#125;</viewid><RenderAsync>0</RenderAsync><LoadOnDemand>1</LoadOnDemand><autorefresh>1</autorefresh><isGridHidden>false</isGridHidden><LayoutStyle>LiteGridList</LayoutStyle><maxselectableitems>1</maxselectableitems><isGridFilteringEnabled>1</isGridFilteringEnabled><viewtype>1039</viewtype><viewts>3142978</viewts><RecordsPerPage>10</RecordsPerPage><viewT"
		"itle>Alerts on Case</viewTitle><layoutXml>&#60;grid name&#61;&#34;resultset&#34; jump&#61;&#34;dhhs_name&#34; select&#61;&#34;1&#34; preview&#61;&#34;1&#34; icon&#61;&#34;1&#34; object&#61;&#34;10213&#34;&#62;&#60;row name&#61;&#34;result&#34; id&#61;&#34;dhhs_alertid&#34;&#62;&#60;cell name&#61;&#34;createdon&#34; width&#61;&#34;150&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_name&#34; width&#61;&#34;300&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_type&#34; width&#61;&#34;200&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_enddate&#34; width&#61;&#34;125&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;statuscode&#34; w"
		"idth&#61;&#34;100&#34; &#47;&#62;&#60;cell name&#61;&#34;ownerid&#34; width&#61;&#34;200&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;&#47;row&#62;&#60;&#47;grid&#62;</layoutXml><otc>10213</otc><otn>dhhs_alert</otn><entitydisplayname>Alert</entitydisplayname><titleformat>&#123;0&#125; &#123;1&#125;</titleformat><entitypluraldisplayname>Alerts</entitypluraldisplayname><expandable>1</expandable><showjumpbar>0</showjumpbar><maxrowsbeforescroll>12</maxrowsbeforescroll><tabindex>10</tabindex><refreshasynchronous>1</refreshasynchronous><subgridAutoExpand>0</subgridAutoExpand><relName>dhhs_contact_dhhs_alert_PersonorClient</relName><roleOrd>-1</roleOrd><oType>2</oType><relationshipType>1</relationshipType><ribbonContext>SubGridStandard</ribbonContext><GridType>SubGrid</GridType><enableContextualActions>true</enableContextualActions><teamTemplateId></teamTemplateId><isWorkflowSupported>true</isWorkflowSupported><LoadOnDemand_GridEmptyMessa"
		"ge>To load &#123;0&#125; records, click here.</LoadOnDemand_GridEmptyMessage><enableFilters></enableFilters><InnerGridDisabled>0</InnerGridDisabled><oId>&#123;{ClientOid}&#125;</oId><isTurboForm>1</isTurboForm></parameters><columns><column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Created&#32;on\" fieldname=\"createdon\" entityname=\"dhhs_alert\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"DateTime.datetime\" sourcetype=\"0\">createdon</column><column width=\"300\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Subject\" fieldname=\"dhhs_name\" entityname=\"dhhs_alert\" renderertype=\"Crm.PrimaryField\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">dhhs_name</column><column width=\"200\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Type\" fieldname=\"dhhs_type\" entityname=\"dhhs_alert\" imageproviderwebresource=\"&#36;webresource&#"
		"58;\" type=\"Picklist\" sourcetype=\"0\">dhhs_type</column><column width=\"125\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"End&#32;date\" fieldname=\"dhhs_enddate\" entityname=\"dhhs_alert\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"DateTime.date\" sourcetype=\"0\">dhhs_enddate</column><column width=\"100\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Status\" fieldname=\"statuscode\" entityname=\"dhhs_alert\" type=\"Status\" sourcetype=\"0\">statuscode</column><column width=\"200\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Owner\" fieldname=\"ownerid\" entityname=\"dhhs_alert\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Owner\" sourcetype=\"0\">ownerid</column></columns></grid>",
		LAST);

	web_add_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/Execute");

	web_revert_auto_header("CRMWRPCToken");

	web_add_header("CRMWRPCToken", 
		lr_eval_string("{path4}"));

/*Correlation comment: Automatic rules - Do not change!  
Original value='c1f247e5-f8ee-4381-b2d0-850aea7b8d3a' 
Name ='CorrelationParameter_44' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_44",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		LAST);

	web_custom_request("InlineEditWebService.asmx_2",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/InlineEditWebService.asmx",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t54.inf",
		"Mode=HTML",
		"EncType=text/xml; charset=utf-8",
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><Execute xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><command>208</command><commandXml>&#60;Input&#62;&#60;id&#62;&#38;&#35;123&#59;{ClientOid}&#38;&#35;125&#59;&#60;&#47;id&#62;&#60;name&#62;contact&#60;&#47;name&#62;&#60;formId&#62;8aaf6a61-a29d-4936-8f85-7dac32ed81d8&#60;&#47;formId&#62;&#60;processId&#62;{process}&#60;&#47;processId&#62;&#60;businessProcessInstanceId&#62;00000000-0000-0000-0000-000000000000&#60;&#47;businessProcessInstanceId&#62;&#60;&#47;Input&#62;</commandXml><encodeValues>false</encodeValues></Execute></soap:Body></soap:Envelope>",
		LAST);

	lr_end_transaction("CRM_06_CreateCase_04_EnterDetails1",LR_AUTO);

	lr_think_time(5);

	web_revert_auto_header("CRMWRPCTokenTimeStamp");

	web_revert_auto_header("Cache-Control");

	web_revert_auto_header("FormLoadId");

	web_revert_auto_header("ReferrerReqId");

	web_add_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/RetrieveInlineSearchResults");

	web_add_auto_header("Cache-Control", 
		"no-cache");

	web_add_auto_header("FormLoadId", 
		"{90e54e86-12d1-3a6b-32ae-82426864576d}");

	web_add_auto_header("ReferrerReqId",
		"{CorrelationParameter_36}");

/*Correlation comment: Automatic rules - Do not change!  
Original value='e67aac4a-027d-498f-bb67-fe86f1c3b83e' 
Name ='CorrelationParameter_45' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_45",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"RequestUrl=*/LookupService.asmx*",
		LAST);

	//oid="{604E0069-F036-E811-A832-000D3AE0A6CF}" oname="PerfTestGrp 
	web_reg_save_param("GroupOid","LB=oid=\"{","RB=}\" oname=\"",LAST);

	lr_start_transaction("CRM_06_CreateCase_05_EnterDetails2");

	web_custom_request("LookupService.asmx_4",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/LookupService.asmx",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t55.inf",
		"Mode=HTML",
		"EncType=text/xml; charset=utf-8",
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><RetrieveInlineSearchResults xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><typesArray><int>10217</int></typesArray><bindingColumns></bindingColumns><additionalParameters>&#38;IsInlineLookup&#61;true&#38;customFilter&#61;&#38;customFilterTypes&#61;</additionalParameters><positions><int>0</int></positions><resolveEmailAddress>false</resolveEmailAddress><sortResults>true</sortResults><lookupValues><string>{param_GroupName}{param_PerfGroupNumber}</string></lookupValues><defaultViewId>&#123;F27E13B6-7410-4695-9EB2-A3D7F041D981&#125;</defaultViewId></RetrieveInlineSearchResults></soap:Body></soap:Envelope>",
		LAST);

	web_add_header("CRMWRPCToken", 
		lr_eval_string("{path4}"));

	web_add_auto_header("CRMWRPCTokenTimeStamp",
		"{CorrelationParameter_53}");

	web_add_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/Execute");

/*Correlation comment: Automatic rules - Do not change!  
Original value='8f89c4c2-71dc-4964-bf0d-908e5e5617c8' 
Name ='CorrelationParameter_46' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_46",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		LAST);

	web_custom_request("InlineEditWebService.asmx_3",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/InlineEditWebService.asmx",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t56.inf",
		"Mode=HTML",
		"EncType=text/xml; charset=utf-8",
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><Execute xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><command>208</command><commandXml>&#60;Input&#62;&#60;id&#62;&#38;&#35;123&#59;{GroupOid}&#38;&#35;125&#59;&#60;&#47;id&#62;&#60;name&#62;dhhs_casegroup&#60;&#47;name&#62;&#60;formId&#62;0b8dc4ed-c769-4501-968c-df4024c3a9de&#60;&#47;formId&#62;&#60;processId&#62;{process}&#60;&#47;processId&#62;&#60;businessProcessInstanceId&#62;00000000-0000-0000-0000-000000000000&#60;&#47;businessProcessInstanceId&#62;&#60;&#47;Input&#62;</commandXml><encodeValues>false</encodeValues></Execute></soap:Body></soap:Envelope>",
		LAST);

	web_add_header("CRMWRPCToken", 
		lr_eval_string("{path3}"));

/*Correlation comment: Automatic rules - Do not change!  
Original value='a85a8385-4d9c-4c43-8846-d9da844c4019' 
Name ='CorrelationParameter_47' 
Type ='Rule' 
AppName ='HubCRM' 
RuleName ='Requestid'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_47",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		LAST);

	web_custom_request("AppGridWebService.ashx_7",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/AppGridWebService.ashx?operation=Refresh",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t57.inf",
		"Mode=HTML",
		"EncType=text/plain;charset=UTF-8",
		"Body=<grid><sortColumns>title&#58;1</sortColumns><pageNum>1</pageNum><recsPerPage>10</recsPerPage><dataProvider>Microsoft.Crm.Application.Platform.Grid.GridDataProviderQueryBuilder</dataProvider><uiProvider>Microsoft.Crm.Application.Controls.GridUIProvider</uiProvider><cols/><max>1</max><refreshAsync>True</refreshAsync><pagingCookie/><enableMultiSort>true</enableMultiSort><enablePagingWhenOnePage>true</enablePagingWhenOnePage><refreshCalledFromRefreshButton>1</refreshCalledFromRefreshButton><returntotalrecordcount>true</returntotalrecordcount><getParameters>getFetchXmlForFilters</getParameters><parameters><viewid>&#123;20C1857E-BCBE-E711-814B-E0071B6D9931&#125;</viewid><RenderAsync>0</RenderAsync><LoadOnDemand>1</LoadOnDemand><autorefresh>1</autorefresh><isGridHidden>false</isGridHidden><LayoutStyle>LiteGridList</LayoutStyle><maxselectableitems>1</maxselectableitems><isGridFilteringEnabled>1</isGridFilteringEnabled><viewtype>1039</viewtype><viewts>3144117</viewts><RecordsPerPage>10</RecordsPerPage><viewTitle"
		">Main Clients</viewTitle><layoutXml>&#60;grid name&#61;&#34;resultset&#34; jump&#61;&#34;title&#34; select&#61;&#34;1&#34; preview&#61;&#34;1&#34; icon&#61;&#34;1&#34; object&#61;&#34;112&#34;&#62;&#60;row name&#61;&#34;result&#34; id&#61;&#34;incidentid&#34;&#62;&#60;cell name&#61;&#34;customerid&#34; width&#61;&#34;200&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;title&#34; width&#61;&#34;200&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;&#47;row&#62;&#60;&#47;grid&#62;</layoutXml><otc>112</otc><otn>incident</otn><entitydisplayname>Case</entitydisplayname><titleformat>&#123;0&#125; &#123;1&#125;</titleformat><entitypluraldisplayname>Cases</entitypluraldisplayname><expandable>1</expandable><showjumpbar>0</showjumpbar><maxrowsbeforescroll>12</maxrowsbeforescroll><tabindex>30</tabindex><refreshasynchronous>1</refreshasynchronous><subgridAu"
		"toExpand>0</subgridAutoExpand><relName>dhhs_casegroup_incident_Casegroupsid</relName><roleOrd>-1</roleOrd><oType>10217</oType><relationshipType>1</relationshipType><ribbonContext>SubGridStandard</ribbonContext><GridType>SubGrid</GridType><enableContextualActions>true</enableContextualActions><teamTemplateId></teamTemplateId><isWorkflowSupported>true</isWorkflowSupported><LoadOnDemand_GridEmptyMessage>To load &#123;0&#125; records, click here.</LoadOnDemand_GridEmptyMessage><enableFilters></enableFilters><InnerGridDisabled>0</InnerGridDisabled><oId>&#123;{GroupOid}&#125;</oId><isTurboForm>1</isTurboForm></parameters><columns><column width=\"200\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Client\" fieldname=\"customerid\" entityname=\"incident\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Customer\" sourcetype=\"0\">customerid</column><column width=\"200\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Case&#32;titl"
		"e\" fieldname=\"title\" entityname=\"incident\" renderertype=\"Crm.PrimaryField\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">title</column></columns></grid>",
		LAST);

	lr_end_transaction("CRM_06_CreateCase_05_EnterDetails2",LR_AUTO);

	lr_think_time(5);

	web_revert_auto_header("CRMWRPCTokenTimeStamp");

	web_revert_auto_header("FormLoadId");

	web_revert_auto_header("ReferrerReqId");

/*	web_add_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_custom_request("Report",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/MetricsReportingService.asmx/Report",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t58.inf",
		"Mode=HTML",
		"EncType=application/json; charset=utf-8",
		"Body={\"request\":{\"MetricsCollections\":[{\"RequestId\":\"{CorrelationParameter_11}\",\"Metrics\":[{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522024827145,\"p\":{\"browserTimestamp\":1522024815457,\"componentId\":\"main.aspx\",\"componentInfo\":\"precise\",\"marker\":\"loadStart\",\"navigation\":0,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522024827145,\"p\":{\"browserTimestamp\":1522024819720,\"componentId\":\"main.aspx\",\"componentInfo\":\"\",\"marker\":\"responseStart\",\"navigation\":0,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522024827145,\"p\":{\"browserTimestamp\":1522024819726,\"componentId\":\"main.aspx\",\"componentInfo\":\"\",\"marker\":\"responseEnd\",\"navigation\":0,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522024827146,\"p\":{\"browserTimestamp\":1522024827145,\"componentId\":\"main.aspx\",\"componentInfo\":\"\",\"ma"
		"rker\":\"loaded\",\"navigation\":0,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"pagenavigations\",\"v\":null,\"t\":1522024827291,\"p\":{\"navigatedAt\":\"\\/Date(1522024827291)\\/\",\"navigationCounter\":1,\"navigationUri\":\"/workplace/home_dashboards.aspx?sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642\",\"tabSessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522024827291,\"p\":{\"browserTimestamp\":\"\\/Date(1522024827291)\\/\",\"componentId\":\"pagenavigations\",\"componentInfo\":\"/workplace/home_dashboards.aspx?sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642\",\"marker\":\"navigationStart\",\"navigation\":1,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522024827321,\"p\":{\"browserTimestamp\":\"\\/Date(1522024827321)\\/\",\"componentId\":\"pagenavigations\",\"componentInfo\":\"/workplace/home_dashboards.aspx?sitemappath=NewArea_6370afe4%7cgroup"
		"_myWork%7cNewSubArea_cb6d1642\",\"marker\":\"navigationEnd\",\"navigation\":1,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"RemoteCommand.Execute\",\"v\":5187,\"t\":1522024829231,\"p\":{\"IsAsync\":true,\"Service\":\"MessageBar\",\"ReqId\":\"{CorrelationParameter_15}\"}},{\"n\":\"RemoteCommand.Execute\",\"v\":4930,\"t\":1522024829490,\"p\":{\"IsAsync\":true,\"Service\":\"RecentlyViewedWebService\",\"ReqId\":\"{CorrelationParameter_18}\"}},{\"n\":\"pagenavigations\",\"v\":null,\"t\":1522024903241,\"p\":{\"navigatedAt\":\"\\/Date(1522024903241)\\/\",\"navigationCounter\":2,\"navigationUri\":\"/_root/homepage.aspx?etc=112&sitemappath=area_service%7cPeople%7cNewSubArea_b823cecf&viewid=%7b00000000-0000-0000-00AA-000010001032%7d\",\"tabSessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522024903241,\"p\":{\"browserTimestamp\":\"\\/Date(1522024903241)\\/\",\"componentId\":\"pagenavigations\",\"componentInfo\":\"/_root/homepage.aspx?etc=112&sitemap"
		"path=area_service%7cPeople%7cNewSubArea_b823cecf&viewid=%7b00000000-0000-0000-00AA-000010001032%7d\",\"marker\":\"navigationStart\",\"navigation\":2,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522024903289,\"p\":{\"browserTimestamp\":\"\\/Date(1522024903289)\\/\",\"componentId\":\"pagenavigations\",\"componentInfo\":\"/_root/homepage.aspx?etc=112&sitemappath=area_service%7cPeople%7cNewSubArea_b823cecf&viewid=%7b00000000-0000-0000-00AA-000010001032%7d\",\"marker\":\"navigationEnd\",\"navigation\":2,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"pagenavigations\",\"v\":null,\"t\":1522024938096,\"p\":{\"navigatedAt\":\"\\/Date(1522024938096)\\/\",\"navigationCounter\":3,\"navigationUri\":\"/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&etc=112&extraqs=%3fetc%3d112&pagetype=entityrecord\",\"tabSessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522024938096,\"p\":{\"browserTimestamp"
		"\":\"\\/Date(1522024938096)\\/\",\"componentId\":\"pagenavigations\",\"componentInfo\":\"/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&etc=112&extraqs=%3fetc%3d112&pagetype=entityrecord\",\"marker\":\"navigationStart\",\"navigation\":3,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"Update ProcessId From Local Storage\",\"v\":1,\"t\":1522024938100,\"p\":{}},{\"n\":\"Send Form Data Request\",\"v\":3,\"t\":1522024938102,\"p\":{}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522024938143,\"p\":{\"browserTimestamp\":\"\\/Date(1522024938143)\\/\",\"componentId\":\"pagenavigations\",\"componentInfo\":\"/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&etc=112&extraqs=%3fetc%3d112&pagetype=entityrecord\",\"marker\":\"navigationEnd\",\"navigation\":3,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"RemoteCommand.Execute\",\"v\":32,\"t\":1522024939141,\"p\":{\"IsAsync\":false,\"Service\":\"ResourceManager\",\"ReqId\":\"{CorrelationParameter_27}\"}},{\"n\":\"RemoteCommand"
		".Execute\",\"v\":30,\"t\":1522024939173,\"p\":{\"IsAsync\":false,\"Service\":\"ResourceManager\",\"ReqId\":\"{CorrelationParameter_28}\"}},{\"n\":\"RemoteCommand.Execute\",\"v\":91,\"t\":1522024939204,\"p\":{\"IsAsync\":false,\"Service\":\"ResourceManager\",\"ReqId\":\"{CorrelationParameter_29}\"}},{\"n\":\"RemoteCommand.Execute\",\"v\":29,\"t\":1522024939295,\"p\":{\"IsAsync\":false,\"Service\":\"ResourceManager\",\"ReqId\":\"{CorrelationParameter_30}\"}},{\"n\":\"RemoteCommand.Execute\",\"v\":29,\"t\":1522024939325,\"p\":{\"IsAsync\":false,\"Service\":\"ResourceManager\",\"ReqId\":\"{CorrelationParameter_31}\"}},{\"n\":\"RemoteCommand.Execute\",\"v\":29,\"t\":1522024939354,\"p\":{\"IsAsync\":false,\"Service\":\"ResourceManager\",\"ReqId\":\"{CorrelationParameter_32}\"}},{\"n\":\"RemoteCommand.Execute\",\"v\":29,\"t\":1522024939384,\"p\":{\"IsAsync\":false,\"Service\":\"ResourceManager\",\"ReqId\":\"{CorrelationParameter_33}\"}},{\"n\":\"Refresh Ribbon\",\"v\":9,\"t\":1522024941822,\"p\":{}},{\"n\":\"pagen"
		"avigations\",\"v\":null,\"t\":1522024942875,\"p\":{\"navigatedAt\":\"\\/Date(1522024942875)\\/\",\"navigationCounter\":4,\"navigationUri\":\"/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&etc=112&extraqs=%3fetc%3d112%26formid%3d{formid}&pagetype=entityrecord\",\"tabSessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522024942876,\"p\":{\"browserTimestamp\":\"\\/Date(1522024942876)\\/\",\"componentId\":\"pagenavigations\",\"componentInfo\":\"/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&etc=112&extraqs=%3fetc%3d112%26formid%3d{formid}&pagetype=entityrecord\",\"marker\":\"navigationStart\",\"navigation\":4,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"Update ProcessId From Local Storage\",\"v\":0,\"t\":1522024942879,\"p\":{}},{\"n\":\"Send Form Data Request\",\"v\":2,\"t\":1522024942879,\"p\":{}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522024942996,\"p\":{\"browserTimestamp\":\"\\/Date(1522024942996)\\/\",\"componentId\":\"p"
		"agenavigations\",\"componentInfo\":\"/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&etc=112&extraqs=%3fetc%3d112%26formid%3d{formid}&pagetype=entityrecord\",\"marker\":\"navigationEnd\",\"navigation\":4,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"Layout Variable Includes\",\"v\":5,\"t\":1522024943998,\"p\":{}},{\"n\":\"Inject Layout Includes to Page\",\"v\":24,\"t\":1522024943979,\"p\":{}},{\"n\":\"Render Form Layout\",\"v\":92,\"t\":1522024944004,\"p\":{}},{\"n\":\"Initialize Application Components\",\"v\":34,\"t\":1522024944097,\"p\":{}},{\"n\":\"Process Form Layout\",\"v\":153,\"t\":1522024943978,\"p\":{}},{\"n\":\"Load Form\",\"v\":749,\"t\":1522024943388,\"p\":{}},{\"n\":\"Build Page View Model\",\"v\":15,\"t\":1522024944219,\"p\":{}},{\"n\":\"Build Page Views\",\"v\":6,\"t\":1522024944234,\"p\":{}},{\"n\":\"Initialize Xrm Controls and Data\",\"v\":44,\"t\":1522024944218,\"p\":{}},{\"n\":\"Build Page View Model\",\"v\":0,\"t\":1522024944263,\"p\":{}},{\"n\":\"Build Page Vie"
		"ws\",\"v\":0,\"t\":1522024944264,\"p\":{}},{\"n\":\"Build Page View Model\",\"v\":1,\"t\":1522024944266,\"p\":{}},{\"n\":\"Build Page Views\",\"v\":0,\"t\":1522024944267,\"p\":{}},{\"n\":\"Build Page View Model\",\"v\":1,\"t\":1522024944270,\"p\":{}},{\"n\":\"Build Page Views\",\"v\":0,\"t\":1522024944271,\"p\":{}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024944371,\"p\":{\"apiName\":\"Xrm.Page.data.entity.getEntityReference\",\"client\":\"Web\",\"isDeprecating\":false,\"userId\":\"{{userguid}}\"}},{\"n\":\"ActivityFeeds_LoadHtml\",\"v\":0,\"t\":1522024944371,\"p\":{}},{\"n\":\"AF_Render_Template\",\"v\":10,\"t\":1522024944372,\"p\":{}},{\"n\":\"TextAreaMaxLength\",\"v\":1,\"t\":1522024944384,\"p\":{}},{\"n\":\"TextAreaAutoResize\",\"v\":11,\"t\":1522024944386,\"p\":{}},{\"n\":\"ElementWatermark\",\"v\":1,\"t\":1522024944397,\"p\":{}},{\"n\":\"Wall_SetProgressState\",\"v\":2,\"t\":1522024944400,\"p\":{}},{\"n\":\"TextAreaMentions\",\"v\":0,\"t\":1522024944402,\"p\":{}},{\"n\":\"AF"
		"_WallHtml_Render\",\"v\":35,\"t\":1522024944372,\"p\":{}},{\"n\":\"Bind SFA Tabs\",\"v\":42,\"t\":1522024944367,\"p\":{}},{\"n\":\"Bind Xrm to HTML\",\"v\":148,\"t\":1522024944262,\"p\":{}},{\"n\":\"ProcessControl.ControlDataService.InitializeWorkflowStep\",\"v\":3,\"t\":1522024944410,\"p\":{}},{\"n\":\"ProcessControl.ControlDataService.InitializeBpfVisitor\",\"v\":0,\"t\":1522024944414,\"p\":{}},{\"n\":\"ProcessControl.ViewModel.initDataService.Building\",\"v\":4,\"t\":1522024944410,\"p\":{}},{\"n\":\"ProcessControl.View.InitializeSubViews\",\"v\":2,\"t\":1522024944415,\"p\":{}},{\"n\":\"ProcessControl.View.InitializeSlider\",\"v\":3,\"t\":1522024944427,\"p\":{}},{\"n\":\"ProcessControl.InitializeView\",\"v\":15,\"t\":1522024944415,\"p\":{}},{\"n\":\"ProcessControl.StagesView.Layout\",\"v\":2,\"t\":1522024944430,\"p\":{}},{\"n\":\"ProcessControl.StepsView.Layout\",\"v\":1,\"t\":1522024944432,\"p\":{}},{\"n\":\"ProcessControl.ActionsView.Layout\",\"v\":0,\"t\":1522024944434,\"p\":{}},{\"n\":\"ProcessControl"
		".View.Layout\",\"v\":4,\"t\":1522024944430,\"p\":{}},{\"n\":\"ProcessControl.ProcessLayout\",\"v\":24,\"t\":1522024944410,\"p\":{}},{\"n\":\"ProcessControl.InitializePageObjects\",\"v\":0,\"t\":1522024944435,\"p\":{}},{\"n\":\"InitializeProcessControl\",\"v\":25,\"t\":1522024944410,\"p\":{}},{\"n\":\"OnLayoutReady handlers\",\"v\":0,\"t\":1522024944435,\"p\":{}},{\"n\":\"Script Frame OnLoad\",\"v\":27,\"t\":1522024944472,\"p\":{}},{\"n\":\"RemoteCommand.Execute\",\"v\":1990,\"t\":1522024942554,\"p\":{\"IsAsync\":true,\"Service\":\"PresenceService\",\"ReqId\":\"{CorrelationParameter_34}\"}},{\"n\":\"RemoteCommand.Execute\",\"v\":1909,\"t\":1522024942637,\"p\":{\"IsAsync\":true,\"Service\":\"LookupService\",\"ReqId\":\"{CorrelationParameter_35}\"}},{\"n\":\"Waiting for data ready before BindData\",\"v\":118,\"t\":1522024944435,\"p\":{}},{\"n\":\"Waiting for layout ready before BindData\",\"v\":0,\"t\":1522024944554,\"p\":{}},{\"n\":\"Process Cached Layout\",\"v\":4,\"t\":1522024944554,\"p\":{}},{\"n\":\"Refre"
		"sh Ribbon\",\"v\":68,\"t\":1522024945077,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":93,\"t\":1522024945794,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":75,\"t\":1522024946788,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":78,\"t\":1522024947776,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":79,\"t\":1522024948787,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":75,\"t\":1522024949785,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":79,\"t\":1522024950779,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":83,\"t\":1522024951779,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":78,\"t\":1522024952777,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":79,\"t\":1522024953784,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522024954779,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":91,\"t\":1522024955784,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522024956788,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":59,\"t\":1522024957779,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":80,\"t\":1522024958782,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":86,\"t\":1522024959791,\"p\":"
		"{}},{\"n\":\"Refresh Ribbon\",\"v\":77,\"t\":1522024960778,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":78,\"t\":1522024961777,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":83,\"t\":1522024962819,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":75,\"t\":1522024963773,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":85,\"t\":1522024964795,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":75,\"t\":1522024965783,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":79,\"t\":1522024966785,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":83,\"t\":1522024967779,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":65,\"t\":1522024968778,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":80,\"t\":1522024969784,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522024970779,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":85,\"t\":1522024971785,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":95,\"t\":1522024972782,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":78,\"t\":1522024973777,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":77,\"t\":1522024974779,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":77,\"t\":15"
		"22024975786,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522024976809,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":85,\"t\":1522024977784,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":59,\"t\":1522024978798,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":61,\"t\":1522024979787,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":67,\"t\":1522024980778,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":67,\"t\":1522024981776,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522024982788,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522024983787,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":74,\"t\":1522024984785,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":60,\"t\":1522024985803,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":69,\"t\":1522024986779,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":77,\"t\":1522024987811,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":69,\"t\":1522024988788,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":64,\"t\":1522024989786,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522024990779,\"p\":{}},{\"n\":\"Refresh Ribbon\""
		",\"v\":72,\"t\":1522024991780,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522024992783,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":67,\"t\":1522024993777,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522024994785,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":56,\"t\":1522024995815,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522024996784,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":68,\"t\":1522024997786,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522024998784,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":78,\"t\":1522024999778,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025000787,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":78,\"t\":1522025001788,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":70,\"t\":1522025002780,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":69,\"t\":1522025003785,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":69,\"t\":1522025004781,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025005790,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":68,\"t\":1522025006785,\"p\":{}},{\"n\":"
		"\"Refresh Ribbon\",\"v\":56,\"t\":1522025007797,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":75,\"t\":1522025008784,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":59,\"t\":1522025009774,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025010778,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":61,\"t\":1522025011780,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":69,\"t\":1522025012787,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025013785,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":70,\"t\":1522025014772,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":78,\"t\":1522025015772,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":67,\"t\":1522025016779,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025017775,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025018779,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025019779,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":75,\"t\":1522025020782,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025021772,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":69,\"t\":1522025022774"
		",\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025023772,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":69,\"t\":1522025024785,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025025784,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":56,\"t\":1522025026784,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":75,\"t\":1522025027775,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025028780,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522025029783,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025030772,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":70,\"t\":1522025031773,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":74,\"t\":1522025032786,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522025033776,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025034783,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":56,\"t\":1522025035800,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":55,\"t\":1522025036772,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":56,\"t\":1522025037783,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":56,"
		"\"t\":1522025038782,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":57,\"t\":1522025039798,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":55,\"t\":1522025040783,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":56,\"t\":1522025041798,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":55,\"t\":1522025042785,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":56,\"t\":1522025043796,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":60,\"t\":1522025044774,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025045780,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":74,\"t\":1522025046783,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025047772,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025048772,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":56,\"t\":1522025049773,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":57,\"t\":1522025050812,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025051781,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":67,\"t\":1522025052781,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522025053784,\"p\":{}},{\"n\":\"Refresh "
		"Ribbon\",\"v\":74,\"t\":1522025054776,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522025055781,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025056773,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025057774,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":69,\"t\":1522025058779,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":79,\"t\":1522025059778,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":57,\"t\":1522025060772,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":69,\"t\":1522025061777,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":83,\"t\":1522025062775,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":78,\"t\":1522025063772,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":56,\"t\":1522025064793,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":80,\"t\":1522025065776,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025066771,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":70,\"t\":1522025067774,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":69,\"t\":1522025068773,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":75,\"t\":1522025069787,\"p\":{}}"
		",{\"n\":\"Refresh Ribbon\",\"v\":70,\"t\":1522025070776,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025071776,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":74,\"t\":1522025072777,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025073781,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522025074784,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025075775,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":69,\"t\":1522025076778,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025077776,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025078780,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025079781,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522025080783,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":62,\"t\":1522025081790,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":69,\"t\":1522025082782,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025083777,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":70,\"t\":1522025084791,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":74,\"t\":15220"
		"25085776,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522025086781,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":77,\"t\":1522025087774,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":68,\"t\":1522025088783,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":70,\"t\":1522025089780,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025090781,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":70,\"t\":1522025091782,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":75,\"t\":1522025092783,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":81,\"t\":1522025096481,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":80,\"t\":1522025097456,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":55,\"t\":1522025098474,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":67,\"t\":1522025099430,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025100412,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":60,\"t\":1522025101386,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522025102355,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025103329,\"p\":{}},{\"n\":\"Refresh Ribbon\",\""
		"v\":78,\"t\":1522025104301,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":90,\"t\":1522025106719,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":79,\"t\":1522025107579,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":80,\"t\":1522025108558,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522025109526,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":56,\"t\":1522025110502,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025111479,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025112454,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025113424,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":75,\"t\":1522025114582,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":62,\"t\":1522025115598,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522025116545,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025117522,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025118511,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":78,\"t\":1522025119483,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025120461,\"p\":{}},{\"n\":\"R"
		"efresh Ribbon\",\"v\":75,\"t\":1522025121434,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025122409,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":78,\"t\":1522025123381,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":74,\"t\":1522025124358,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":56,\"t\":1522025125326,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":74,\"t\":1522025126304,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":56,\"t\":1522025127315,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025128262,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":75,\"t\":1522025129236,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":60,\"t\":1522025130279,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":56,\"t\":1522025131193,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025132164,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":75,\"t\":1522025133137,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025134112,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":79,\"t\":1522025135082,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":67,\"t\":1522025136060,\""
		"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025137042,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025138014,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":74,\"t\":1522025138986,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025139964,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":77,\"t\":1522025140936,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025141912,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":78,\"t\":1522025142885,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025143865,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":68,\"t\":1522025144847,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025145815,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":74,\"t\":1522025146788,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025147760,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":59,\"t\":1522025148757,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025149713,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":89,\"t\":1522025150697,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":86,\"t"
		"\":1522025152035,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025152896,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522025153868,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":69,\"t\":1522025154846,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":68,\"t\":1522025155830,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025156813,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025157824,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025158795,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025159767,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025160739,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":75,\"t\":1522025161711,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":75,\"t\":1522025162687,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":61,\"t\":1522025163674,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":66,\"t\":1522025164832,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522025165614,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":77,\"t\":1522025166616,\"p\":{}},{\"n\":\"Refresh Rib"
		"bon\",\"v\":75,\"t\":1522025167609,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":68,\"t\":1522025168615,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025169613,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":69,\"t\":1522025170616,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025171616,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":55,\"t\":1522025172617,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":74,\"t\":1522025173618,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":81,\"t\":1522025174630,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025175614,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":56,\"t\":1522025176616,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":75,\"t\":1522025177615,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":77,\"t\":1522025178616,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":75,\"t\":1522025179621,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":55,\"t\":1522025180622,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025181622,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":57,\"t\":1522025182622,\"p\":{}},{"
		"\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522025183618,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025184624,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":55,\"t\":1522025185663,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":69,\"t\":1522025186609,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025187609,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025188613,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":82,\"t\":1522025189616,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":77,\"t\":1522025190613,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":55,\"t\":1522025191620,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":74,\"t\":1522025192620,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":78,\"t\":1522025193610,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025194618,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":83,\"t\":1522025195620,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":73,\"t\":1522025196609,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":72,\"t\":1522025197613,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":56,\"t\":1522025"
		"198629,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":79,\"t\":1522025199613,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":71,\"t\":1522025200622,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":67,\"t\":1522025201610,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":82,\"t\":1522025202608,\"p\":{}},{\"n\":\"Refresh Ribbon\",\"v\":76,\"t\":1522025203606,\"p\":{}}],\"IsExistingActivity\":true},{\"RequestId\":\"{CorrelationParameter_13}\",\"Metrics\":[{\"n\":\"RemoteCommand.Execute\",\"v\":5035,\"t\":1522024829359,\"p\":{\"IsAsync\":true,\"Service\":\"DashboardWebService\",\"ReqId\":\"{CorrelationParameter_16}\"}},{\"n\":\"RemoteCommand.Execute\",\"v\":5045,\"t\":1522024829353,\"p\":{\"IsAsync\":true,\"Service\":\"DashboardWebService\",\"ReqId\":\"{CorrelationParameter_17}\"}},{\"n\":\"RemoteCommand.Execute\",\"v\":5042,\"t\":1522024829357,\"p\":{\"IsAsync\":true,\"Service\":\"DashboardWebService\",\"ReqId\":\"{CorrelationParameter_19}\"}},{\"n\":\"RemoteCommandXml.Execute\",\"v\":364,"
		"\"t\":1522024834876,\"p\":{\"IsAsync\":true,\"Service\":\"AppGridWebService\",\"ReqId\":\"{CorrelationParameter_20}\"}},{\"n\":\"SubGrid\",\"v\":511,\"t\":1522024834865,\"p\":{\"id\":\"Component376145d\",\"IsAsync\":true}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522024835377,\"p\":{\"browserTimestamp\":1522024835376,\"componentId\":\"Component376145d\",\"componentInfo\":\"\",\"marker\":\"loaded\",\"navigation\":1,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"RemoteCommandXml.Execute\",\"v\":461,\"t\":1522024834917,\"p\":{\"IsAsync\":true,\"Service\":\"AppGridWebService\",\"ReqId\":\"{CorrelationParameter_21}\"}},{\"n\":\"SubGrid\",\"v\":505,\"t\":1522024834911,\"p\":{\"id\":\"Componenta3058e5\",\"IsAsync\":true}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522024835416,\"p\":{\"browserTimestamp\":1522024835416,\"componentId\":\"Componenta3058e5\",\"componentInfo\":\"\",\"marker\":\"loaded\",\"navigation\":1,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"RemoteComma"
		"ndXml.Execute\",\"v\":518,\"t\":1522024835148,\"p\":{\"IsAsync\":true,\"Service\":\"AppGridWebService\",\"ReqId\":\"{CorrelationParameter_22}\"}},{\"n\":\"SubGrid\",\"v\":558,\"t\":1522024835142,\"p\":{\"id\":\"Componentb177617\",\"IsAsync\":true}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522024835700,\"p\":{\"browserTimestamp\":1522024835700,\"componentId\":\"Componentb177617\",\"componentInfo\":\"\",\"marker\":\"loaded\",\"navigation\":1,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"RemoteCommandXml.Execute\",\"v\":587,\"t\":1522024835115,\"p\":{\"IsAsync\":true,\"Service\":\"AppGridWebService\",\"ReqId\":\"{CorrelationParameter_23}\"}},{\"n\":\"SubGrid\",\"v\":630,\"t\":1522024835109,\"p\":{\"id\":\"Component17fb94f\",\"IsAsync\":true}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522024835740,\"p\":{\"browserTimestamp\":1522024835740,\"componentId\":\"Component17fb94f\",\"componentInfo\":\"\",\"marker\":\"loaded\",\"navigation\":1,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a"
		"2\"}}],\"IsExistingActivity\":true},{\"RequestId\":\"{CorrelationParameter_24}\",\"Metrics\":[{\"n\":\"Fetch and Start Load Page\",\"v\":510,\"t\":1522024903288,\"p\":{}},{\"n\":\"Document Ready and CSS Load\",\"v\":140,\"t\":1522024903798,\"p\":{}},{\"n\":\"Read-Ready Grid\",\"v\":697,\"t\":1522024903241,\"p\":{}},{\"n\":\"Before JS load\",\"v\":63,\"t\":1522024903938,\"p\":{}},{\"n\":\"Load Global JS and Init\",\"v\":119,\"t\":1522024904001,\"p\":{}},{\"n\":\"Load Other JS and Init\",\"v\":398,\"t\":1522024904120,\"p\":{}},{\"n\":\"Intialize Controls\",\"v\":69,\"t\":1522024904518,\"p\":{}},{\"n\":\"Initialize Page manager\",\"v\":260,\"t\":1522024904587,\"p\":{}},{\"n\":\"Initialize WRPC tokens\",\"v\":7,\"t\":1522024904847,\"p\":{}},{\"n\":\"Grid Page Load\",\"v\":916,\"t\":1522024903938,\"p\":{}},{\"n\":\"Initialize\",\"v\":920,\"t\":1522024903938,\"p\":{}},{\"n\":\"All Controls Initialized\",\"v\":1617,\"t\":1522024903241,\"p\":{}},{\"n\":\"GridLoad\",\"v\":null,\"t\":1522024904859,\"p\":{\"All Contro"
		"ls Initialized\":1617,\"CRMVersion\":\"9.0.1.621\",\"ClientType\":\"Web\",\"DeviceType\":\"Web\",\"Entity Logical Name\":\"incident\",\"Entity Type Code\":\"112\",\"GRID_COLUMN_WITH_IMAGES\":\"\",\"Initialize Controls\":1346,\"Initialize Page manager\":1606,\"Initialize WRPC tokens\":1613,\"isBPFEntity\":false,\"IsCDNEnabled\":false,\"IsGridColdLoad\":false,\"IsGridWithImageRendering\":true,\"IsResourcesServedFromCDN\":false,\"Load Global JS and Init\":879,\"Load Other JS and Init\":1277,\"OperatingSystem\":\"MICROSOFT WINDOWS\",\"Read-Ready Grid\":697,\"SystemUserId\":\"{{userguid}}\"}},{\"n\":\"WebClientLatencyAndBandwidth\",\"v\":null,\"t\":1522024906203,\"p\":{\"LatencyServerConnectionEstablishedTimeMs\":0,\"LatencyMs\":68,\"BandwidthBytesPerSec\":2337028}},{\"n\":\"Commanding.ExecuteCommand\",\"v\":null,\"t\":1522024938034,\"p\":{\"clientActivityId\":\"{47142810-6863-57db-87c8-3b8054004c5c}\",\"componentType\":\"Start\",\"commandId\":\"Mscrm.NewRecordFromGrid\",\"entityName\":"
		"\"incident\",\"entityContext\":\"HomePageGrid\",\"relationshipType\":\"0\"}},{\"n\":\"Commanding.ExecuteCommand\",\"v\":null,\"t\":1522024938090,\"p\":{\"clientActivityId\":\"{47142810-6863-57db-87c8-3b8054004c5c}\",\"componentType\":\"RibbonAction\",\"commandId\":\"Mscrm.NewRecordFromGrid\",\"entityName\":\"incident\",\"entityContext\":\"HomePageGrid\",\"relationshipType\":\"0\",\"ribbonActionIndex\":\"0\",\"ribbonActionType\":\"JavaScriptFunction\",\"functionName\":\"XrmCore.Commands.Open.openNewRecord\",\"library\":\"$webresource:Main_system_library.js\",\"startTimestamp\":\"1522024938034\",\"endTimestamp\":\"1522024938090\",\"diffTime\":\"56\"}},{\"n\":\"Commanding.ExecuteCommand\",\"v\":null,\"t\":1522024938090,\"p\":{\"clientActivityId\":\"{47142810-6863-57db-87c8-3b8054004c5c}\",\"componentType\":\"End\",\"commandId\":\"Mscrm.NewRecordFromGrid\",\"entityName\":\"incident\",\"entityContext\":\"HomePageGrid\",\"relationshipType\":\"0\"}}],\"IsExistingActivity\":true},{\"RequestId\":\"{CorrelationParame"
		"ter_25}\",\"Metrics\":[{\"n\":\"Update ProcessId From Local Storage\",\"v\":2,\"t\":1522024939649,\"p\":{}},{\"n\":\"OnLoadStarted handlers\",\"v\":0,\"t\":1522024939652,\"p\":{}},{\"n\":\"Request Form Layout\",\"v\":1330,\"t\":1522024939654,\"p\":{}},{\"n\":\"Parse Form Layout Response Json\",\"v\":10,\"t\":1522024940984,\"p\":{}},{\"n\":\"Process Entity Metadata\",\"v\":0,\"t\":1522024940996,\"p\":{}},{\"n\":\"Process inline edit subgrids\",\"v\":0,\"t\":1522024940997,\"p\":{}},{\"n\":\"Style Includes\",\"v\":4,\"t\":1522024940998,\"p\":{}},{\"n\":\"Script Includes\",\"v\":16,\"t\":1522024941002,\"p\":{}},{\"n\":\"Layout Variable Includes\",\"v\":7,\"t\":1522024941018,\"p\":{}},{\"n\":\"Inject Layout Includes to Page\",\"v\":28,\"t\":1522024940997,\"p\":{}},{\"n\":\"Render Form Layout\",\"v\":82,\"t\":1522024941026,\"p\":{}},{\"n\":\"Initialize Application Components\",\"v\":22,\"t\":1522024941108,\"p\":{}},{\"n\":\"Process Form Layout\",\"v\":136,\"t\":1522024940995,\"p\":{}},{\"n\":\"Load Form\",\"v\":1"
		"508,\"t\":1522024939644,\"p\":{}},{\"n\":\"RequestNotesControlLayout\",\"v\":1686,\"t\":1522024939484,\"p\":{}},{\"n\":\"Build Page View Model\",\"v\":16,\"t\":1522024941254,\"p\":{}},{\"n\":\"Build Page Views\",\"v\":11,\"t\":1522024941271,\"p\":{}},{\"n\":\"Initialize Xrm Controls and Data\",\"v\":65,\"t\":1522024941252,\"p\":{}},{\"n\":\"Build Page View Model\",\"v\":1,\"t\":1522024941319,\"p\":{}},{\"n\":\"Build Page Views\",\"v\":1,\"t\":1522024941320,\"p\":{}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024941434,\"p\":{\"apiName\":\"Xrm.Page.data.entity.getEntityReference\",\"client\":\"Web\",\"isDeprecating\":false,\"userId\":\"{{userguid}}\"}},{\"n\":\"ActivityFeeds_LoadHtml\",\"v\":0,\"t\":1522024941434,\"p\":{}},{\"n\":\"AF_Render_Template\",\"v\":9,\"t\":1522024941435,\"p\":{}},{\"n\":\"TextAreaMaxLength\",\"v\":3,\"t\":1522024941446,\"p\":{}},{\"n\":\"TextAreaAutoResize\",\"v\":11,\"t\":1522024941449,\"p\":{}},{\"n\":\"ElementWatermark\",\"v\":0,\"t\":1522024941461,\"p\""
		":{}},{\"n\":\"Wall_SetProgressState\",\"v\":3,\"t\":1522024941464,\"p\":{}},{\"n\":\"TextAreaMentions\",\"v\":1,\"t\":1522024941468,\"p\":{}},{\"n\":\"AF_WallHtml_Render\",\"v\":35,\"t\":1522024941435,\"p\":{}},{\"n\":\"Bind SFA Tabs\",\"v\":43,\"t\":1522024941429,\"p\":{}},{\"n\":\"Bind Xrm to HTML\",\"v\":155,\"t\":1522024941318,\"p\":{}},{\"n\":\"ProcessControl.ControlDataService.InitializeWorkflowStep\",\"v\":6,\"t\":1522024941473,\"p\":{}},{\"n\":\"ProcessControl.ControlDataService.InitializeBpfVisitor\",\"v\":2,\"t\":1522024941479,\"p\":{}},{\"n\":\"ProcessControl.ViewModel.initDataService.Building\",\"v\":8,\"t\":1522024941473,\"p\":{}},{\"n\":\"ProcessControl.View.InitializeSubViews\",\"v\":3,\"t\":1522024941482,\"p\":{}},{\"n\":\"ProcessControl.View.InitializeSlider\",\"v\":4,\"t\":1522024941493,\"p\":{}},{\"n\":\"ProcessControl.InitializeView\",\"v\":16,\"t\":1522024941482,\"p\":{}},{\"n\":\"ProcessControl.StagesView.Layout\",\"v\":3,\"t\":1522024941498,\"p\":{}},{\"n\":\"ProcessControl.StepsView."
		"Layout\",\"v\":1,\"t\":1522024941501,\"p\":{}},{\"n\":\"ProcessControl.ActionsView.Layout\",\"v\":1,\"t\":1522024941502,\"p\":{}},{\"n\":\"ProcessControl.View.Layout\",\"v\":5,\"t\":1522024941498,\"p\":{}},{\"n\":\"ProcessControl.ProcessLayout\",\"v\":30,\"t\":1522024941473,\"p\":{}},{\"n\":\"ProcessControl.InitializePageObjects\",\"v\":0,\"t\":1522024941503,\"p\":{}},{\"n\":\"InitializeProcessControl\",\"v\":30,\"t\":1522024941473,\"p\":{}},{\"n\":\"OnLayoutReady handlers\",\"v\":0,\"t\":1522024941504,\"p\":{}},{\"n\":\"Waiting for data ready before BindData\",\"v\":1,\"t\":1522024941504,\"p\":{}},{\"n\":\"Waiting for layout ready before BindData\",\"v\":0,\"t\":1522024941505,\"p\":{}},{\"n\":\"Process Cached Layout\",\"v\":5,\"t\":1522024941505,\"p\":{}}],\"IsExistingActivity\":true},{\"RequestId\":\"{CorrelationParameter_26}\",\"Metrics\":[{\"n\":\"Data Variable Includes\",\"v\":2,\"t\":1522024941510,\"p\":{}},{\"n\":\"Load PBL Webresource\",\"v\":1,\"t\":1522024941512,\"p\":{}},{\"n\":\"clientapi\",\"v"
		"\":null,\"t\":1522024941516,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024941517,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024941517,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024941519,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024941520,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024941520,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024941520,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024941521,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024941521,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024941521,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024941522,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024941522,\"p\":{\"apiName\":\"GetParent\"}},{"
		"\"n\":\"clientapi\",\"v\":null,\"t\":1522024941523,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"Create Common Controls\",\"v\":11,\"t\":1522024941513,\"p\":{}},{\"n\":\"Bind Form Data for form: {formid_1}\",\"v\":8,\"t\":1522024941525,\"p\":{}},{\"n\":\"ProcessControl.ViewModel.initDataServiceNew\",\"v\":2,\"t\":1522024941534,\"p\":{}},{\"n\":\"ProcessControl.InitializeViewModel.FormData\",\"v\":2,\"t\":1522024941534,\"p\":{}},{\"n\":\"DefaultPathManagerInitialization\",\"v\":2,\"t\":1522024941536,\"p\":{}},{\"n\":\"ProcessControl.StagesView.Render\",\"v\":5,\"t\":1522024941538,\"p\":{}},{\"n\":\"ProcessControl.StepsView.Render\",\"v\":9,\"t\":1522024941544,\"p\":{}},{\"n\":\"ProcessControl.ActionsView.Render\",\"v\":3,\"t\":1522024941553,\"p\":{}},{\"n\":\"ProcessControl.View.Adjust\",\"v\":0,\"t\":1522024941557,\"p\":{}},{\"n\":\"ProcessControl.View.ContainerWidth\",\"v\":1,\"t\":1522024941557,\"p\":{}},{\"n\":\"ProcessControl.View.Resize\",\"v\":4,\"t\":1522024941558,\"p\":{}},{\"n\":\"ProcessControl.View"
		".Render\",\"v\":24,\"t\":1522024941538,\"p\":{}},{\"n\":\"LoadProcessControl\",\"v\":30,\"t\":1522024941533,\"p\":{}},{\"n\":\"ProcessControl.PostInitialize\",\"v\":1,\"t\":1522024941563,\"p\":{}},{\"n\":\"FinalizeProcessControl\",\"v\":6,\"t\":1522024941564,\"p\":{}},{\"n\":\"Bind FormData to Process Control\",\"v\":37,\"t\":1522024941533,\"p\":{}},{\"n\":\"Form RibbonLayout Request - Async\",\"v\":1,\"t\":1522024941571,\"p\":{}},{\"n\":\"Initialize Command Bar\",\"v\":1,\"t\":1522024941571,\"p\":{}},{\"n\":\"Non-Form RibbonLayout Request - Async\",\"v\":9,\"t\":1522024941573,\"p\":{}},{\"n\":\"Execute OnLoad for form: {formid_1}\",\"v\":5,\"t\":1522024941582,\"p\":{}},{\"n\":\"Bind Data\",\"v\":63,\"t\":1522024941524,\"p\":{}},{\"n\":\"OnDataBound handler\",\"v\":0,\"t\":1522024941588,\"p\":{}},{\"n\":\"Create Quick Form\",\"v\":0,\"t\":1522024941589,\"p\":{}},{\"n\":\"Create Record Set Control\",\"v\":1,\"t\":1522024941589,\"p\":{}},{\"n\":\"Add Item to MRU\",\"v\":0,\"t\":1522024941590,\"p\":{}},{\"n\":"
		"\"Bind Data and Create Controls\",\"v\":86,\"t\":1522024941505,\"p\":{}},{\"n\":\"Script Frame OnLoad\",\"v\":15,\"t\":1522024941724,\"p\":{}},{\"n\":\"Waiting for Form Ribbon Layout Response to evaluate Subgrid Ribbon Layouts\",\"v\":140,\"t\":1522024941935,\"p\":{}},{\"n\":\"Run form Onload method: SendMessageToPageManager\",\"v\":0,\"t\":1522024942100,\"p\":{}},{\"n\":\"Run form Onload method: Mscrm.BusinessRulesScript.Initialize\",\"v\":0,\"t\":1522024942101,\"p\":{}},{\"n\":\"Run form Onload method: CreateTurboFormPreOnLoadPerfMarker\",\"v\":0,\"t\":1522024942102,\"p\":{}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024942104,\"p\":{\"apiName\":\"GetDisabled\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024942104,\"p\":{\"apiName\":\"SetFocus\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024942105,\"p\":{\"apiName\":\"SetDisabled\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024942106,\"p\":{\"apiName\":\"SetDisabled\"}},{\"n\":\"Run form Onload method: Mscrm.Form_onload\",\"v\":4,\"t\":1522024942102,\"p"
		"\":{}},{\"n\":\"Run form Onload method: FS.Incident.Library.Load\",\"v\":11,\"t\":1522024942106,\"p\":{}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024942118,\"p\":{\"apiName\":\"GetAttribute\"}},{\"n\":\"Run form Onload method: form_Onload\",\"v\":67,\"t\":1522024942117,\"p\":{}},{\"n\":\"Run form Onload method: captureTelemetry\",\"v\":2,\"t\":1522024942184,\"p\":{}},{\"n\":\"Run form Onload method: syncFields\",\"v\":3,\"t\":1522024942186,\"p\":{}},{\"n\":\"ProcessControl.View.Resize\",\"v\":78,\"t\":1522024942191,\"p\":{}},{\"n\":\"UI Update 1\",\"v\":445,\"t\":1522024942190,\"p\":{}},{\"n\":\"Post OnLoad UI Update\",\"v\":446,\"t\":1522024942190,\"p\":{}},{\"n\":\"Handle Post OnLoad\",\"v\":454,\"t\":1522024942189,\"p\":{}},{\"n\":\"Run form Onload method: SendMessageToPageManager\",\"v\":455,\"t\":1522024942189,\"p\":{}},{\"n\":\"Run form Onload method: FireDataLoad\",\"v\":1,\"t\":1522024942644,\"p\":{}},{\"n\":\"Append Script: /{636567693290000510}/WebResources/Main_system_library.js?appid=ab18c93f-"
		"61e6-e711-a848-000d3ad117e3&ver=-2068631631\",\"v\":22,\"t\":1522024943099,\"p\":{}},{\"n\":\"Run form Onload method: SendMessageToPageManager\",\"v\":0,\"t\":1522024943122,\"p\":{}},{\"n\":\"Fire Global PageLoaded Event\",\"v\":84,\"t\":1522024943193,\"p\":{}},{\"n\":\"Refresh NavBar\",\"v\":55,\"t\":1522024943277,\"p\":{}},{\"n\":\"InitializePageState - OnBeforeUnload\",\"v\":0,\"t\":1522024943388,\"p\":{}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024943416,\"p\":{\"apiName\":\"Xrm.Page.data.removeOnLoad\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024943418,\"p\":{\"apiName\":\"Xrm.Page.data.removeOnLoad\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024943421,\"p\":{\"apiName\":\"Xrm.Page.data.removeOnLoad\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024943423,\"p\":{\"apiName\":\"Xrm.Page.data.removeOnLoad\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024943425,\"p\":{\"apiName\":\"Xrm.Page.data.removeOnLoad\"}},{\"n\":\"InitializePageState - ClearEventHandlers\",\"v\":6,\"t\":1522024943456,\"p\":{}}"
		",{\"n\":\"InitializePageState - Dispose All Objects\",\"v\":89,\"t\":1522024943388,\"p\":{}},{\"n\":\"Update ProcessId From Local Storage\",\"v\":0,\"t\":1522024943480,\"p\":{}},{\"n\":\"OnLoadStarted handlers\",\"v\":1,\"t\":1522024943480,\"p\":{}},{\"n\":\"Request Form Layout\",\"v\":485,\"t\":1522024943482,\"p\":{}},{\"n\":\"Parse Form Layout Response Json\",\"v\":10,\"t\":1522024943968,\"p\":{}},{\"n\":\"Process Entity Metadata\",\"v\":0,\"t\":1522024943979,\"p\":{}},{\"n\":\"Process inline edit subgrids\",\"v\":0,\"t\":1522024943979,\"p\":{}},{\"n\":\"Style Includes\",\"v\":3,\"t\":1522024943981,\"p\":{}},{\"n\":\"Script Includes\",\"v\":10,\"t\":1522024943984,\"p\":{}}],\"IsExistingActivity\":true},{\"RequestId\":\"{CorrelationParameter_36}\",\"Metrics\":[{\"n\":\"Data Variable Includes\",\"v\":1,\"t\":1522024944559,\"p\":{}},{\"n\":\"Load PBL Webresource\",\"v\":2,\"t\":1522024944561,\"p\":{}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024944565,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\","
		"\"v\":null,\"t\":1522024944567,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024944568,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024944568,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024944569,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024944569,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024944570,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024944570,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024944571,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024944571,\"p\":{\"apiName\":\"GetParent\"}},{\"n\":\"Create Common Controls\",\"v\":8,\"t\":1522024944564,\"p\":{}},{\"n\":\"Bind Form Data for form: {formid}\",\"v\":6,\"t\":1522024944572,\"p\":{}},{\"n\":\"ProcessControl.ViewModel.initDataServiceNew\",\"v\":1,\"t\":1522024944578,\"p\":{}},{\"n\":\"Pro"
		"cessControl.InitializeViewModel.FormData\",\"v\":1,\"t\":1522024944578,\"p\":{}},{\"n\":\"DefaultPathManagerInitialization\",\"v\":0,\"t\":1522024944580,\"p\":{}},{\"n\":\"ProcessControl.StagesView.Render\",\"v\":5,\"t\":1522024944580,\"p\":{}},{\"n\":\"ProcessControl.StepsView.Render\",\"v\":10,\"t\":1522024944585,\"p\":{}},{\"n\":\"ProcessControl.ActionsView.Render\",\"v\":2,\"t\":1522024944595,\"p\":{}},{\"n\":\"ProcessControl.View.Adjust\",\"v\":0,\"t\":1522024944597,\"p\":{}},{\"n\":\"ProcessControl.View.ContainerWidth\",\"v\":1,\"t\":1522024944598,\"p\":{}},{\"n\":\"ProcessControl.View.Resize\",\"v\":3,\"t\":1522024944599,\"p\":{}},{\"n\":\"ProcessControl.View.Render\",\"v\":23,\"t\":1522024944580,\"p\":{}},{\"n\":\"LoadProcessControl\",\"v\":25,\"t\":1522024944578,\"p\":{}},{\"n\":\"ProcessControl.PostInitialize\",\"v\":1,\"t\":1522024944603,\"p\":{}},{\"n\":\"FinalizeProcessControl\",\"v\":3,\"t\":1522024944604,\"p\":{}},{\"n\":\"Bind FormData to Process Control\",\"v\":29,\"t\":1522024944578,\"p\":"
		"{}},{\"n\":\"Form RibbonLayout Request - Async\",\"v\":1,\"t\":1522024944608,\"p\":{}},{\"n\":\"Initialize Command Bar\",\"v\":1,\"t\":1522024944608,\"p\":{}},{\"n\":\"Non-Form RibbonLayout Request - Async\",\"v\":17,\"t\":1522024944610,\"p\":{}},{\"n\":\"Execute OnLoad for form: {formid}\",\"v\":5,\"t\":1522024944627,\"p\":{}},{\"n\":\"Bind Data\",\"v\":60,\"t\":1522024944572,\"p\":{}},{\"n\":\"OnDataBound handler\",\"v\":1,\"t\":1522024944632,\"p\":{}},{\"n\":\"Create Quick Form\",\"v\":0,\"t\":1522024944633,\"p\":{}},{\"n\":\"Create Record Set Control\",\"v\":1,\"t\":1522024944633,\"p\":{}},{\"n\":\"Add Item to MRU\",\"v\":0,\"t\":1522024944634,\"p\":{}},{\"n\":\"Bind Data and Create Controls\",\"v\":80,\"t\":1522024944554,\"p\":{}},{\"n\":\"Run form Onload method: SendMessageToPageManager\",\"v\":0,\"t\":1522024944667,\"p\":{}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024944669,\"p\":{\"apiName\":\"SetDisabled\"}},{\"n\":\"Run form Onload method: Mscrm.BusinessRulesScript.Initialize\",\"v\":1,\"t\":152"
		"2024944668,\"p\":{}},{\"n\":\"Run form Onload method: CreateTurboFormPreOnLoadPerfMarker\",\"v\":0,\"t\":1522024944670,\"p\":{}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024944671,\"p\":{\"apiName\":\"GetDisabled\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024944671,\"p\":{\"apiName\":\"SetFocus\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024944672,\"p\":{\"apiName\":\"SetDisabled\"}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024944672,\"p\":{\"apiName\":\"SetDisabled\"}},{\"n\":\"Run form Onload method: Mscrm.Form_onload\",\"v\":2,\"t\":1522024944670,\"p\":{}},{\"n\":\"Run form Onload method: FS.Incident.Library.Load\",\"v\":15,\"t\":1522024944673,\"p\":{}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522024944688,\"p\":{\"apiName\":\"GetAttribute\"}},{\"n\":\"Run form Onload method: form_Onload\",\"v\":6,\"t\":1522024944688,\"p\":{}},{\"n\":\"Run form Onload method: captureTelemetry\",\"v\":1,\"t\":1522024944694,\"p\":{}},{\"n\":\"ProcessControl.View.Resize\",\"v\":94,\"t\":1522024944696,\"p\":{}},{\"n\":"
		"\"UI Update 1\",\"v\":370,\"t\":1522024944696,\"p\":{}},{\"n\":\"Post OnLoad UI Update\",\"v\":370,\"t\":1522024944696,\"p\":{}},{\"n\":\"Handle Post OnLoad\",\"v\":379,\"t\":1522024944696,\"p\":{}},{\"n\":\"Run form Onload method: SendMessageToPageManager\",\"v\":379,\"t\":1522024944696,\"p\":{}},{\"n\":\"Run form Onload method: FireDataLoad\",\"v\":0,\"t\":1522024945076,\"p\":{}},{\"n\":\"Waiting for Form Ribbon Layout Response to evaluate Subgrid Ribbon Layouts\",\"v\":635,\"t\":1522024944627,\"p\":{}},{\"n\":\"RemoteCommand.Execute\",\"v\":310,\"t\":1522024945067,\"p\":{\"IsAsync\":true,\"Service\":\"LookupService\",\"ReqId\":\"{CorrelationParameter_37}\"}},{\"n\":\"Fire Global PageLoaded Event\",\"v\":111,\"t\":1522024945523,\"p\":{}},{\"n\":\"Refresh NavBar\",\"v\":43,\"t\":1522024945634,\"p\":{}},{\"n\":\"RemoteCommand.Execute\",\"v\":3364,\"t\":1522025092992,\"p\":{\"IsAsync\":false,\"Service\":\"LookupService\",\"ReqId\":\"{CorrelationParameter_38}\"}},{\"n\":\"Run form Onload method: Mscrm.custome"
		"rid_onchange\",\"v\":1,\"t\":1522025104818,\"p\":{}},{\"n\":\"clientapi\",\"v\":null,\"t\":1522025104820,\"p\":{\"apiName\":\"SetDisabled\"}},{\"n\":\"Build Page View Model\",\"v\":1,\"t\":1522025104820,\"p\":{}},{\"n\":\"Build Page Views\",\"v\":1,\"t\":1522025104821,\"p\":{}},{\"n\":\"Build Page View Model\",\"v\":1,\"t\":1522025104824,\"p\":{}},{\"n\":\"Build Page Views\",\"v\":0,\"t\":1522025104825,\"p\":{}},{\"n\":\"Append Script: /{636567693290000510}/WebResources/Service/Localization/Script/ResourceStringProvider.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=-2068631631\",\"v\":1157,\"t\":1522025104942,\"p\":{}},{\"n\":\"Run form Onload method: SendMessageToPageManager\",\"v\":0,\"t\":1522025106100,\"p\":{}},{\"n\":\"Append Script: /{636567693290000510}/WebResources/CRM/ClientUtility.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=-2068631631\",\"v\":88,\"t\":1522025106101,\"p\":{}},{\"n\":\"Run form Onload method: SendMessageToPageManager\",\"v\":0,\"t\":1522025106190,\"p\":{}},{\"n\":\"Append"
		" Script: /{636567693290000510}/WebResources/CRM/Localization/ResourceStringProvider.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=-2068631631\",\"v\":50,\"t\":1522025106192,\"p\":{}},{\"n\":\"Run form Onload method: SendMessageToPageManager\",\"v\":0,\"t\":1522025106242,\"p\":{}},{\"n\":\"Append Script: /{636567693290000510}/WebResources/Service/Incident/Ribbon/Incident_ribbon_library.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=-2068631631\",\"v\":80,\"t\":1522025106244,\"p\":{}},{\"n\":\"Run form Onload method: SendMessageToPageManager\",\"v\":0,\"t\":1522025106324,\"p\":{}},{\"n\":\"Append Script: /{636567693290000510}/WebResources/Main_system_library.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=-2068631631\",\"v\":21,\"t\":1522025106422,\"p\":{}},{\"n\":\"Run form Onload method: SendMessageToPageManager\",\"v\":0,\"t\":1522025106444,\"p\":{}},{\"n\":\"RemoteCommand.Execute\",\"v\":1701,\"t\":1522025104807,\"p\":{\"IsAsync\":true,\"Service\":\"PresenceService\",\"ReqId\":\"{CorrelationParam"
		"eter_39}\"}},{\"n\":\"RemoteCommand.Execute\",\"v\":1670,\"t\":1522025104840,\"p\":{\"IsAsync\":true,\"Service\":\"PresenceService\",\"ReqId\":\"{CorrelationParameter_40}\"}},{\"n\":\"RemoteCommand.Execute\",\"v\":1630,\"t\":1522025104881,\"p\":{\"IsAsync\":true,\"Service\":\"InlineEditWebService\",\"ReqId\":\"{CorrelationParameter_41}\"}},{\"n\":\"RemoteCommandXml.Execute\",\"v\":235,\"t\":1522025106376,\"p\":{\"IsAsync\":true,\"Service\":\"AppGridWebService\",\"ReqId\":\"{CorrelationParameter_42}\"}},{\"n\":\"SubGrid\",\"v\":267,\"t\":1522025106364,\"p\":{\"id\":\"Personal_Personal_contact_Person\",\"IsAsync\":true}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522025106631,\"p\":{\"browserTimestamp\":1522025106631,\"componentId\":\"Personal_Personal_contact_Person\",\"componentInfo\":\"\",\"marker\":\"loaded\",\"navigation\":4,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"RemoteCommandXml.Execute\",\"v\":144,\"t\":1522025106488,\"p\":{\"IsAsync\":true,\"Service\":\"AppGridWebService\","
		"\"ReqId\":\"{CorrelationParameter_43}\"}},{\"n\":\"SubGrid\",\"v\":174,\"t\":1522025106477,\"p\":{\"id\":\"AlertsOnClient_AlertsOnClient_contact_AlertsOnCase\",\"IsAsync\":true}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522025106652,\"p\":{\"browserTimestamp\":1522025106651,\"componentId\":\"AlertsOnClient_AlertsOnClient_contact_AlertsOnCase\",\"componentInfo\":\"\",\"marker\":\"loaded\",\"navigation\":4,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}},{\"n\":\"RemoteCommand.Execute\",\"v\":262,\"t\":1522025106390,\"p\":{\"IsAsync\":true,\"Service\":\"InlineEditWebService\",\"ReqId\":\"{CorrelationParameter_44}\"}},{\"n\":\"Handle Post OnLoad\",\"v\":9,\"t\":1522025106708,\"p\":{}},{\"n\":\"Execute OnLoad for form: 959892a7-a898-44ed-83ca-63e7ce1850d4\",\"v\":9,\"t\":1522025106708,\"p\":{}},{\"n\":\"Handle Post OnLoad\",\"v\":5,\"t\":1522025106823,\"p\":{}},{\"n\":\"Execute OnLoad for form: 8aaf6a61-a29d-4936-8f85-7dac32ed81d8\",\"v\":5,\"t\":1522025106823,\"p\":{}},{\"n\":\"RemoteCommand.Execute"
		"\",\"v\":205,\"t\":1522025149012,\"p\":{\"IsAsync\":false,\"Service\":\"LookupService\",\"ReqId\":\"{CorrelationParameter_45}\"}},{\"n\":\"Build Page View Model\",\"v\":1,\"t\":1522025151555,\"p\":{}},{\"n\":\"Build Page Views\",\"v\":1,\"t\":1522025151556,\"p\":{}},{\"n\":\"Append Script: /{636567693290000510}/WebResources/dhhs_case?appid=ab18c93f-61e6-e711-a848-000d3ad117e3\",\"v\":31,\"t\":1522025151640,\"p\":{}},{\"n\":\"Run form Onload method: SendMessageToPageManager\",\"v\":0,\"t\":1522025151672,\"p\":{}},{\"n\":\"Append Script: /{636567693290000510}/WebResources/Service/CommandBarActions/ServiceCommandBarActions.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=-2068631631\",\"v\":64,\"t\":1522025151677,\"p\":{}},{\"n\":\"Run form Onload method: SendMessageToPageManager\",\"v\":0,\"t\":1522025151741,\"p\":{}},{\"n\":\"RemoteCommand.Execute\",\"v\":223,\"t\":1522025151595,\"p\":{\"IsAsync\":true,\"Service\":\"InlineEditWebService\",\"ReqId\":\"{CorrelationParameter_46}\"}},{\"n\":\"Handle Post OnLoad"
		"\",\"v\":18,\"t\":1522025151833,\"p\":{}},{\"n\":\"Execute OnLoad for form: 0b8dc4ed-c769-4501-968c-df4024c3a9de\",\"v\":18,\"t\":1522025151833,\"p\":{}},{\"n\":\"RemoteCommandXml.Execute\",\"v\":154,\"t\":1522025151796,\"p\":{\"IsAsync\":true,\"Service\":\"AppGridWebService\",\"ReqId\":\"{CorrelationParameter_47}\"}},{\"n\":\"SubGrid\",\"v\":247,\"t\":1522025151786,\"p\":{\"id\":\"Case_group_details_form_Case_group_details_form_dhhs_casegroup_Related_people\",\"IsAsync\":true}},{\"n\":\"clienttimeline\",\"v\":null,\"t\":1522025152034,\"p\":{\"browserTimestamp\":1522025152034,\"componentId\":\"Case_group_details_form_Case_group_details_form_dhhs_casegroup_Related_people\",\"componentInfo\":\"\",\"marker\":\"loaded\",\"navigation\":4,\"sessionId\":\"e23017eb-9dbf-4b03-ac3c-36b7bdc709a2\"}}],\"IsExistingActivity\":true}]}}",
		LAST);*/

	web_add_header("CRMWRPCToken", 
		lr_eval_string("{path4}"));

	web_add_auto_header("CRMWRPCTokenTimeStamp",
		"{CorrelationParameter_53}");

	web_add_auto_header("FormLoadId", 
		"{90e54e86-12d1-3a6b-32ae-82426864576d}");

	web_add_auto_header("ReferrerReqId",
		"{CorrelationParameter_36}");

	web_add_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/Execute");
	
	web_reg_save_param("oId","LB/IC=\"_entity\":{\"Id\":\"{","RB/IC=}\",",LAST);

	lr_start_transaction("CRM_06_CreateCase_06_SaveCase");

	web_custom_request("InlineEditWebService.asmx_4",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/InlineEditWebService.asmx",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t59.inf",
		"Mode=HTML",
		"EncType=text/xml; charset=utf-8",
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><Execute xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><command>1</command><commandXml>&#60;Input&#62;&#60;id&#62;00000000-0000-0000-0000-000000000000&#60;&#47;id&#62;&#60;name&#62;incident&#60;&#47;name&#62;&#60;formId&#62;{formid}&#60;&#47;formId&#62;&#60;dataxml&#62;&#38;&#35;60&#59;incident&#38;&#35;62&#59;&#38;&#35;60&#59;dhhs_operationalguidelines&#38;&#35;62&#59;PerformanceTestingPurposeOnlyThisCaseisbeingcreated.&#38;&#35;60&#59;&#38;&#35;47&#59;dhhs_operationalguidelines&#38;&#35;62&#59;&#38;&#35;60&#59;dhhs_helptextbpf&#38;&#35;62&#59;Some help text...&#38;&#35;60&#59;&#38;&#35;47&#59;dhhs_helptextbpf&#38;&#35;62&#59;&#38;&#35;60&#59;statuscode&#38;&#35;62&#59;1&#38;&#35;60&#59;&#38;&#35;47&#59;statuscode&#38;&#35;62&#59;&#38;&#35;60&#59;firstresponseslas"
		"tatus&#38;&#35;62&#59;1&#38;&#35;60&#59;&#38;&#35;47&#59;firstresponseslastatus&#38;&#35;62&#59;&#38;&#35;60&#59;processid&#38;&#35;62&#59;{process}&#38;&#35;60&#59;&#38;&#35;47&#59;processid&#38;&#35;62&#59;&#38;&#35;60&#59;traversedpath&#38;&#35;62&#59;9a1a4412-9444-4e47-ad53-c2877413026c&#38;&#35;60&#59;&#38;&#35;47&#59;traversedpath&#38;&#35;62&#59;&#38;&#35;60&#59;casetypecode&#38;&#35;62&#59;883990000&#38;&#35;60&#59;&#38;&#35;47&#59;casetypecode&#38;&#35;62&#59;&#38;&#35;60&#59;customerid type&#38;&#35;61&#59;&#38;&#35;34&#59;2&#38;&#35;34&#59; name&#38;&#35;61&#59;&#38;&#35;34&#59;PerfTest&#38;&#35;38&#59;&#38;&#35;35&#59;32&#38;&#35;59&#59;{ClientFN} {ClientLN}&#38;&#35;34&#59;&#38;&#35;62&#59;&#38;&#35;38&#59;&#38;&#35;35&#59;123&#38;&#35;59&#59;{ClientOid}&#38;&#35;38&#59;&#38;&#35;35&#59;125&#38;&#35;59&#59;&#38;&#35;60&#59;&#38;&#35;47&#59;customerid&#38;&#35;62&#59;&#38;&#35;60&#59;dhhs_narrative&#38;&#35;62&#59;PerformanceTestingNarrativedetails&#38;&#35;60&#59;&#38;&#35;47&#59;dhh"
		"s_narrative&#38;&#35;62&#59;&#38;&#35;60&#59;dhhs_presentingneed&#38;&#35;62&#59;PerformanceTestingPresentingNeed&#38;&#35;60&#59;&#38;&#35;47&#59;dhhs_presentingneed&#38;&#35;62&#59;&#38;&#35;60&#59;dhhs_casegroupsid type&#38;&#35;61&#59;&#38;&#35;34&#59;10217&#38;&#35;34&#59; name&#38;&#35;61&#59;&#38;&#35;34&#59;{param_GroupName}{param_PerfGroupNumber}&#38;&#35;34&#59;&#38;&#35;62&#59;&#38;&#35;38&#59;&#38;&#35;35&#59;123&#38;&#35;59&#59;{GroupOid}&#38;&#35;38&#59;&#38;&#35;35&#59;125&#38;&#35;59&#59;&#38;&#35;60&#59;&#38;&#35;47&#59;dhhs_casegroupsid&#38;&#35;62&#59;&#38;&#35;60&#59;dhhs_closecase&#38;&#35;62&#59;0&#38;&#35;60&#59;&#38;&#35;47&#59;dhhs_closecase&#38;&#35;62&#59;&#38;&#35;60&#59;dhhs_roleforprimaryclient&#38;&#35;62&#59;883990000&#38;&#35;60&#59;&#38;&#35;47&#59;dhhs_roleforprimaryclient&#38;&#35;62&#59;&#38;&#35;60&#59;ownerid type&#38;&#35;61&#59;&#38;&#35;34&#59;8&#38;&#35;34&#59; name&#38;&#35;61&#59;&#38;&#35;34&#59;{corr_givenname}&#38;&#35;38&#59;&#38;&#35;35&#59;32&#38;&#35;59&#59;{corr_surname}"
		"&#38;&#35;34&#59;&#38;&#35;62&#59;&#38;&#35;38&#59;&#38;&#35;35&#59;123&#38;&#35;59&#59;{userguid}&#38;&#35;38&#59;&#38;&#35;35&#59;125&#38;&#35;59&#59;&#38;&#35;60&#59;&#38;&#35;47&#59;ownerid&#38;&#35;62&#59;&#38;&#35;60&#59;title&#38;&#35;62&#59;{param_CaseName}{param_CaseDate}{param_CaseNumber}&#38;&#35;60&#59;&#38;&#35;47&#59;title&#38;&#35;62&#59;&#38;&#35;60&#59;resolvebyslastatus&#38;&#35;62&#59;1&#38;&#35;60&#59;&#38;&#35;47&#59;resolvebyslastatus&#38;&#35;62&#59;&#38;&#35;60&#59;dhhs_validatecaseclosure&#38;&#35;62&#59;0&#38;&#35;60&#59;&#38;&#35;47&#59;dhhs_validatecaseclosure&#38;&#35;62&#59;&#38;&#35;60&#59;stageid&#38;&#35;62&#59;9a1a4412-9444-4e47-ad53-c2877413026c&#38;&#35;60&#59;&#38;&#35;47&#59;stageid&#38;&#35;62&#59;&#38;&#35;60&#59;transactioncurrencyid name&#38;&#35;61&#59;&#38;&#35;34&#59;Australian Dollar&#38;&#35;34&#59; type&#38;&#35;61&#59;&#38;&#35;34&#59;9105&#38;&#35;34&#59;&#38;&#35;62&#59;&#38;&#35;123&#59;2143E9A2-21CA-E711-A835-000D3AD07676&#38;&#35;125&#59;&#38;&#35;"
		"60&#59;&#38;&#35;47&#59;transactioncurrencyid&#38;&#35;62&#59;&#38;&#35;60&#59;isdecrementing name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;62&#59;false&#38;&#35;60&#59;&#38;&#35;47&#59;isdecrementing&#38;&#35;62&#59;&#38;&#35;60&#59;dhhs_triggersync name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;62&#59;false&#38;&#35;60&#59;&#38;&#35;47&#59;dhhs_triggersync&#38;&#35;62&#59;&#38;&#35;60&#59;prioritycode name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;62&#59;2&#38;&#35;60&#59;&#38;&#35;47&#59;prioritycode&#38;&#35;62&#59;&#38;&#35;60&#59;activitiescomplete name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;62&#59;false&#38;&#35;60&#59;&#38;&#35;47&#59;activitiescomplete&#38;&#35;62&#59;&#38;&#35;60&#59;severitycode name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;62&#59;1&#38;&#35;60&#59;&#38;&#35;47&#59;severitycode&#38;&#35;62&#59;&#38;&#35;60&#59;isescalated name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;"
		"62&#59;false&#38;&#35;60&#59;&#38;&#35;47&#59;isescalated&#38;&#35;62&#59;&#38;&#35;60&#59;dhhs_latestsafetyplan name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;62&#59;true&#38;&#35;60&#59;&#38;&#35;47&#59;dhhs_latestsafetyplan&#38;&#35;62&#59;&#38;&#35;60&#59;decremententitlementterm name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;62&#59;true&#38;&#35;60&#59;&#38;&#35;47&#59;decremententitlementterm&#38;&#35;62&#59;&#38;&#35;60&#59;incidentstagecode name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;62&#59;1&#38;&#35;60&#59;&#38;&#35;47&#59;incidentstagecode&#38;&#35;62&#59;&#38;&#35;60&#59;routecase name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;62&#59;true&#38;&#35;60&#59;&#38;&#35;47&#59;routecase&#38;&#35;62&#59;&#38;&#35;60&#59;customercontacted name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;62&#59;false&#38;&#35;60&#59;&#38;&#35;47&#59;customercontacted&#38;&#35;62&#59;&#38;&#35;60&#59;statecode name&#38;&#35;61&#59;&"
		"#38;&#35;34&#59;Active&#38;&#35;34&#59;&#38;&#35;62&#59;Active&#38;&#35;60&#59;&#38;&#35;47&#59;statecode&#38;&#35;62&#59;&#38;&#35;60&#59;blockedprofile name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;62&#59;false&#38;&#35;60&#59;&#38;&#35;47&#59;blockedprofile&#38;&#35;62&#59;&#38;&#35;60&#59;followuptaskcreated name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;62&#59;false&#38;&#35;60&#59;&#38;&#35;47&#59;followuptaskcreated&#38;&#35;62&#59;&#38;&#35;60&#59;checkemail name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;62&#59;false&#38;&#35;60&#59;&#38;&#35;47&#59;checkemail&#38;&#35;62&#59;&#38;&#35;60&#59;firstresponsesent name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;62&#59;false&#38;&#35;60&#59;&#38;&#35;47&#59;firstresponsesent&#38;&#35;62&#59;&#38;&#35;60&#59;dhhs_maritalstatus name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;62&#59;883990002&#38;&#35;60&#59;&#38;&#35;47&#59;dhhs_maritalstatus&#38;&#35;62&#59;&#38;&#35;"
		"60&#59;dhhs_latestriskandneedsassessment name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;62&#59;true&#38;&#35;60&#59;&#38;&#35;47&#59;dhhs_latestriskandneedsassessment&#38;&#35;62&#59;&#38;&#35;60&#59;dhhs_safetocall name&#38;&#35;61&#59;&#38;&#35;34&#59;&#38;&#35;34&#59;&#38;&#35;62&#59;false&#38;&#35;60&#59;&#38;&#35;47&#59;dhhs_safetocall&#38;&#35;62&#59;&#38;&#35;13&#59;&#38;&#35;10&#59;&#38;&#35;60&#59;businessprocessflowinstanceid&#38;&#35;62&#59;00000000-0000-0000-0000-000000000000&#38;&#35;60&#59;&#38;&#35;47&#59;businessprocessflowinstanceid&#38;&#35;62&#59;&#38;&#35;60&#59;&#38;&#35;47&#59;incident&#38;&#35;62&#59;&#60;&#47;dataxml&#62;&#60;performduplicatecheck&#62;true&#60;&#47;performduplicatecheck&#62;&#60;associations&#62;&#60;&#47;associations&#62;&#60;processId&#62;{process}&#60;&#47;processId&#62;&#60;businessProcessInstanceId&#62;00000000-0000-0000-0000-000000000000&#60;&#47;businessProcessInstanceId&#62;&#60;&#47;Input&#62;</commandXml><encodeValues>false</encodeValues><"
		"/Execute></soap:Body></soap:Envelope>",
		LAST);

	web_add_auto_header("CRMWRPCToken", 
		lr_eval_string("{path3}"));

	web_custom_request("AppGridWebService.ashx_8",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/AppGridWebService.ashx?operation=Refresh",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t60.inf",
		"Mode=HTML",
		"EncType=text/plain;charset=UTF-8",
		"Body=<grid><sortColumns>record2id&#58;1</sortColumns><pageNum>1</pageNum><recsPerPage>10</recsPerPage><dataProvider>Microsoft.Crm.Application.Platform.Grid.GridDataProviderQueryBuilder</dataProvider><uiProvider>Microsoft.Crm.Application.Controls.GridUIProvider</uiProvider><cols/><max>1</max><refreshAsync>True</refreshAsync><pagingCookie/><enableMultiSort>true</enableMultiSort><enablePagingWhenOnePage>true</enablePagingWhenOnePage><refreshCalledFromRefreshButton>1</refreshCalledFromRefreshButton><returntotalrecordcount>true</returntotalrecordcount><getParameters>getFetchXmlForFilters</getParameters><parameters><viewid>&#123;7C0E0725-CCD9-4525-9313-665FD075652F&#125;</viewid><RenderAsync>0</RenderAsync><LoadOnDemand>1</LoadOnDemand><autorefresh>1</autorefresh><isGridHidden>false</isGridHidden><LayoutStyle>LiteGridList</LayoutStyle><maxselectableitems>1</maxselectableitems><isGridFilteringEnabled>1</isGridFilteringEnabled><viewtype>1039</viewtype><viewts>3142845</viewts><RecordsPerPage>10</RecordsPerPage><viewT"
		"itle>Active Connections</viewTitle><layoutXml>&#60;grid name&#61;&#34;connections&#34; jump&#61;&#34;record2id&#34; select&#61;&#34;1&#34; icon&#61;&#34;0&#34; preview&#61;&#34;1&#34; object&#61;&#34;3234&#34;&#62;&#60;row name&#61;&#34;connection&#34; id&#61;&#34;connectionid&#34;&#62;&#60;cell name&#61;&#34;record2roleid&#34; width&#61;&#34;150&#34; &#47;&#62;&#60;cell name&#61;&#34;record2id&#34; width&#61;&#34;150&#34; &#47;&#62;&#60;&#47;row&#62;&#60;&#47;grid&#62;</layoutXml><otc>3234</otc><otn>connection</otn><entitydisplayname>Connection</entitydisplayname><titleformat>&#123;0&#125; &#123;1&#125;</titleformat><entitypluraldisplayname>Connections</entitypluraldisplayname><expandable>1</expandable><showjumpbar>0</showjumpbar><maxrowsbeforescroll>12</maxrowsbeforescroll><tabindex>1360</tabindex><refreshasynchronous>1</refreshasynchronous><subgridAutoExpand>0</subgridAutoExpand><relName>incident_connections1</relName><roleOrd>-1</roleOrd><oType>112</oType><relationshipType>1</relationshipType><ribbonCon"
		"text>SubGridStandard</ribbonContext><GridType>SubGrid</GridType><enableContextualActions>true</enableContextualActions><teamTemplateId></teamTemplateId><isWorkflowSupported>true</isWorkflowSupported><LoadOnDemand_GridEmptyMessage>To load &#123;0&#125; records, click here.</LoadOnDemand_GridEmptyMessage><enableFilters></enableFilters><InnerGridDisabled>0</InnerGridDisabled><oId>&#123;{oId}&#125;</oId><isTurboForm>1</isTurboForm></parameters><columns><column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Role&#32;&#40;To&#41;\" fieldname=\"record2roleid\" entityname=\"connection\" type=\"Lookup\" sourcetype=\"0\">record2roleid</column><column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Connected&#32;to\" fieldname=\"record2id\" entityname=\"connection\" type=\"Lookup.connection\" sourcetype=\"0\">record2id</column></columns></grid>",
		LAST);

	web_custom_request("AppGridWebService.ashx_9",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/AppGridWebService.ashx?operation=Refresh",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t61.inf",
		"Mode=HTML",
		"EncType=text/plain;charset=UTF-8",
		"Body=<grid><sortColumns>dhhs_screening&#58;1</sortColumns><pageNum>1</pageNum><recsPerPage>10</recsPerPage><dataProvider>Microsoft.Crm.Application.Platform.Grid.GridDataProviderQueryBuilder</dataProvider><uiProvider>Microsoft.Crm.Application.Controls.GridUIProvider</uiProvider><cols/><max>1</max><refreshAsync>True</refreshAsync><pagingCookie/><enableMultiSort>true</enableMultiSort><enablePagingWhenOnePage>true</enablePagingWhenOnePage><refreshCalledFromRefreshButton>1</refreshCalledFromRefreshButton><returntotalrecordcount>true</returntotalrecordcount><getParameters>getFetchXmlForFilters</getParameters><parameters><viewid>&#123;EC7E0EAA-07BA-E711-814B-E0071B6D9931&#125;</viewid><RenderAsync>0</RenderAsync><LoadOnDemand>1</LoadOnDemand><autorefresh>1</autorefresh><isGridHidden>false</isGridHidden><LayoutStyle>LiteGridList</LayoutStyle><maxselectableitems>1</maxselectableitems><isGridFilteringEnabled>1</isGridFilteringEnabled><viewtype>1039</viewtype><viewts>3143950</viewts><RecordsPerPage>10</RecordsPerPage><"
		"viewTitle>L17 Screening Person</viewTitle><layoutXml>&#60;grid name&#61;&#34;resultset&#34; jump&#61;&#34;dhhs_name&#34; select&#61;&#34;1&#34; preview&#61;&#34;1&#34; icon&#61;&#34;1&#34; object&#61;&#34;10249&#34;&#62;&#60;row name&#61;&#34;result&#34; id&#61;&#34;dhhs_screeningpersonsid&#34;&#62;&#60;cell name&#61;&#34;createdon&#34; width&#61;&#34;100&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_screening&#34; width&#61;&#34;125&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;a_a79cc2c4c1a7e7118148e0071b6d9931.dhhs_l17screeningid&#34; width&#61;&#34;125&#34; disableSorting&#61;&#34;1&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; relatedentityname&#61;&#34;dhhs_screening&#34; relatedentityattr&#61;&#34;dhhs_screeningid&#34; primaryentityattr&#61;&#34;dhhs_screening&#34; relationshipid&#61;&#34;&#123;1b2060c5-8216-4c89-8859-64ac83c9692e&#125;&#34; relatio"
		"nshipname&#61;&#34;dhhs_screening_dhhs_screeningpersons&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_givennames&#34; width&#61;&#34;125&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_lastname&#34; width&#61;&#34;125&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_personid&#34; width&#61;&#34;125&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_role&#34; width&#61;&#34;100&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;a_a79cc2c4c1a7e7118148e0071b6d9931.dhhs_childreninfamily&#34; width&#61;&#34;100&#34; disableSorting&#61;&#34;1&#34; relatedentityname&#61;&#34;dhhs_screening&#34; relatedentityattr&#61;&#34;dhhs_screeningid&#34; "
		"primaryentityattr&#61;&#34;dhhs_screening&#34; relationshipid&#61;&#34;&#123;1b2060c5-8216-4c89-8859-64ac83c9692e&#125;&#34; relationshipname&#61;&#34;dhhs_screening_dhhs_screeningpersons&#34; &#47;&#62;&#60;cell name&#61;&#34;a_a79cc2c4c1a7e7118148e0071b6d9931.dhhs_l17pdffile&#34; width&#61;&#34;100&#34; disableSorting&#61;&#34;1&#34; relatedentityname&#61;&#34;dhhs_screening&#34; relatedentityattr&#61;&#34;dhhs_screeningid&#34; primaryentityattr&#61;&#34;dhhs_screening&#34; relationshipid&#61;&#34;&#123;1b2060c5-8216-4c89-8859-64ac83c9692e&#125;&#34; relationshipname&#61;&#34;dhhs_screening_dhhs_screeningpersons&#34; &#47;&#62;&#60;&#47;row&#62;&#60;&#47;grid&#62;</layoutXml><otc>10249</otc><otn>dhhs_screeningpersons</otn><entitydisplayname>Screening person</entitydisplayname><titleformat>&#123;0&#125; &#123;1&#125;</titleformat><entitypluraldisplayname>Screening persons</entitypluraldisplayname><expandable>1</expandable><showjumpbar>0</showjumpbar><maxrowsbeforescroll>12</maxrowsbeforescroll><tabindex>14"
		"80</tabindex><refreshasynchronous>1</refreshasynchronous><subgridAutoExpand>0</subgridAutoExpand><relName>dhhs_incident_dhhs_screeningpersons_L17</relName><roleOrd>1</roleOrd><oType>112</oType><relationshipType>2</relationshipType><ribbonContext>SubGridStandard</ribbonContext><GridType>SubGrid</GridType><enableContextualActions>true</enableContextualActions><teamTemplateId></teamTemplateId><isWorkflowSupported>true</isWorkflowSupported><LoadOnDemand_GridEmptyMessage>To load &#123;0&#125; records, click here.</LoadOnDemand_GridEmptyMessage><enableFilters></enableFilters><InnerGridDisabled>0</InnerGridDisabled><oId>&#123;{oId}&#125;</oId><isTurboForm>1</isTurboForm></parameters><columns><column width=\"100\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Created&#32;on\" fieldname=\"createdon\" entityname=\"dhhs_screeningpersons\" type=\"DateTime.datetime\" sourcetype=\"0\">createdon</column><column width=\"125\" isHidden=\"false\" isMetadataBound=\"true"
		"\" isSortable=\"true\" label=\"Screening&#32;Ref&#32;number\" fieldname=\"dhhs_screening\" entityname=\"dhhs_screeningpersons\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Lookup\" sourcetype=\"0\">dhhs_screening</column><column width=\"125\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"L17&#32;screening&#32;ID&#32;&#40;Screening&#32;Ref&#32;number&#41;\" fieldname=\"dhhs_l17screeningid\" entityname=\"dhhs_screening\" imageproviderwebresource=\"&#36;webresource&#58;\" relationshipname=\"dhhs_screening_dhhs_screeningpersons\" type=\"String.text\" sourcetype=\"0\">a_a79cc2c4c1a7e7118148e0071b6d9931.dhhs_l17screeningid</column><column width=\"125\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Given&#32;names\" fieldname=\"dhhs_givennames\" entityname=\"dhhs_screeningpersons\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">dhhs_givennames</column><column width=\"125\" isHidden=\"false\" isMetadataBound="
		"\"true\" isSortable=\"true\" label=\"Last&#32;name\" fieldname=\"dhhs_lastname\" entityname=\"dhhs_screeningpersons\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">dhhs_lastname</column><column width=\"125\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Resolved&#32;name\" fieldname=\"dhhs_personid\" entityname=\"dhhs_screeningpersons\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Lookup\" sourcetype=\"0\">dhhs_personid</column><column width=\"100\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Role\" fieldname=\"dhhs_role\" entityname=\"dhhs_screeningpersons\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Picklist\" sourcetype=\"0\">dhhs_role</column><column width=\"100\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Children&#32;in&#32;family&#32;&#40;Screening&#32;Ref&#32;number&#41;\" fieldname=\"dhhs_childreninfamily\" entityname=\"dhhs_screening\" relationsh"
		"ipname=\"dhhs_screening_dhhs_screeningpersons\" type=\"Picklist\" sourcetype=\"0\">a_a79cc2c4c1a7e7118148e0071b6d9931.dhhs_childreninfamily</column><column width=\"100\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"L17&#32;PDF&#32;file&#32;&#40;Screening&#32;Ref&#32;number&#41;\" fieldname=\"dhhs_l17pdffile\" entityname=\"dhhs_screening\" relationshipname=\"dhhs_screening_dhhs_screeningpersons\" type=\"String.url\" sourcetype=\"0\">a_a79cc2c4c1a7e7118148e0071b6d9931.dhhs_l17pdffile</column></columns></grid>",
		LAST);

	web_custom_request("AppGridWebService.ashx_10",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/AppGridWebService.ashx?operation=Refresh",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t62.inf",
		"Mode=HTML",
		"EncType=text/plain;charset=UTF-8",
		"Body=<grid><sortColumns>record2roleid&#58;1</sortColumns><pageNum>1</pageNum><recsPerPage>10</recsPerPage><dataProvider>Microsoft.Crm.Application.Platform.Grid.GridDataProviderQueryBuilder</dataProvider><uiProvider>Microsoft.Crm.Application.Controls.GridUIProvider</uiProvider><cols/><max>1</max><refreshAsync>True</refreshAsync><pagingCookie/><enableMultiSort>true</enableMultiSort><enablePagingWhenOnePage>true</enablePagingWhenOnePage><refreshCalledFromRefreshButton>1</refreshCalledFromRefreshButton><returntotalrecordcount>true</returntotalrecordcount><getParameters></getParameters><parameters><viewid>&#123;BED5F444-0BD0-E711-A826-000D3AE0A6CF&#125;</viewid><RenderAsync>0</RenderAsync><LoadOnDemand>1</LoadOnDemand><autorefresh>1</autorefresh><isGridHidden>false</isGridHidden><LayoutStyle>LiteGridList</LayoutStyle><maxselectableitems>1</maxselectableitems><isGridFilteringEnabled>1</isGridFilteringEnabled><viewtype>1039</viewtype><viewts>3142864</viewts><RecordsPerPage>10</RecordsPerPage><viewTitle>Connections "
		"- Personal connections on Case</viewTitle><layoutXml>&#60;grid name&#61;&#34;resultset&#34; jump&#61;&#34;name&#34; select&#61;&#34;1&#34; preview&#61;&#34;1&#34; icon&#61;&#34;1&#34; object&#61;&#34;3234&#34;&#62;&#60;row id&#61;&#34;connectionid&#34; name&#61;&#34;result&#34;&#62;&#60;cell name&#61;&#34;record2roleid&#34; width&#61;&#34;200&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;record2id&#34; width&#61;&#34;200&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_liveswithperson&#34; width&#61;&#34;200&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_source_ofsupport&#34; width&#61;&#34;150&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell na"
		"me&#61;&#34;dhhs_accesscustodydetails&#34; width&#61;&#34;200&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;effectivestart&#34; width&#61;&#34;150&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;effectiveend&#34; width&#61;&#34;150&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;&#47;row&#62;&#60;&#47;grid&#62;</layoutXml><otc>3234</otc><otn>connection</otn><entitydisplayname>Connection</entitydisplayname><titleformat>&#123;0&#125; &#123;1&#125;</titleformat><entitypluraldisplayname>Connections</entitypluraldisplayname><expandable>1</expandable><showjumpbar>0</showjumpbar><maxrowsbeforescroll>12</maxrowsbeforescroll><tabindex>10</tabindex><refreshasynchronous>1</refreshasynchronous><subgridAutoExpand>0</subgridAutoExpand><relName>contact_connections1"
		"</relName><roleOrd>-1</roleOrd><oType>2</oType><relationshipType>1</relationshipType><ribbonContext>SubGridStandard</ribbonContext><GridType>SubGrid</GridType><enableContextualActions>true</enableContextualActions><teamTemplateId></teamTemplateId><isWorkflowSupported>true</isWorkflowSupported><LoadOnDemand_GridEmptyMessage>To load &#123;0&#125; records, click here.</LoadOnDemand_GridEmptyMessage><enableFilters></enableFilters><InnerGridDisabled>0</InnerGridDisabled><oId>&#123;{ClientOid}&#125;</oId><effectiveFetchXml>&#60;fetch distinct&#61;&#34;false&#34; no-lock&#61;&#34;false&#34; mapping&#61;&#34;logical&#34; page&#61;&#34;1&#34; count&#61;&#34;10&#34; returntotalrecordcount&#61;&#34;true&#34;&#62;&#60;entity name&#61;&#34;connection&#34;&#62;&#60;attribute name&#61;&#34;record2roleid&#34; &#47;&#62;&#60;attribute name&#61;&#34;record2id&#34; &#47;&#62;&#60;attribute name&#61;&#34;dhhs_liveswithperson&#34; &#47;&#62;&#60;attribute name&#61;&#34;dhhs_accesscustodydetails&#34; &#4"
		"7;&#62;&#60;attribute name&#61;&#34;effectivestart&#34; &#47;&#62;&#60;attribute name&#61;&#34;effectiveend&#34; &#47;&#62;&#60;attribute name&#61;&#34;dhhs_source_ofsupport&#34; &#47;&#62;&#60;attribute name&#61;&#34;connectionid&#34; &#47;&#62;&#60;attribute name&#61;&#34;record2roleid&#34; &#47;&#62;&#60;attribute name&#61;&#34;record2id&#34; &#47;&#62;&#60;attribute name&#61;&#34;dhhs_liveswithperson&#34; &#47;&#62;&#60;attribute name&#61;&#34;dhhs_source_ofsupport&#34; &#47;&#62;&#60;attribute name&#61;&#34;dhhs_accesscustodydetails&#34; &#47;&#62;&#60;attribute name&#61;&#34;effectivestart&#34; &#47;&#62;&#60;attribute name&#61;&#34;effectiveend&#34; &#47;&#62;&#60;filter type&#61;&#34;and&#34;&#62;&#60;condition attribute&#61;&#34;record1id&#34; operator&#61;&#34;eq&#34; value&#61;&#34;&#123;{ClientOid}&#125;&#34; &#47;&#62;&#60;filter type&#61;&#34;and&#34;&#62;&#60;condition attribute&#61;&#34;record2objecttypecode&#34; operator&#61;&#34;eq&#34; value&#61;&#34;2&#34; &#47;&"
		"#62;&#60;condition attribute&#61;&#34;record1objecttypecode&#34; operator&#61;&#34;eq&#34; value&#61;&#34;2&#34; &#47;&#62;&#60;&#47;filter&#62;&#60;&#47;filter&#62;&#60;order attribute&#61;&#34;record2roleid&#34; descending&#61;&#34;false&#34; &#47;&#62;&#60;&#47;entity&#62;&#60;&#47;fetch&#62;</effectiveFetchXml><isFetchXmlNotFinal>False</isFetchXmlNotFinal><fetchXmlForFilters>&#60;fetch version&#61;&#34;1.0&#34; output-format&#61;&#34;xml-platform&#34; mapping&#61;&#34;logical&#34; distinct&#61;&#34;false&#34;&#62;&#60;entity name&#61;&#34;connection&#34;&#62;&#60;attribute name&#61;&#34;record2roleid&#34; &#47;&#62;&#60;attribute name&#61;&#34;record2id&#34; &#47;&#62;&#60;attribute name&#61;&#34;dhhs_liveswithperson&#34; &#47;&#62;&#60;attribute name&#61;&#34;dhhs_accesscustodydetails&#34; &#47;&#62;&#60;attribute name&#61;&#34;effectivestart&#34; &#47;&#62;&#60;attribute name&#61;&#34;effectiveend&#34; &#47;&#62;&#60;order attribute&#61;&#34;record2roleid&#34; descending&#61;&#34;false&#34; &#47;&#62;"
		"&#60;filter type&#61;&#34;and&#34;&#62;&#60;filter type&#61;&#34;and&#34;&#62;&#60;condition value&#61;&#34;2&#34; attribute&#61;&#34;record2objecttypecode&#34; operator&#61;&#34;eq&#34; &#47;&#62;&#60;condition value&#61;&#34;2&#34; attribute&#61;&#34;record1objecttypecode&#34; operator&#61;&#34;eq&#34; &#47;&#62;&#60;&#47;filter&#62;&#60;&#47;filter&#62;&#60;attribute name&#61;&#34;dhhs_source_ofsupport&#34; &#47;&#62;&#60;attribute name&#61;&#34;connectionid&#34; &#47;&#62;&#60;&#47;entity&#62;&#60;&#47;fetch&#62;</fetchXmlForFilters><isTurboForm>1</isTurboForm></parameters><columns><column width=\"200\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Role&#32;&#40;To&#41;\" fieldname=\"record2roleid\" entityname=\"connection\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Lookup\" sourcetype=\"0\">record2roleid</column><column width=\"200\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Connected&#32;to\" fieldname=\"record2id\" entityname=\"c"
		"onnection\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Lookup.connection\" sourcetype=\"0\">record2id</column><column width=\"200\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Lives&#32;with&#32;person\" fieldname=\"dhhs_liveswithperson\" entityname=\"connection\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">dhhs_liveswithperson</column><column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Source&#32;of&#32;support\" fieldname=\"dhhs_source_ofsupport\" entityname=\"connection\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Picklist\" sourcetype=\"0\">dhhs_source_ofsupport</column><column width=\"200\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Access&#47;Custody&#32;details\" fieldname=\"dhhs_accesscustodydetails\" entityname=\"connection\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">dhhs_accesscus"
		"todydetails</column><column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Start&#32;date\" fieldname=\"effectivestart\" entityname=\"connection\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"DateTime.date\" sourcetype=\"0\">effectivestart</column><column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"End&#32;date\" fieldname=\"effectiveend\" entityname=\"connection\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"DateTime.date\" sourcetype=\"0\">effectiveend</column></columns></grid>",
		LAST);

	web_custom_request("AppGridWebService.ashx_11",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/AppGridWebService.ashx?operation=Refresh",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t63.inf",
		"Mode=HTML",
		"EncType=text/plain;charset=UTF-8",
		"Body=<grid><sortColumns>modifiedon&#58;0</sortColumns><pageNum>1</pageNum><recsPerPage>8</recsPerPage><dataProvider>Microsoft.Crm.Application.Platform.Grid.GridDataProviderQueryBuilder</dataProvider><uiProvider>Microsoft.Crm.Application.Controls.GridUIProvider</uiProvider><cols/><max>1</max><refreshAsync>True</refreshAsync><pagingCookie/><enableMultiSort>true</enableMultiSort><enablePagingWhenOnePage>true</enablePagingWhenOnePage><refreshCalledFromRefreshButton>1</refreshCalledFromRefreshButton><returntotalrecordcount>true</returntotalrecordcount><getParameters>getFetchXmlForFilters</getParameters><parameters><viewid>&#123;00000000-0000-0000-00AA-000010001046&#125;</viewid><RenderAsync>0</RenderAsync><LoadOnDemand>1</LoadOnDemand><autorefresh>1</autorefresh><isGridHidden>false</isGridHidden><LayoutStyle>LiteGridList</LayoutStyle><maxselectableitems>1</maxselectableitems><isGridFilteringEnabled>1</isGridFilteringEnabled><viewtype>1039</viewtype><viewts>3217864</viewts><RecordsPerPage>8</RecordsPerPage><viewTi"
		"tle>Similar Resolved Cases</viewTitle><layoutXml>&#60;grid name&#61;&#34;resultset&#34; object&#61;&#34;112&#34; jump&#61;&#34;title&#34; select&#61;&#34;1&#34; icon&#61;&#34;1&#34; preview&#61;&#34;1&#34;&#62;&#60;row name&#61;&#34;result&#34; id&#61;&#34;incidentid&#34;&#62;&#60;cell name&#61;&#34;title&#34; &#47;&#62;&#60;cell name&#61;&#34;caseorigincode&#34; width&#61;&#34;100&#34; ishidden&#61;&#34;1&#34; &#47;&#62;&#60;&#47;row&#62;&#60;&#47;grid&#62;</layoutXml><otc>112</otc><otn>incident</otn><entitydisplayname>Case</entitydisplayname><titleformat>&#123;0&#125; &#123;1&#125;</titleformat><entitypluraldisplayname>Cases</entitypluraldisplayname><expandable>1</expandable><showjumpbar>0</showjumpbar><maxrowsbeforescroll>13</maxrowsbeforescroll><tabindex>1590</tabindex><refreshasynchronous>1</refreshasynchronous><subgridAutoExpand>1</subgridAutoExpand><relName></relName><roleOrd></roleOrd><oType>112</oType><relationshipType>0</relationshipType><ribbonContext>SubGridStandard</ribbonContext><GridType>SubG"
		"rid</GridType><enableContextualActions>False</enableContextualActions><teamTemplateId></teamTemplateId><isWorkflowSupported>true</isWorkflowSupported><LoadOnDemand_GridEmptyMessage>To load &#123;0&#125; records, click here.</LoadOnDemand_GridEmptyMessage><enableFilters></enableFilters><InnerGridDisabled>0</InnerGridDisabled><oId>&#123;{oId}&#125;</oId><isTurboForm>1</isTurboForm></parameters><columns><column width=\"300\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Case&#32;title\" fieldname=\"title\" entityname=\"incident\" renderertype=\"Crm.PrimaryField\" type=\"String.text\" sourcetype=\"0\">title</column><column width=\"0\" isHidden=\"true\" isMetadataBound=\"true\" isSortable=\"false\" label=\"Origin\" fieldname=\"caseorigincode\" entityname=\"incident\" type=\"Picklist\" sourcetype=\"0\">caseorigincode</column></columns></grid>",
		LAST);

	web_custom_request("AppGridWebService.ashx_12",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/AppGridWebService.ashx?operation=Refresh",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t64.inf",
		"Mode=HTML",
		"EncType=text/plain;charset=UTF-8",
		"Body=<grid><sortColumns>dhhs_name&#58;1</sortColumns><pageNum>1</pageNum><recsPerPage>10</recsPerPage><dataProvider>Microsoft.Crm.Application.Platform.Grid.GridDataProviderQueryBuilder</dataProvider><uiProvider>Microsoft.Crm.Application.Controls.GridUIProvider</uiProvider><cols/><max>1</max><refreshAsync>True</refreshAsync><pagingCookie/><enableMultiSort>true</enableMultiSort><enablePagingWhenOnePage>true</enablePagingWhenOnePage><refreshCalledFromRefreshButton>1</refreshCalledFromRefreshButton><returntotalrecordcount>true</returntotalrecordcount><getParameters></getParameters><parameters><viewid>&#123;F271F05E-2DD3-E711-A825-000D3AE0CB84&#125;</viewid><RenderAsync>0</RenderAsync><LoadOnDemand>1</LoadOnDemand><autorefresh>1</autorefresh><isGridHidden>false</isGridHidden><LayoutStyle>LiteGridList</LayoutStyle><maxselectableitems>1</maxselectableitems><isGridFilteringEnabled>1</isGridFilteringEnabled><viewtype>1039</viewtype><viewts>3142978</viewts><RecordsPerPage>10</RecordsPerPage><viewTitle>Alerts on Case</"
		"viewTitle><layoutXml>&#60;grid name&#61;&#34;resultset&#34; jump&#61;&#34;dhhs_name&#34; select&#61;&#34;1&#34; preview&#61;&#34;1&#34; icon&#61;&#34;1&#34; object&#61;&#34;10213&#34;&#62;&#60;row name&#61;&#34;result&#34; id&#61;&#34;dhhs_alertid&#34;&#62;&#60;cell name&#61;&#34;createdon&#34; width&#61;&#34;150&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_name&#34; width&#61;&#34;300&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_type&#34; width&#61;&#34;200&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_enddate&#34; width&#61;&#34;125&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;statuscode&#34; width&#61;&#34;100&#34"
		"; &#47;&#62;&#60;cell name&#61;&#34;ownerid&#34; width&#61;&#34;200&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;&#47;row&#62;&#60;&#47;grid&#62;</layoutXml><otc>10213</otc><otn>dhhs_alert</otn><entitydisplayname>Alert</entitydisplayname><titleformat>&#123;0&#125; &#123;1&#125;</titleformat><entitypluraldisplayname>Alerts</entitypluraldisplayname><expandable>1</expandable><showjumpbar>0</showjumpbar><maxrowsbeforescroll>12</maxrowsbeforescroll><tabindex>10</tabindex><refreshasynchronous>1</refreshasynchronous><subgridAutoExpand>0</subgridAutoExpand><relName>dhhs_contact_dhhs_alert_PersonorClient</relName><roleOrd>-1</roleOrd><oType>2</oType><relationshipType>1</relationshipType><ribbonContext>SubGridStandard</ribbonContext><GridType>SubGrid</GridType><enableContextualActions>true</enableContextualActions><teamTemplateId></teamTemplateId><isWorkflowSupported>true</isWorkflowSupported><LoadOnDemand_GridEmptyMessage>To load &#123;0&#1"
		"25; records, click here.</LoadOnDemand_GridEmptyMessage><enableFilters></enableFilters><InnerGridDisabled>0</InnerGridDisabled><oId>&#123;{ClientOid}&#125;</oId><effectiveFetchXml>&#60;fetch distinct&#61;&#34;false&#34; no-lock&#61;&#34;false&#34; mapping&#61;&#34;logical&#34; page&#61;&#34;1&#34; count&#61;&#34;10&#34; returntotalrecordcount&#61;&#34;true&#34;&#62;&#60;entity name&#61;&#34;dhhs_alert&#34;&#62;&#60;attribute name&#61;&#34;dhhs_name&#34; &#47;&#62;&#60;attribute name&#61;&#34;createdon&#34; &#47;&#62;&#60;attribute name&#61;&#34;dhhs_type&#34; &#47;&#62;&#60;attribute name&#61;&#34;dhhs_enddate&#34; &#47;&#62;&#60;attribute name&#61;&#34;statuscode&#34; &#47;&#62;&#60;attribute name&#61;&#34;ownerid&#34; &#47;&#62;&#60;attribute name&#61;&#34;dhhs_alertid&#34; &#47;&#62;&#60;attribute name&#61;&#34;createdon&#34; &#47;&#62;&#60;attribute name&#61;&#34;dhhs_name&#34; &#47;&#62;&#60;attribute name&#61;&#34;dhhs_type&#34; &#47;&#62;&#60;attribute name&#61;&#34;dhhs_endd"
		"ate&#34; &#47;&#62;&#60;attribute name&#61;&#34;statuscode&#34; &#47;&#62;&#60;attribute name&#61;&#34;ownerid&#34; &#47;&#62;&#60;filter type&#61;&#34;and&#34;&#62;&#60;condition attribute&#61;&#34;statecode&#34; operator&#61;&#34;eq&#34; value&#61;&#34;0&#34; &#47;&#62;&#60;condition attribute&#61;&#34;dhhs_personorclient&#34; operator&#61;&#34;eq&#34; value&#61;&#34;&#123;{ClientOid}&#125;&#34; &#47;&#62;&#60;&#47;filter&#62;&#60;order attribute&#61;&#34;dhhs_name&#34; descending&#61;&#34;false&#34; &#47;&#62;&#60;&#47;entity&#62;&#60;&#47;fetch&#62;</effectiveFetchXml><isFetchXmlNotFinal>False</isFetchXmlNotFinal><fetchXmlForFilters>&#60;fetch version&#61;&#34;1.0&#34; output-format&#61;&#34;xml-platform&#34; mapping&#61;&#34;logical&#34; distinct&#61;&#34;false&#34;&#62;&#60;entity name&#61;&#34;dhhs_alert&#34;&#62;&#60;attribute name&#61;&#34;dhhs_name&#34; &#47;&#62;&#60;attribute name&#61;&#34;createdon&#34; &#47;&#62;&#60;attribute name&#61;&#34;dhhs_type&#34; &#47;&#62;&#6"
		"0;attribute name&#61;&#34;dhhs_enddate&#34; &#47;&#62;&#60;attribute name&#61;&#34;statuscode&#34; &#47;&#62;&#60;attribute name&#61;&#34;ownerid&#34; &#47;&#62;&#60;order attribute&#61;&#34;dhhs_name&#34; descending&#61;&#34;false&#34; &#47;&#62;&#60;filter type&#61;&#34;and&#34;&#62;&#60;condition attribute&#61;&#34;statecode&#34; operator&#61;&#34;eq&#34; value&#61;&#34;0&#34; &#47;&#62;&#60;&#47;filter&#62;&#60;attribute name&#61;&#34;dhhs_alertid&#34; &#47;&#62;&#60;&#47;entity&#62;&#60;&#47;fetch&#62;</fetchXmlForFilters><isTurboForm>1</isTurboForm></parameters><columns><column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Created&#32;on\" fieldname=\"createdon\" entityname=\"dhhs_alert\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"DateTime.datetime\" sourcetype=\"0\">createdon</column><column width=\"300\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Subject\" fieldname=\"dhhs_name\" entityname=\"dhhs_alert\" renderertyp"
		"e=\"Crm.PrimaryField\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">dhhs_name</column><column width=\"200\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Type\" fieldname=\"dhhs_type\" entityname=\"dhhs_alert\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Picklist\" sourcetype=\"0\">dhhs_type</column><column width=\"125\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"End&#32;date\" fieldname=\"dhhs_enddate\" entityname=\"dhhs_alert\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"DateTime.date\" sourcetype=\"0\">dhhs_enddate</column><column width=\"100\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Status\" fieldname=\"statuscode\" entityname=\"dhhs_alert\" type=\"Status\" sourcetype=\"0\">statuscode</column><column width=\"200\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Owner\" fieldname=\"ownerid\" entityname=\"dhhs_alert\" imagepr"
		"oviderwebresource=\"&#36;webresource&#58;\" type=\"Owner\" sourcetype=\"0\">ownerid</column></columns></grid>",
		LAST);

	web_revert_auto_header("CRMWRPCToken");

	web_revert_auto_header("CRMWRPCTokenTimeStamp");

	web_revert_auto_header("Cache-Control");

	web_revert_auto_header("ReferrerReqId");

	web_revert_auto_header("FormLoadId");

	web_add_header("CRMWRPCTokenTimeStamp",
		"{CorrelationParameter_53}");

	web_add_auto_header("Cache-Control", 
		"no-cache");

	web_add_auto_header("FormLoadId", 
		"{90e54e86-12d1-3a6b-32ae-82426864576d}");

	web_add_auto_header("ReferrerReqId",
		"{CorrelationParameter_36}");

	web_custom_request("AppGridWebService.ashx_13",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/AppGridWebService.ashx?operation=Refresh",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t65.inf",
		"Mode=HTML",
		"EncType=text/plain;charset=UTF-8",
		"Body=<grid><sortColumns>title&#58;1</sortColumns><pageNum>1</pageNum><recsPerPage>10</recsPerPage><dataProvider>Microsoft.Crm.Application.Platform.Grid.GridDataProviderQueryBuilder</dataProvider><uiProvider>Microsoft.Crm.Application.Controls.GridUIProvider</uiProvider><cols/><max>1</max><refreshAsync>True</refreshAsync><pagingCookie/><enableMultiSort>true</enableMultiSort><enablePagingWhenOnePage>true</enablePagingWhenOnePage><refreshCalledFromRefreshButton>1</refreshCalledFromRefreshButton><returntotalrecordcount>true</returntotalrecordcount><getParameters></getParameters><parameters><viewid>&#123;20C1857E-BCBE-E711-814B-E0071B6D9931&#125;</viewid><RenderAsync>0</RenderAsync><LoadOnDemand>1</LoadOnDemand><autorefresh>1</autorefresh><isGridHidden>false</isGridHidden><LayoutStyle>LiteGridList</LayoutStyle><maxselectableitems>1</maxselectableitems><isGridFilteringEnabled>1</isGridFilteringEnabled><viewtype>1039</viewtype><viewts>3144117</viewts><RecordsPerPage>10</RecordsPerPage><viewTitle>Main Clients</viewTi"
		"tle><layoutXml>&#60;grid name&#61;&#34;resultset&#34; jump&#61;&#34;title&#34; select&#61;&#34;1&#34; preview&#61;&#34;1&#34; icon&#61;&#34;1&#34; object&#61;&#34;112&#34;&#62;&#60;row name&#61;&#34;result&#34; id&#61;&#34;incidentid&#34;&#62;&#60;cell name&#61;&#34;customerid&#34; width&#61;&#34;200&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;title&#34; width&#61;&#34;200&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;&#47;row&#62;&#60;&#47;grid&#62;</layoutXml><otc>112</otc><otn>incident</otn><entitydisplayname>Case</entitydisplayname><titleformat>&#123;0&#125; &#123;1&#125;</titleformat><entitypluraldisplayname>Cases</entitypluraldisplayname><expandable>1</expandable><showjumpbar>0</showjumpbar><maxrowsbeforescroll>12</maxrowsbeforescroll><tabindex>30</tabindex><refreshasynchronous>1</refreshasynchronous><subgridAutoExpand>0</subgridAu"
		"toExpand><relName>dhhs_casegroup_incident_Casegroupsid</relName><roleOrd>-1</roleOrd><oType>10217</oType><relationshipType>1</relationshipType><ribbonContext>SubGridStandard</ribbonContext><GridType>SubGrid</GridType><enableContextualActions>true</enableContextualActions><teamTemplateId></teamTemplateId><isWorkflowSupported>true</isWorkflowSupported><LoadOnDemand_GridEmptyMessage>To load &#123;0&#125; records, click here.</LoadOnDemand_GridEmptyMessage><enableFilters></enableFilters><InnerGridDisabled>0</InnerGridDisabled><oId>&#123;{GroupOid}&#125;</oId><effectiveFetchXml>&#60;fetch distinct&#61;&#34;false&#34; no-lock&#61;&#34;false&#34; mapping&#61;&#34;logical&#34; page&#61;&#34;1&#34; count&#61;&#34;10&#34; returntotalrecordcount&#61;&#34;true&#34;&#62;&#60;entity name&#61;&#34;incident&#34;&#62;&#60;attribute name&#61;&#34;customerid&#34; &#47;&#62;&#60;attribute name&#61;&#34;title&#34; &#47;&#62;&#60;attribute name&#61;&#34;incidentid&#34; &#47;&#62;&#60;attribute name&#61;"
		"&#34;processid&#34; &#47;&#62;&#60;attribute name&#61;&#34;customerid&#34; &#47;&#62;&#60;attribute name&#61;&#34;title&#34; &#47;&#62;&#60;filter type&#61;&#34;and&#34;&#62;&#60;condition attribute&#61;&#34;dhhs_casegroupsid&#34; operator&#61;&#34;eq&#34; value&#61;&#34;&#123;{GroupOid}&#125;&#34; &#47;&#62;&#60;&#47;filter&#62;&#60;order attribute&#61;&#34;title&#34; descending&#61;&#34;false&#34; &#47;&#62;&#60;link-entity name&#61;&#34;workflow&#34; to&#61;&#34;processid&#34; from&#61;&#34;workflowid&#34; link-type&#61;&#34;outer&#34; alias&#61;&#34;processidworkflowworkflowid&#34;&#62;&#60;attribute name&#61;&#34;versionnumber&#34; &#47;&#62;&#60;&#47;link-entity&#62;&#60;&#47;entity&#62;&#60;&#47;fetch&#62;</effectiveFetchXml><isFetchXmlNotFinal>False</isFetchXmlNotFinal><fetchXmlForFilters>&#60;fetch version&#61;&#34;1.0&#34; output-format&#61;&#34;xml-platform&#34; mapping&#61;&#34;logical&#34;&#62;&#60;entity name&#61;&#34;incident&#34;&#62;&#60;order attribute&#61;&#34;ti"
		"tle&#34; descending&#61;&#34;false&#34; &#47;&#62;&#60;attribute name&#61;&#34;customerid&#34; &#47;&#62;&#60;attribute name&#61;&#34;title&#34; &#47;&#62;&#60;attribute name&#61;&#34;incidentid&#34; &#47;&#62;&#60;attribute name&#61;&#34;processid&#34; &#47;&#62;&#60;link-entity alias&#61;&#34;processidworkflowworkflowid&#34; name&#61;&#34;workflow&#34; from&#61;&#34;workflowid&#34; to&#61;&#34;processid&#34; link-type&#61;&#34;outer&#34; visible&#61;&#34;false&#34;&#62;&#60;attribute name&#61;&#34;versionnumber&#34; &#47;&#62;&#60;&#47;link-entity&#62;&#60;&#47;entity&#62;&#60;&#47;fetch&#62;</fetchXmlForFilters><isTurboForm>1</isTurboForm></parameters><columns><column width=\"200\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Client\" fieldname=\"customerid\" entityname=\"incident\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Customer\" sourcetype=\"0\">customerid</column><column width=\"200\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label="
		"\"Case&#32;title\" fieldname=\"title\" entityname=\"incident\" renderertype=\"Crm.PrimaryField\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">title</column></columns></grid>",
		LAST);

	web_revert_auto_header("Cache-Control");

	web_revert_auto_header("ReferrerReqId");

	web_add_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/ReloadCommandBar");

	web_custom_request("Ribbon.asmx",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/Ribbon.asmx",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t66.inf",
		"Mode=HTML",
		"EncType=text/xml; charset=utf-8",
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\" ?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><ReloadCommandBar xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><hierarchyLocation>{formid}</hierarchyLocation><entityLogicalName>incident</entityLogicalName><ribbonContext>Form</ribbonContext><pageId>HTTPS&#58;&#47;&#47;.CRM6.DYNAMICS.COM&#47;FORM&#47;PAGE.ASPX&#63;APPID&#61;AB18C93F-61E6-E711-A848-000D3AD117E3&#38;LCID&#61;1033&#38;THEMEID&#61;6706240E-D78B-4278-814E-FDB8C89F220F&#38;TSTAMP&#61;{tstamp}&#38;UPDATETIMESTAMP&#61;{updateTimeStamp}&#38;USERTS&#61;{userts}&#38;VER&#61;-2068631631&#35;APPID&#61;AB18C93F-61E6-E711-A848-000D3AD117E3&#38;ETC&#61;112&#38;EXTRAQS&#61;&#37;3FETC&#37;3D112&#37;26FORMID&#37;3D2286CEF5-5237-4A7F-9023-41AD0AF2B9B6&#38;PAGEMODE&#61;IFRAME&#38;PAGETYPE&#61;ENTITYRECORD&#38;COUNTER&#61;1522024942876</pageId><record"
		"Id>&#123;{oId}&#125;</recordId><formState>2</formState><status>1</status></ReloadCommandBar></soap:Body></soap:Envelope>",
		LAST);

	web_add_auto_header("Accept", 
		"application/xml, text/xml, */*; q=0.01");

	web_revert_auto_header("FormLoadId");

	web_add_header("ReferrerReqId",
		"{CorrelationParameter_36}");

	web_add_auto_header("Cache-Control", 
		"no-cache");

	web_add_header("FormLoadId", 
		"{90e54e86-12d1-3a6b-32ae-82426864576d}");

	web_add_header("SOAPAction", 
		"http://schemas.microsoft.com/xrm/2011/Contracts/Services/IOrganizationService/Execute");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("web",
		"URL=https://{param_URL}.crm6.dynamics.com/XRMServices/2011/Organization.svc/web",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t67.inf",
		"Mode=HTML",
		"EncType=text/xml; charset=utf-8",
		"Body=<s:Envelope xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\"><s:Body><Execute xmlns=\"http://schemas.microsoft.com/xrm/2011/Contracts/Services\"><request i:type=\"a:OrganizationRequest\" xmlns:a=\"http://schemas.microsoft.com/xrm/2011/Contracts\" xmlns:i=\"http://www.w3.org/2001/XMLSchema-instance\"><a:Parameters xmlns:b=\"http://schemas.datacontract.org/2004/07/System.Collections.Generic\"><a:KeyValuePairOfstringanyType><b:key>Entity</b:key><b:value i:type=\"a:EntityReference\"><a:Id>{oId}</a:Id><a:LogicalName>incident</a:LogicalName><a:Name i:nil=\"true\" /></b:value></a:KeyValuePairOfstringanyType><a:KeyValuePairOfstringanyType><b:key>PageSize</b:key><b:value i:type=\"d:int\" xmlns:d=\"http://www.w3.org/2001/XMLSchema\">10</b:value></a:KeyValuePairOfstringanyType><a:KeyValuePairOfstringanyType><b:key>PageNumber</b:key><b:value i:type=\"d:int\" xmlns:d=\"http://www.w3.org/2001/XMLSchema\">1</b:value></a:KeyValuePairOfstringanyType><a:KeyValuePairOfstringanyType><b:k"
		"ey>CommentsPerPost</b:key><b:value i:type=\"d:int\" xmlns:d=\"http://www.w3.org/2001/XMLSchema\">2</b:value></a:KeyValuePairOfstringanyType></a:Parameters><a:RequestId i:nil=\"true\"/><a:RequestName>RetrieveRecordWall</a:RequestName></request></Execute></s:Body></s:Envelope>",
		LAST);

	web_add_auto_header("Accept", 
		"*/*");

	web_revert_auto_header("Cache-Control");

	web_add_header("ReferrerReqId",
		"{CorrelationParameter_24}");

	web_custom_request("AppGridWebService.ashx_14", 
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/AppGridWebService.ashx?operation=Refresh", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{param_URL}.crm6.dynamics.com/_root/homepage.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&etc=112&pagemode=iframe&sitemappath=area_service%7cPeople%7cNewSubArea_b823cecf&viewid=%7b00000000-0000-0000-00AA-000010001032%7d", 
		"Snapshot=t68.inf", 
		"Mode=HTML", 
		"EncType=text/plain;charset=UTF-8", 
		"Body=<grid><sortColumns>title&#58;1</sortColumns><pageNum>1</pageNum><recsPerPage>50</recsPerPage><dataProvider>Microsoft.Crm.Service.Application.Controls.CasesGridDataProvider</dataProvider><uiProvider>Microsoft.Crm.Application.Controls.GridUIProvider</uiProvider><cols/><max>-1</max><refreshAsync>False</refreshAsync><pagingCookie/><enableMultiSort>true</enableMultiSort><enablePagingWhenOnePage>true</enablePagingWhenOnePage><refreshCalledFromRefreshButton>1</refreshCalledFromRefreshButton>"
		"<returntotalrecordcount>true</returntotalrecordcount><getParameters></getParameters><parameters><autorefresh>1</autorefresh><isGridHidden>false</isGridHidden><isGridFilteringEnabled>1</isGridFilteringEnabled><viewid>&#123;00000000-0000-0000-00AA-000010001028&#125;</viewid><viewtype>1039</viewtype><RecordsPerPage>50</RecordsPerPage><viewTitle>My Active Cases</viewTitle><layoutXml>&#60;grid name&#61;&#34;resultset&#34; jump&#61;&#34;title&#34; select&#61;&#34;1&#34; icon&#61;&#34;1&#34; preview&#61;"
		"&#34;1&#34; object&#61;&#34;112&#34;&#62;&#60;row name&#61;&#34;result&#34; id&#61;&#34;incidentid&#34;&#62;&#60;cell name&#61;&#34;ticketnumber&#34; width&#61;&#34;150&#34; &#47;&#62;&#60;cell name&#61;&#34;title&#34; width&#61;&#34;150&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;customerid&#34; width&#61;&#34;100&#34; &#47;&#62;&#60;cell name&#61;&#34;casetypecode&#34; width&#61;&#34;100&#34; &#47;&"
		"#62;&#60;&#47;row&#62;&#60;&#47;grid&#62;</layoutXml><otc>112</otc><otn>incident</otn><entitydisplayname>Case</entitydisplayname><titleformat>&#123;0&#125; &#123;1&#125;</titleformat><entitypluraldisplayname>Cases</entitypluraldisplayname><isWorkflowSupported>true</isWorkflowSupported><fetchXmlForFilters>&#60;fetch version&#61;&#34;1.0&#34; output-format&#61;&#34;xml-platform&#34; mapping&#61;&#34;logical&#34;&#62;&#60;entity name&#61;&#34;incident&#34;&#62;&#60;attribute name&#61;&#34;"
		"ticketnumber&#34; &#47;&#62;&#60;attribute name&#61;&#34;title&#34; &#47;&#62;&#60;order attribute&#61;&#34;title&#34; descending&#61;&#34;false&#34; &#47;&#62;&#60;filter type&#61;&#34;and&#34;&#62;&#60;condition attribute&#61;&#34;ownerid&#34; operator&#61;&#34;eq-userid&#34; &#47;&#62;&#60;condition attribute&#61;&#34;statecode&#34; operator&#61;&#34;eq&#34; value&#61;&#34;0&#34; &#47;&#62;&#60;&#47;filter&#62;&#60;attribute name&#61;&#34;customerid&#34; &#47;&#62;&#60;attribute name&#61;&#34;"
		"casetypecode&#34; &#47;&#62;&#60;attribute name&#61;&#34;incidentid&#34; &#47;&#62;&#60;attribute name&#61;&#34;processid&#34; &#47;&#62;&#60;link-entity alias&#61;&#34;processidworkflowworkflowid&#34; name&#61;&#34;workflow&#34; from&#61;&#34;workflowid&#34; to&#61;&#34;processid&#34; link-type&#61;&#34;outer&#34; visible&#61;&#34;false&#34;&#62;&#60;attribute name&#61;&#34;versionnumber&#34; &#47;&#62;&#60;&#47;link-entity&#62;&#60;&#47;entity&#62;&#60;&#47;fetch&#62;</fetchXmlForFilters>"
		"<isFetchXmlNotFinal>False</isFetchXmlNotFinal><effectiveFetchXml>&#60;fetch distinct&#61;&#34;false&#34; no-lock&#61;&#34;false&#34; mapping&#61;&#34;logical&#34; page&#61;&#34;1&#34; count&#61;&#34;50&#34; returntotalrecordcount&#61;&#34;true&#34;&#62;&#60;entity name&#61;&#34;incident&#34;&#62;&#60;attribute name&#61;&#34;ticketnumber&#34; &#47;&#62;&#60;attribute name&#61;&#34;title&#34; &#47;&#62;&#60;attribute name&#61;&#34;customerid&#34; &#47;&#62;&#60;attribute name&#61;&#34;casetypecode&"
		"#34; &#47;&#62;&#60;attribute name&#61;&#34;incidentid&#34; &#47;&#62;&#60;attribute name&#61;&#34;processid&#34; &#47;&#62;&#60;attribute name&#61;&#34;ticketnumber&#34; &#47;&#62;&#60;attribute name&#61;&#34;title&#34; &#47;&#62;&#60;attribute name&#61;&#34;customerid&#34; &#47;&#62;&#60;attribute name&#61;&#34;casetypecode&#34; &#47;&#62;&#60;attribute name&#61;&#34;caseorigincode&#34; &#47;&#62;&#60;filter type&#61;&#34;and&#34;&#62;&#60;condition attribute&#61;&#34;ownerid&#34; operator&#61;&"
		"#34;eq-userid&#34; &#47;&#62;&#60;condition attribute&#61;&#34;statecode&#34; operator&#61;&#34;eq&#34; value&#61;&#34;0&#34; &#47;&#62;&#60;&#47;filter&#62;&#60;order attribute&#61;&#34;title&#34; descending&#61;&#34;false&#34; &#47;&#62;&#60;link-entity name&#61;&#34;workflow&#34; to&#61;&#34;processid&#34; from&#61;&#34;workflowid&#34; link-type&#61;&#34;outer&#34; alias&#61;&#34;processidworkflowworkflowid&#34;&#62;&#60;attribute name&#61;&#34;versionnumber&#34; &#47;&#62;&#60;&#47;link-entity"
		"&#62;&#60;&#47;entity&#62;&#60;&#47;fetch&#62;</effectiveFetchXml><LayoutStyle>GridList</LayoutStyle><enableFilters>1</enableFilters><isTurboForm>0</isTurboForm></parameters><columns><column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Case&#32;ID\" fieldname=\"ticketnumber\" entityname=\"incident\" renderertype=\"nvarchar\" type=\"String.text\" sourcetype=\"0\">ticketnumber</column><column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" "
		"isSortable=\"true\" label=\"Case&#32;title\" fieldname=\"title\" entityname=\"incident\" renderertype=\"Crm.PrimaryField\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">title</column><column width=\"100\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Client\" fieldname=\"customerid\" entityname=\"incident\" renderertype=\"customer\" type=\"Customer\" sourcetype=\"0\">customerid</column><column width=\"100\" isHidden=\"false\" "
		"isMetadataBound=\"true\" isSortable=\"true\" label=\"Case&#32;type\" fieldname=\"casetypecode\" entityname=\"incident\" renderertype=\"picklist\" type=\"Picklist\" sourcetype=\"0\">casetypecode</column></columns></grid>", 
		LAST);

	web_add_auto_header("Accept", 
		"application/xml, text/xml, */*; q=0.01");

	web_add_auto_header("Cache-Control", 
		"no-cache");

	web_add_auto_header("FormLoadId", 
		"{90e54e86-12d1-3a6b-32ae-82426864576d}");

	web_add_auto_header("ReferrerReqId",
		"{CorrelationParameter_36}");

	web_add_header("SOAPAction", 
		"http://schemas.microsoft.com/xrm/2011/Contracts/Services/IOrganizationService/Execute");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("web_2",
		"URL=https://{param_URL}.crm6.dynamics.com/XRMServices/2011/Organization.svc/web",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t69.inf",
		"Mode=HTML",
		"EncType=text/xml; charset=utf-8",
		"Body=<s:Envelope xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\"><s:Body><Execute xmlns=\"http://schemas.microsoft.com/xrm/2011/Contracts/Services\" xmlns:i=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:c=\"http://www.w3.org/2001/XMLSchema\"><request xmlns:a=\"http://schemas.microsoft.com/xrm/2011/Contracts\"><a:Parameters xmlns:b=\"http://schemas.datacontract.org/2004/07/System.Collections.Generic\"><a:KeyValuePairOfstringanyType><b:key>Query</b:key><b:value i:type=\"a:FetchExpression\"><a:Query>&#60;fetch version&#61;&#39;1.0&#39; output-format&#61;&#39;xml-platform&#39; mapping&#61;&#39;logical&#39; distinct&#61;&#39;true&#39;&#62;&#60;entity name&#61;&#39;systemuser&#39;&#62;&#60;filter type&#61;&#39;or&#39;&#62;&#60;condition attribute&#61;&#39;systemuserid&#39; operator&#61;&#39;eq&#39; value&#61;&#39;9831cb82-0834-41fa-b0a9-989a0da4f4de&#39; &#47;&#62;&#60;&#47;filter&#62;&#60;attribute name&#61;&#39;systemuserid&#39; &#47;&#62;&#60;attribute name&#61;&#39;entityimage_url&#39; &#47;&#62;&#"
		"60;&#47;entity&#62;&#60;&#47;fetch&#62;</a:Query></b:value></a:KeyValuePairOfstringanyType></a:Parameters><a:RequestId i:nil=\"true\" /><a:RequestName>RetrieveMultiple</a:RequestName></request></Execute></s:Body></s:Envelope>",
		LAST);

	web_add_auto_header("Accept", 
		"*/*");

	web_revert_auto_header("Cache-Control");

	web_revert_auto_header("FormLoadId");

	web_revert_auto_header("ReferrerReqId");

	web_add_header("CRMWRPCToken", 
		lr_eval_string("{path3}"));

	web_add_header("CRMWRPCTokenTimeStamp",
		"{CorrelationParameter_53}");

	//lr_start_transaction("CRM_06_CreateCase_06_TAppGridWebService");

	web_custom_request("AppGridWebService.ashx_15",
		"URL=https://{param_URL}.crm6.dynamics.com/AppWebServices/AppGridWebService.ashx?operation=Refresh",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t70.inf",
		"Mode=HTML",
		"EncType=text/plain;charset=UTF-8",
		"Body=<grid><sortColumns>createdon&#58;1</sortColumns><pageNum>1</pageNum><recsPerPage>10</recsPerPage><dataProvider>Microsoft.Crm.Application.Platform.Grid.GridDataProviderQueryBuilder</dataProvider><uiProvider>Microsoft.Crm.Application.Controls.GridUIProvider</uiProvider><cols/><max>1</max><refreshAsync>True</refreshAsync><pagingCookie/><enableMultiSort>true</enableMultiSort><enablePagingWhenOnePage>true</enablePagingWhenOnePage><refreshCalledFromRefreshButton>1</refreshCalledFromRefreshButton><returntotalrecordcount>true</returntotalrecordcount><getParameters>getFetchXmlForFilters</getParameters><parameters><viewid>&#123;DD8A07B8-D8BC-4D9F-BAA0-7EE87DAC6528&#125;</viewid><RenderAsync>0</RenderAsync><LoadOnDemand>1</LoadOnDemand><autorefresh>1</autorefresh><isGridHidden>false</isGridHidden><LayoutStyle>LiteGridList</LayoutStyle><maxselectableitems>1</maxselectableitems><isGridFilteringEnabled>1</isGridFilteringEnabled><viewtype>1039</viewtype><viewts>3143032</viewts><RecordsPerPage>10</RecordsPerPage><viewT"
		"itle>Active Case Activities</viewTitle><layoutXml>&#60;grid name&#61;&#34;resultset&#34; jump&#61;&#34;dhhs_name&#34; select&#61;&#34;1&#34; icon&#61;&#34;1&#34; preview&#61;&#34;1&#34; object&#61;&#34;10216&#34;&#62;&#60;row name&#61;&#34;result&#34; id&#61;&#34;dhhs_caseactivityid&#34;&#62;&#60;cell name&#61;&#34;dhhs_activitylink&#34; width&#61;&#34;100&#34; &#47;&#62;&#60;cell name&#61;&#34;createdon&#34; width&#61;&#34;150&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_actualstart&#34; width&#61;&#34;150&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_activitytype&#34; width&#61;&#34;100&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_category&#34; width&#61;&#34;100&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_subject&#34; width&#61;&#34;200&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#"
		"61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_servicetypeid&#34; width&#61;&#34;100&#34; &#47;&#62;&#60;cell name&#61;&#34;ownerid&#34; width&#61;&#34;100&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_statusreasontext&#34; width&#61;&#34;125&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_caseid&#34; width&#61;&#34;100&#34; &#47;&#62;&#60;cell name&#61;&#34;dhhs_casegroupid&#34; width&#61;&#34;150&#34; imageproviderfunctionname&#61;&#34;&#34; imageproviderwebresource&#61;&#34;&#36;webresource&#58;&#34; &#47;&#62;&#60;&#47;row&#62;&#60;&#47;grid&#62;</layoutXml><otc>10216</otc><otn>dhhs_caseactivity</otn><entitydisplayname>Case Activity</entitydisplayname><titleformat>&#123;0&#125; &#123;1&#125;</titleformat><entitypluraldisplayname>Case Activities</entitypluraldisplayname><expandable>1</expandable><showjumpbar>0</showjumpbar><maxrowsbeforescroll>12</maxrowsbeforescroll><tabindex>1460</"
		"tabindex><refreshasynchronous>1</refreshasynchronous><subgridAutoExpand>0</subgridAutoExpand><relName>dhhs_incident_dhhs_caseactivity_CaseId</relName><roleOrd>-1</roleOrd><oType>112</oType><relationshipType>1</relationshipType><ribbonContext>SubGridStandard</ribbonContext><GridType>SubGrid</GridType><enableContextualActions>true</enableContextualActions><teamTemplateId></teamTemplateId><isWorkflowSupported>true</isWorkflowSupported><LoadOnDemand_GridEmptyMessage>To load &#123;0&#125; records, click here.</LoadOnDemand_GridEmptyMessage><enableFilters></enableFilters><InnerGridDisabled>0</InnerGridDisabled><oId>&#123;{oId}&#125;</oId><isTurboForm>1</isTurboForm></parameters><columns><column width=\"100\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Activity&#32;link\" fieldname=\"dhhs_activitylink\" entityname=\"dhhs_caseactivity\" type=\"String.url\" sourcetype=\"0\">dhhs_activitylink</column><column width=\"150\" isHidden=\"false\" isMetadataBound=\""
		"true\" isSortable=\"true\" label=\"Created&#32;On\" fieldname=\"createdon\" entityname=\"dhhs_caseactivity\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"DateTime.datetime\" sourcetype=\"0\">createdon</column><column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Actual&#32;start\" fieldname=\"dhhs_actualstart\" entityname=\"dhhs_caseactivity\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"DateTime.datetime\" sourcetype=\"0\">dhhs_actualstart</column><column width=\"100\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Activity&#32;type\" fieldname=\"dhhs_activitytype\" entityname=\"dhhs_caseactivity\" type=\"String.text\" sourcetype=\"0\">dhhs_activitytype</column><column width=\"100\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Category\" fieldname=\"dhhs_category\" entityname=\"dhhs_caseactivity\" type=\"String.text\" sourcetype=\"0\">dhhs_category</column><column width=\"200\" isHidden=\"f"
		"alse\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Subject\" fieldname=\"dhhs_subject\" entityname=\"dhhs_caseactivity\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">dhhs_subject</column><column width=\"100\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Service&#32;type\" fieldname=\"dhhs_servicetypeid\" entityname=\"dhhs_caseactivity\" type=\"Lookup\" sourcetype=\"0\">dhhs_servicetypeid</column><column width=\"100\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Owner\" fieldname=\"ownerid\" entityname=\"dhhs_caseactivity\" type=\"Owner\" sourcetype=\"0\">ownerid</column><column width=\"125\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Activity&#32;status\" fieldname=\"dhhs_statusreasontext\" entityname=\"dhhs_caseactivity\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"String.text\" sourcetype=\"0\">dhhs_statusreasontext</column><column width=\"100\" isHidden=\"f"
		"alse\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Case\" fieldname=\"dhhs_caseid\" entityname=\"dhhs_caseactivity\" type=\"Lookup\" sourcetype=\"0\">dhhs_caseid</column><column width=\"150\" isHidden=\"false\" isMetadataBound=\"true\" isSortable=\"true\" label=\"Case&#32;Group\" fieldname=\"dhhs_casegroupid\" entityname=\"dhhs_caseactivity\" imageproviderwebresource=\"&#36;webresource&#58;\" type=\"Lookup\" sourcetype=\"0\">dhhs_casegroupid</column></columns></grid>",
		LAST);

	//lr_end_transaction("CRM_06_CreateCase_06_TAppGridWebService",LR_AUTO);

	lr_end_transaction("CRM_06_CreateCase_06_SaveCase",LR_AUTO);

	lr_think_time(5);

	//AddActivity();
	
	return 0;
}
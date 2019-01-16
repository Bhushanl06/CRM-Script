crmwrpctoken()
{
	#include <string.h>
	
		char path1[1024],path2[1024],path3[1024];
    	char separators[] = "\\"; 
   		char * token,* token1,* pch;
   		char word[] = "x2b";		
		char crmwrpctoken1[1024]="",crmwrpctoken2[1024]="",crmwrpctoken3[1024]="";
	//lr_save_string(lr_eval_string("{CorrelationParameter_112}"), "path1");
	lr_output_message ("path is %s", lr_eval_string("{path1}"));
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
	        lr_output_message ("Full path of file is %s",crmwrpctoken1);
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
											   	 	strcat(crmwrpctoken1, token);	   	 	
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
											   	 	strcat(crmwrpctoken1, token);	   	 	
										        }
										        
								        	}
										       /* lr_output_message ("%s", token );
										        strcat(fullpath, "\\\\");
										   	 	lr_output_message ("Full path of file is %s", fullpath);
										   	 	strcat(fullpath, token);*/
								    	    
				}while (token != NULL );
			    
    	}

    lr_output_message ("Full path of file is %s", crmwrpctoken1);
   	 	
	lr_save_string(crmwrpctoken1, "path1");
	
	return 0;
}
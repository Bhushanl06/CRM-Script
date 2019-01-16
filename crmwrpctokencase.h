crmwrpctokencase()
{
	#include <string.h>
	char path1[1024],path2[1024],path3[1024];
    	char separators[] = "\\"; 
   	char * token,* token1,* pch;
   	char word[] = "x2b";		
	char crmwrpctoken1[1024]="",crmwrpctoken2[1024]="",crmwrpctoken3[1024]="";
	

	//lr_save_string("path2", "path1");
	lr_output_message ("path is %s", lr_eval_string("{path2}"));
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
	    }
	
    	else{
		//While valid tokens are returned
		    do      
			{    	    
  	    			lr_output_message ("Full path of file is %s", crmwrpctoken2);			
			        lr_output_message ("%s", token );

			        //Get the next token
				token = (char *)strtok(NULL, separators);
				lr_output_message ("%s", token );
				
				if(token != NULL)
				    {
				       	lr_output_message ("%s", token );
					strcat(crmwrpctoken2, token);
					lr_output_message ("Full path of file is %s", crmwrpctoken2);
				    }
			}while (token != NULL );
	   }
	
    	lr_output_message ("Full path of file is %s", crmwrpctoken2);
   	 	
	lr_save_string(crmwrpctoken2, "path2");

	return 0;
}
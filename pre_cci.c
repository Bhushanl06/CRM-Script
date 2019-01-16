# 1 "c:\\users\\ssen3107\\appdata\\local\\temp\\c221tysz.tjj\\\\combined_CRM_06_CreateCase.c"
# 1 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h" 1
 
 












 











# 103 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"






















































		


		typedef unsigned size_t;
	
	
        
	

















	

 



















 
 
 
 
 


 
 
 
 
 
 














int     lr_start_transaction   (char * transaction_name);
int lr_start_sub_transaction          (char * transaction_name, char * trans_parent);
long lr_start_transaction_instance    (char * transaction_name, long parent_handle);
int   lr_start_cross_vuser_transaction		(char * transaction_name, char * trans_id_param); 



int     lr_end_transaction     (char * transaction_name, int status);
int lr_end_sub_transaction            (char * transaction_name, int status);
int lr_end_transaction_instance       (long transaction, int status);
int   lr_end_cross_vuser_transaction	(char * transaction_name, char * trans_id_param, int status);


 
typedef char* lr_uuid_t;
 



lr_uuid_t lr_generate_uuid();

 


int lr_generate_uuid_free(lr_uuid_t uuid);

 



int lr_generate_uuid_on_buf(lr_uuid_t buf);

   
# 273 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"
int lr_start_distributed_transaction  (char * transaction_name, lr_uuid_t correlator, long timeout  );

   







int lr_end_distributed_transaction  (lr_uuid_t correlator, int status);


double lr_stop_transaction            (char * transaction_name);
double lr_stop_transaction_instance   (long parent_handle);


void lr_resume_transaction           (char * trans_name);
void lr_resume_transaction_instance  (long trans_handle);


int lr_update_transaction            (const char *trans_name);


 
void lr_wasted_time(long time);


 
int lr_set_transaction(const char *name, double duration, int status);
 
long lr_set_transaction_instance(const char *name, double duration, int status, long parent_handle);


int   lr_user_data_point                      (char *, double);
long lr_user_data_point_instance                   (char *, double, long);
 



int lr_user_data_point_ex(const char *dp_name, double value, int log_flag);
long lr_user_data_point_instance_ex(const char *dp_name, double value, long parent_handle, int log_flag);


int lr_transaction_add_info      (const char *trans_name, char *info);
int lr_transaction_instance_add_info   (long trans_handle, char *info);
int lr_dpoint_add_info           (const char *dpoint_name, char *info);
int lr_dpoint_instance_add_info        (long dpoint_handle, char *info);


double lr_get_transaction_duration       (char * trans_name);
double lr_get_trans_instance_duration    (long trans_handle);
double lr_get_transaction_think_time     (char * trans_name);
double lr_get_trans_instance_think_time  (long trans_handle);
double lr_get_transaction_wasted_time    (char * trans_name);
double lr_get_trans_instance_wasted_time (long trans_handle);
int    lr_get_transaction_status		 (char * trans_name);
int	   lr_get_trans_instance_status		 (long trans_handle);

 



int lr_set_transaction_status(int status);

 



int lr_set_transaction_status_by_name(int status, const char *trans_name);
int lr_set_transaction_instance_status(int status, long trans_handle);


typedef void* merc_timer_handle_t;
 

merc_timer_handle_t lr_start_timer();
double lr_end_timer(merc_timer_handle_t timer_handle);


 
 
 
 
 
 











 



int   lr_rendezvous  (char * rendezvous_name);
 




int   lr_rendezvous_ex (char * rendezvous_name);



 
 
 
 
 
char *lr_get_vuser_ip (void);
void   lr_whoami (int *vuser_id, char ** sgroup, int *scid);
char *	  lr_get_host_name (void);
char *	  lr_get_master_host_name (void);

 
long     lr_get_attrib_long	(char * attr_name);
char *   lr_get_attrib_string	(char * attr_name);
double   lr_get_attrib_double      (char * attr_name);

char * lr_paramarr_idx(const char * paramArrayName, unsigned int index);
char * lr_paramarr_random(const char * paramArrayName);
int    lr_paramarr_len(const char * paramArrayName);

int	lr_param_unique(const char * paramName);
int lr_param_sprintf(const char * paramName, const char * format, ...);


 
 
static void *ci_this_context = 0;






 








void lr_continue_on_error (int lr_continue);
char *   lr_decrypt (const char *EncodedString);


 
 
 
 
 
 



 







 















void   lr_abort (void);
void lr_exit(int exit_option, int exit_status);
void lr_abort_ex (unsigned long flags);

void   lr_peek_events (void);


 
 
 
 
 


void   lr_think_time (double secs);

 


void lr_force_think_time (double secs);


 
 
 
 
 



















int   lr_msg (char * fmt, ...);
int   lr_debug_message (unsigned int msg_class,
									    char * format,
										...);
# 512 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"
void   lr_new_prefix (int type,
                                 char * filename,
                                 int line);
# 515 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"
int   lr_log_message (char * fmt, ...);
int   lr_message (char * fmt, ...);
int   lr_error_message (char * fmt, ...);
int   lr_output_message (char * fmt, ...);
int   lr_vuser_status_message (char * fmt, ...);
int   lr_error_message_without_fileline (char * fmt, ...);
int   lr_fail_trans_with_error (char * fmt, ...);

 
 
 
 
 
# 539 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"

 
 
 
 
 





int   lr_next_row ( char * table);
int lr_advance_param ( char * param);



														  
														  

														  
														  

													      
 


char *   lr_eval_string (char * str);
int   lr_eval_string_ext (const char *in_str,
                                     unsigned long const in_len,
                                     char ** const out_str,
                                     unsigned long * const out_len,
                                     unsigned long const options,
                                     const char *file,
								     long const line);
# 573 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"
void   lr_eval_string_ext_free (char * * pstr);

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int lr_param_increment (char * dst_name,
                              char * src_name);
# 596 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"













											  
											  

											  
											  
											  

int	  lr_save_var (char *              param_val,
							  unsigned long const param_val_len,
							  unsigned long const options,
							  char *			  param_name);
# 620 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"
int   lr_save_string (const char * param_val, const char * param_name);



int   lr_set_custom_error_message (const char * param_val, ...);

int   lr_remove_custom_error_message ();


int   lr_free_parameter (const char * param_name);
int   lr_save_int (const int param_val, const char * param_name);
int   lr_save_timestamp (const char * tmstampParam, ...);
int   lr_save_param_regexp (const char *bufferToScan, unsigned int bufSize, ...);

int   lr_convert_double_to_integer (const char *source_param_name, const char * target_param_name);
int   lr_convert_double_to_double (const char *source_param_name, const char *format_string, const char * target_param_name);

 
 
 
 
 
 
# 699 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"
void   lr_save_datetime (const char *format, int offset, const char *name);









 











 
 
 
 
 






 



char * lr_error_context_get_entry (char * key);

 



long   lr_error_context_get_error_id (void);


 
 
 

int lr_table_get_rows_num (char * param_name);

int lr_table_get_cols_num (char * param_name);

char * lr_table_get_cell_by_col_index (char * param_name, int row, int col);

char * lr_table_get_cell_by_col_name (char * param_name, int row, const char* col_name);

int lr_table_get_column_name_by_index (char * param_name, int col, 
											char * * const col_name,
											size_t * col_name_len);
# 760 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"

int lr_table_get_column_name_by_index_free (char * col_name);

 
 
 
 
# 775 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"
int   lr_zip (const char* param1, const char* param2);
int   lr_unzip (const char* param1, const char* param2);

 
 
 
 
 
 
 
 

 
 
 
 
 
 
int   lr_param_substit (char * file,
                                   int const line,
                                   char * in_str,
                                   size_t const in_len,
                                   char * * const out_str,
                                   size_t * const out_len);
# 799 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"
void   lr_param_substit_free (char * * pstr);


 
# 811 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"





char *   lrfnc_eval_string (char * str,
                                      char * file_name,
                                      long const line_num);
# 819 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"


int   lrfnc_save_string ( const char * param_val,
                                     const char * param_name,
                                     const char * file_name,
                                     long const line_num);
# 825 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"

int   lrfnc_free_parameter (const char * param_name );







typedef struct _lr_timestamp_param
{
	int iDigits;
}lr_timestamp_param;

extern const lr_timestamp_param default_timestamp_param;

int   lrfnc_save_timestamp (const char * param_name, const lr_timestamp_param* time_param);

int lr_save_searched_string(char * buffer, long buf_size, unsigned int occurrence,
			    char * search_string, int offset, unsigned int param_val_len, 
			    char * param_name);

 
char *   lr_string (char * str);

 
# 926 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"

int   lr_save_value (char * param_val,
                                unsigned long const param_val_len,
                                unsigned long const options,
                                char * param_name,
                                char * file_name,
                                long const line_num);
# 933 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"


 
 
 
 
 











int   lr_printf (char * fmt, ...);
 
int   lr_set_debug_message (unsigned int msg_class,
                                       unsigned int swtch);
# 955 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"
unsigned int   lr_get_debug_message (void);


 
 
 
 
 

void   lr_double_think_time ( double secs);
void   lr_usleep (long);


 
 
 
 
 
 




int *   lr_localtime (long offset);


int   lr_send_port (long port);


# 1031 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"



struct _lr_declare_identifier{
	char signature[24];
	char value[128];
};

int   lr_pt_abort (void);

void vuser_declaration (void);






# 1060 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"


# 1072 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrun.h"
















 
 
 
 
 







int    _lr_declare_transaction   (char * transaction_name);


 
 
 
 
 







int   _lr_declare_rendezvous  (char * rendezvous_name);

 
 
 
 
 


typedef int PVCI;






typedef int VTCERR;









PVCI   vtc_connect(char * servername, int portnum, int options);
VTCERR   vtc_disconnect(PVCI pvci);
VTCERR   vtc_get_last_error(PVCI pvci);
VTCERR   vtc_query_column(PVCI pvci, char * columnName, int columnIndex, char * *outvalue);
VTCERR   vtc_query_row(PVCI pvci, int rowIndex, char * **outcolumns, char * **outvalues);
VTCERR   vtc_send_message(PVCI pvci, char * column, char * message, unsigned short *outRc);
VTCERR   vtc_send_if_unique(PVCI pvci, char * column, char * message, unsigned short *outRc);
VTCERR   vtc_send_row1(PVCI pvci, char * columnNames, char * messages, char * delimiter, unsigned char sendflag, unsigned short *outUpdates);
VTCERR   vtc_update_message(PVCI pvci, char * column, int index , char * message, unsigned short *outRc);
VTCERR   vtc_update_message_ifequals(PVCI pvci, char * columnName, int index,	char * message, char * ifmessage, unsigned short 	*outRc);
VTCERR   vtc_update_row1(PVCI pvci, char * columnNames, int index , char * messages, char * delimiter, unsigned short *outUpdates);
VTCERR   vtc_retrieve_message(PVCI pvci, char * column, char * *outvalue);
VTCERR   vtc_retrieve_messages1(PVCI pvci, char * columnNames, char * delimiter, char * **outvalues);
VTCERR   vtc_retrieve_row(PVCI pvci, char * **outcolumns, char * **outvalues);
VTCERR   vtc_rotate_message(PVCI pvci, char * column, char * *outvalue, unsigned char sendflag);
VTCERR   vtc_rotate_messages1(PVCI pvci, char * columnNames, char * delimiter, char * **outvalues, unsigned char sendflag);
VTCERR   vtc_rotate_row(PVCI pvci, char * **outcolumns, char * **outvalues, unsigned char sendflag);
VTCERR   vtc_increment(PVCI pvci, char * column, int index , int incrValue, int *outValue);
VTCERR   vtc_clear_message(PVCI pvci, char * column, int index , unsigned short *outRc);
VTCERR   vtc_clear_column(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_ensure_index(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_drop_index(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_clear_row(PVCI pvci, int rowIndex, unsigned short *outRc);
VTCERR   vtc_create_column(PVCI pvci, char * column,unsigned short *outRc);
VTCERR   vtc_column_size(PVCI pvci, char * column, int *size);
void   vtc_free(char * msg);
void   vtc_free_list(char * *msglist);

VTCERR   lrvtc_connect(char * servername, int portnum, int options);
VTCERR   lrvtc_disconnect();
VTCERR   lrvtc_query_column(char * columnName, int columnIndex);
VTCERR   lrvtc_query_row(int columnIndex);
VTCERR   lrvtc_send_message(char * columnName, char * message);
VTCERR   lrvtc_send_if_unique(char * columnName, char * message);
VTCERR   lrvtc_send_row1(char * columnNames, char * messages, char * delimiter, unsigned char sendflag);
VTCERR   lrvtc_update_message(char * columnName, int index , char * message);
VTCERR   lrvtc_update_message_ifequals(char * columnName, int index, char * message, char * ifmessage);
VTCERR   lrvtc_update_row1(char * columnNames, int index , char * messages, char * delimiter);
VTCERR   lrvtc_retrieve_message(char * columnName);
VTCERR   lrvtc_retrieve_messages1(char * columnNames, char * delimiter);
VTCERR   lrvtc_retrieve_row();
VTCERR   lrvtc_rotate_message(char * columnName, unsigned char sendflag);
VTCERR   lrvtc_rotate_messages1(char * columnNames, char * delimiter, unsigned char sendflag);
VTCERR   lrvtc_rotate_row(unsigned char sendflag);
VTCERR   lrvtc_increment(char * columnName, int index , int incrValue);
VTCERR   lrvtc_noop();
VTCERR   lrvtc_clear_message(char * columnName, int index);
VTCERR   lrvtc_clear_column(char * columnName); 
VTCERR   lrvtc_ensure_index(char * columnName); 
VTCERR   lrvtc_drop_index(char * columnName); 
VTCERR   lrvtc_clear_row(int rowIndex);
VTCERR   lrvtc_create_column(char * columnName);
VTCERR   lrvtc_column_size(char * columnName);



 
 
 
 
 

 
int lr_enable_ip_spoofing();
int lr_disable_ip_spoofing();


 




int lr_convert_string_encoding(char * sourceString, char * fromEncoding, char * toEncoding, char * paramName);
int lr_read_file(const char *filename, const char *outputParam, int continueOnError);


 
int lr_db_connect (char * pFirstArg, ...);
int lr_db_disconnect (char * pFirstArg,	...);
int lr_db_executeSQLStatement (char * pFirstArg, ...);
int lr_db_dataset_action(char * pFirstArg, ...);
int lr_checkpoint(char * pFirstArg,	...);
int lr_db_getvalue(char * pFirstArg, ...);







 
 



















# 1 "c:\\users\\ssen3107\\appdata\\local\\temp\\c221tysz.tjj\\\\combined_CRM_06_CreateCase.c" 2

# 1 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/SharedParameter.h" 1



 
 
 
 
# 100 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/SharedParameter.h"






typedef int PVCI2;






typedef int VTCERR2;


 
 
 

 
extern PVCI2    vtc_connect(char *servername, int portnum, int options);
extern VTCERR2  vtc_disconnect(PVCI2 pvci);
extern VTCERR2  vtc_get_last_error(PVCI2 pvci);

 
extern VTCERR2  vtc_query_column(PVCI2 pvci, char *columnName, int columnIndex, char **outvalue);
extern VTCERR2  vtc_query_row(PVCI2 pvci, int columnIndex, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_send_message(PVCI2 pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_if_unique(PVCI2 pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_row1(PVCI2 pvci, char *columnNames, char *messages, char *delimiter,  unsigned char sendflag, unsigned short *outUpdates);
extern VTCERR2  vtc_update_message(PVCI2 pvci, char *column, int index , char *message, unsigned short *outRc);
extern VTCERR2  vtc_update_message_ifequals(PVCI2 pvci, char	*columnName, int index,	char *message, char	*ifmessage,	unsigned short 	*outRc);
extern VTCERR2  vtc_update_row1(PVCI2 pvci, char *columnNames, int index , char *messages, char *delimiter, unsigned short *outUpdates);
extern VTCERR2  vtc_retrieve_message(PVCI2 pvci, char *column, char **outvalue);
extern VTCERR2  vtc_retrieve_messages1(PVCI2 pvci, char *columnNames, char *delimiter, char ***outvalues);
extern VTCERR2  vtc_retrieve_row(PVCI2 pvci, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_rotate_message(PVCI2 pvci, char *column, char **outvalue, unsigned char sendflag);
extern VTCERR2  vtc_rotate_messages1(PVCI2 pvci, char *columnNames, char *delimiter, char ***outvalues, unsigned char sendflag);
extern VTCERR2  vtc_rotate_row(PVCI2 pvci, char ***outcolumns, char ***outvalues, unsigned char sendflag);
extern VTCERR2	vtc_increment(PVCI2 pvci, char *column, int index , int incrValue, int *outValue);
extern VTCERR2  vtc_clear_message(PVCI2 pvci, char *column, int index , unsigned short *outRc);
extern VTCERR2  vtc_clear_column(PVCI2 pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_clear_row(PVCI2 pvci, int rowIndex, unsigned short *outRc);

extern VTCERR2  vtc_create_column(PVCI2 pvci, char *column,unsigned short *outRc);
extern VTCERR2  vtc_column_size(PVCI2 pvci, char *column, int *size);
extern VTCERR2  vtc_ensure_index(PVCI2 pvci, char *column, unsigned short *outRc);
extern VTCERR2  vtc_drop_index(PVCI2 pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_noop(PVCI2 pvci);

 
extern void vtc_free(char *msg);
extern void vtc_free_list(char **msglist);

 


 




 




















 




 
 
 

extern VTCERR2  lrvtc_connect(char *servername, int portnum, int options);
extern VTCERR2  lrvtc_disconnect();
extern VTCERR2  lrvtc_query_column(char *columnName, int columnIndex);
extern VTCERR2  lrvtc_query_row(int columnIndex);
extern VTCERR2  lrvtc_send_message(char *columnName, char *message);
extern VTCERR2  lrvtc_send_if_unique(char *columnName, char *message);
extern VTCERR2  lrvtc_send_row1(char *columnNames, char *messages, char *delimiter,  unsigned char sendflag);
extern VTCERR2  lrvtc_update_message(char *columnName, int index , char *message);
extern VTCERR2  lrvtc_update_message_ifequals(char *columnName, int index, char 	*message, char *ifmessage);
extern VTCERR2  lrvtc_update_row1(char *columnNames, int index , char *messages, char *delimiter);
extern VTCERR2  lrvtc_retrieve_message(char *columnName);
extern VTCERR2  lrvtc_retrieve_messages1(char *columnNames, char *delimiter);
extern VTCERR2  lrvtc_retrieve_row();
extern VTCERR2  lrvtc_rotate_message(char *columnName, unsigned char sendflag);
extern VTCERR2  lrvtc_rotate_messages1(char *columnNames, char *delimiter, unsigned char sendflag);
extern VTCERR2  lrvtc_rotate_row(unsigned char sendflag);
extern VTCERR2  lrvtc_increment(char *columnName, int index , int incrValue);
extern VTCERR2  lrvtc_clear_message(char *columnName, int index);
extern VTCERR2  lrvtc_clear_column(char *columnName);
extern VTCERR2  lrvtc_clear_row(int rowIndex);
extern VTCERR2  lrvtc_create_column(char *columnName);
extern VTCERR2  lrvtc_column_size(char *columnName);
extern VTCERR2  lrvtc_ensure_index(char *columnName);
extern VTCERR2  lrvtc_drop_index(char *columnName);

extern VTCERR2  lrvtc_noop();

 
 
 

                               


 
 
 





















# 2 "c:\\users\\ssen3107\\appdata\\local\\temp\\c221tysz.tjj\\\\combined_CRM_06_CreateCase.c" 2

# 1 "globals.h" 1



 
 

# 1 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/web_api.h" 1







# 1 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/as_web.h" 1



























































 




 



 











 





















 
 
 

  int
	web_add_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_add_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
	
  int
	web_add_auto_header(
		const char *		mpszHeader,
		const char *		mpszValue);

  int
	web_add_header(
		const char *		mpszHeader,
		const char *		mpszValue);
  int
	web_add_cookie(
		const char *		mpszCookie);
  int
	web_cleanup_auto_headers(void);
  int
	web_cleanup_cookies(void);
  int
	web_concurrent_end(
		const char * const	mpszReserved,
										 
		...								 
	);
  int
	web_concurrent_start(
		const char * const	mpszConcurrentGroupName,
										 
										 
		...								 
										 
	);
  int
	web_create_html_param(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim);
  int
	web_create_html_param_ex(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim,
		const char *		mpszNum);
  int
	web_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	spdy_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_disable_keep_alive(void);
  int
	web_enable_keep_alive(void);
  int
	web_find(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_get_int_property(
		const int			miHttpInfoType);
  int
	web_image(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_image_check(
		const char *		mpszName,
		...);
  int
	web_java_check(
		const char *		mpszName,
		...);
  int
	web_link(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

	
  int
	web_global_verification(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
  int
	web_reg_find(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
				
  int
	web_reg_save_param(
		const char *		mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 

  int
	web_convert_param(
		const char * 		mpszParamName, 
										 
		...);							 
										 
										 


										 

										 
  int
	web_remove_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
				
  int
	web_remove_auto_header(
		const char *		mpszHeaderName,
		...);							 
										 



  int
	web_remove_cookie(
		const char *		mpszCookie);

  int
	web_save_header(
		const char *		mpszType,	 
		const char *		mpszName);	 
  int
	web_set_certificate(
		const char *		mpszIndex);
  int
	web_set_certificate_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_set_connections_limit(
		const char *		mpszLimit);
  int
	web_set_max_html_param_len(
		const char *		mpszLen);
  int
	web_set_max_retries(
		const char *		mpszMaxRetries);
  int
	web_set_proxy(
		const char *		mpszProxyHost);
  int
	web_set_pac(
		const char *		mpszPacUrl);
  int
	web_set_proxy_bypass(
		const char *		mpszBypass);
  int
	web_set_secure_proxy(
		const char *		mpszProxyHost);
  int
	web_set_sockets_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue
	);
  int
	web_set_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue,
		...								 
	);
  int
	web_set_timeout(
		const char *		mpszWhat,
		const char *		mpszTimeout);
  int
	web_set_user(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);

  int
	web_sjis_to_euc_param(
		const char *		mpszParamName,
										 
		const char *		mpszParamValSjis);
										 

  int
	web_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	spdy_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_submit_form(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	spdy_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_set_proxy_bypass_local(
		const char * mpszNoLocal
		);

  int 
	web_cache_cleanup(void);

  int
	web_create_html_query(
		const char* mpszStartQuery,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_create_radio_button_param(
		const char *NameFiled,
		const char *NameAndVal,
		const char *ParamName
		);

  int
	web_convert_from_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										
  int
	web_convert_to_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_ex(
		const char * mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_xpath(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_json(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_regexp(
		 const char * mpszParamName,
		 ...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_run(
		const char * mpszCode,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_reset(void);

  int
	web_convert_date_param(
		const char * 		mpszParamName,
		...);










# 769 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/as_web.h"


# 782 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/as_web.h"



























# 820 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/as_web.h"

 
 
 


  int
	FormSubmit(
		const char *		mpszFormName,
		...);
  int
	InitWebVuser(void);
  int
	SetUser(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);
  int
	TerminateWebVuser(void);
  int
	URL(
		const char *		mpszUrlName);
























# 888 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/as_web.h"


  int
	web_rest(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 

  int
web_stream_open(
	const char *		mpszArg1,
	...
);
  int
	web_stream_wait(
		const char *		mpszArg1,
		...
	);

  int
	web_stream_close(
		const char *		mpszArg1,
		...
	);

  int
web_stream_play(
	const char *		mpszArg1,
	...
	);

  int
web_stream_pause(
	const char *		mpszArg1,
	...
	);

  int
web_stream_seek(
	const char *		mpszArg1,
	...
	);

  int
web_stream_get_param_int(
	const char*			mpszStreamID,
	const int			miStateType
	);

  double
web_stream_get_param_double(
	const char*			mpszStreamID,
	const int			miStateType
	);

  int
web_stream_get_param_string(
	const char*			mpszStreamID,
	const int			miStateType,
	const char*			mpszParameterName
	);

  int
web_stream_set_param_int(
	const char*			mpszStreamID,
	const int			miStateType,
	const int			miStateValue
	);

  int
web_stream_set_param_double(
	const char*			mpszStreamID,
	const int			miStateType,
	const double		mdfStateValue
	);

 
 
 






# 9 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/web_api.h" 2

















 







 














  int
	web_reg_add_cookie(
		const char *		mpszCookie,
		...);							 
										 

  int
	web_report_data_point(
		const char *		mpszEventType,
		const char *		mpszEventName,
		const char *		mpszDataPointName,
		const char *		mpszLAST);	 
										 
										 
										 

  int
	web_text_link(
		const char *		mpszStepName,
		...);

  int
	web_element(
		const char *		mpszStepName,
		...);

  int
	web_image_link(
		const char *		mpszStepName,
		...);

  int
	web_static_image(
		const char *		mpszStepName,
		...);

  int
	web_image_submit(
		const char *		mpszStepName,
		...);

  int
	web_button(
		const char *		mpszStepName,
		...);

  int
	web_edit_field(
		const char *		mpszStepName,
		...);

  int
	web_radio_group(
		const char *		mpszStepName,
		...);

  int
	web_check_box(
		const char *		mpszStepName,
		...);

  int
	web_list(
		const char *		mpszStepName,
		...);

  int
	web_text_area(
		const char *		mpszStepName,
		...);

  int
	web_map_area(
		const char *		mpszStepName,
		...);

  int
	web_eval_java_script(
		const char *		mpszStepName,
		...);

  int
	web_reg_dialog(
		const char *		mpszArg1,
		...);

  int
	web_reg_cross_step_download(
		const char *		mpszArg1,
		...);

  int
	web_browser(
		const char *		mpszStepName,
		...);

  int
	web_control(
		const char *		mpszStepName,
		...);

  int
	web_set_rts_key(
		const char *		mpszArg1,
		...);

  int
	web_save_param_length(
		const char * 		mpszParamName,
		...);

  int
	web_save_timestamp_param(
		const char * 		mpszParamName,
		...);

  int
	web_load_cache(
		const char *		mpszStepName,
		...);							 
										 

  int
	web_dump_cache(
		const char *		mpszStepName,
		...);							 
										 
										 

  int
	web_reg_find_in_log(
		const char *		mpszArg1,
		...);							 
										 
										 

  int
	web_get_sockets_info(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 

  int
	web_add_cookie_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

  int
	web_hook_java_script(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

 
 
 
 
 
 
 
 
 
 
 
 
  int
	web_reg_async_attributes(
		const char *		mpszArg,
		...
	);

 
 
 
 
 
 
  int
	web_sync(
		 const char *		mpszArg1,
		 ...
	);

 
 
 
 
  int
	web_stop_async(
		const char *		mpszArg1,
		...
	);

 
 
 
 
 

 
 
 

typedef enum WEB_ASYNC_CB_RC_ENUM_T
{
	WEB_ASYNC_CB_RC_OK,				 

	WEB_ASYNC_CB_RC_ABORT_ASYNC_NOT_ERROR,
	WEB_ASYNC_CB_RC_ABORT_ASYNC_ERROR,
										 
										 
										 
										 
	WEB_ASYNC_CB_RC_ENUM_COUNT
} WEB_ASYNC_CB_RC_ENUM;

 
 
 

typedef enum WEB_CONVERS_CB_CALL_REASON_ENUM_T
{
	WEB_CONVERS_CB_CALL_REASON_BUFFER_RECEIVED,
	WEB_CONVERS_CB_CALL_REASON_END_OF_TASK,

	WEB_CONVERS_CB_CALL_REASON_ENUM_COUNT
} WEB_CONVERS_CB_CALL_REASON_ENUM;

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

typedef
int														 
	(*RequestCB_t)();

typedef
int														 
	(*ResponseBodyBufferCB_t)(
		  const char *		aLastBufferStr,
		  int				aLastBufferLen,
		  const char *		aAccumulatedStr,
		  int				aAccumulatedLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseCB_t)(
		  const char *		aResponseHeadersStr,
		  int				aResponseHeadersLen,
		  const char *		aResponseBodyStr,
		  int				aResponseBodyLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseHeadersCB_t)(
		  int				aHttpStatusCode,
		  const char *		aAccumulatedHeadersStr,
		  int				aAccumulatedHeadersLen);



 
 
 

typedef enum WEB_CONVERS_UTIL_RC_ENUM_T
{
	WEB_CONVERS_UTIL_RC_OK,
	WEB_CONVERS_UTIL_RC_CONVERS_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_TASK_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_UNAVIALABLE,
	WEB_CONVERS_UTIL_RC_INVALID_ARGUMENT,

	WEB_CONVERS_UTIL_RC_ENUM_COUNT
} WEB_CONVERS_UTIL_RC_ENUM;

 
 
 

  int					 
	web_util_set_request_url(
		  const char *		aUrlStr);

  int					 
	web_util_set_request_body(
		  const char *		aRequestBodyStr);

  int					 
	web_util_set_formatted_request_body(
		  const char *		aRequestBodyStr);


 
 
 
 
 

 
 
 
 
 

 
 
 
 
 
 
 
 

 
 
  int
web_websocket_connect(
		 const char *	mpszArg1,
		 ...
		 );


 
 
 
 
 																						
  int
web_websocket_send(
	   const char *		mpszArg1,
		...
	   );

 
 
 
 
 
 
  int
web_websocket_close(
		const char *	mpszArg1,
		...
		);

 
typedef
void														
(*OnOpen_t)(
			  const char* connectionID,  
			  const char * responseHeader,  
			  int length  
);

typedef
void														
(*OnMessage_t)(
	  const char* connectionID,  
	  int isbinary,  
	  const char * data,  
	  int length  
	);

typedef
void														
(*OnError_t)(
	  const char* connectionID,  
	  const char * message,  
	  int length  
	);

typedef
void														
(*OnClose_t)(
	  const char* connectionID,  
	  int isClosedByClient,  
	  int code,  
	  const char* reason,  
	  int length  
	 );
 
 
 
 
 





# 7 "globals.h" 2

# 1 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/lrw_custom_body.h" 1
 





# 8 "globals.h" 2

# 1 "CRM_Login_Popup.c" 1
CRM_Login_Popup()
{

	# 1 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/string.h" 1
 








# 1 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/stddef.h" 1













typedef unsigned int uintptr_t;








typedef int intptr_t;








typedef int ptrdiff_t;





typedef unsigned short wchar_t;




typedef long time_t;




typedef long clock_t;




typedef wchar_t wint_t;
typedef wchar_t wctype_t;




typedef char *	va_list;



 





# 10 "C:\\Program Files (x86)\\HP\\Virtual User Generator\\include/string.h" 2










void *	 memchr(const void *, int, size_t);
int 	 memcmp(const void *, const void *, size_t);
void * 	 memcpy(void *, const void *, size_t);
void *	 memmove(void *, const void *, size_t);
void *	 memset(void *, int, size_t);

char 	*strcat(char *, const char *);
char 	*strchr(const char *, int);
int	 strcmp(const char *, const char *);
int	 strcoll(const char *, const char *);
char 	*strcpy(char *, const char *);
size_t	 strcspn(const char *, const char *);
char 	*strerror(int);
size_t	 strlen(const char *);
char 	*strncat(char *, const char *, size_t);
int	 strncmp(const char *, const char *, size_t);
char 	*strncpy(char *, const char *, size_t);
char 	*strpbrk(const char *, const char *);
char 	*strrchr(const char *, int);
size_t	 strspn(const char *, const char *);
char 	*strstr(const char *, const char *);
char 	*strtok(char *, const char *);

void *	 memccpy(void *, const void *, int, size_t);
int	 strcmpi(const char *, const char *);
char 	*strdup(const char *);
int	 strnicmp(const char *, const char *, size_t);
void	 swab(const char *, char *, size_t);

# 4 "CRM_Login_Popup.c" 2

	char path1[1024],path2[1024],path3[1024];
   	char separators[] = "\\"; 
  	char * token,* token1,* pch;
  	char word[] = "x2b";
   	char crmwrpctoken1[1024],crmwrpctoken2[1024],crmwrpctoken3[1024],crmwrpctoken4[1024];


	web_add_cookie("wlidperf=FR=L&ST=1523946042477; DOMAIN=login.microsoftonline.com");

	 








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

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_22",
		"RegExp=CRMWSFed.nonce.(.*?)&wct",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"RequestUrl=*/main.aspx*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=wct_3",
		"RegExp=wct=(.*?)&",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"RequestUrl=*/main.aspx*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=hpgrequestid_3",
		"RegExp=x-ms-request-id:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=esctx_2",
		"RegExp=esctx=(.*?);",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Cookies",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=ctx_3",
		"RegExp=\"sCtx\":\"(.*?)\",",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_23",
		"RegExp=u0026client-request-id=(.*?)\",",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=flowToken_3",
		"RegExp=\"sFT\":\"(.*?)\",",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_24",
		"RegExp=\"apiCanary\":\"(.*?)\",",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=canary_3",
		"RegExp=\",\"canary\":\"(.*?)\",",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		"LAST");

	web_url("main.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t873.inf", 
		"Mode=HTTP", 
		"LAST");

	web_add_header("Accept", 
		"application/javascript, */*;q=0.8");

	web_concurrent_start(0);

	web_url("convergedlogin_pcore.min.js",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/cdnbundles/convergedlogin_pcore.min.js",
		"Resource=1",
		"RecContentType=application/x-javascript",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t874.inf",
		"LAST");

	web_add_header("Accept", 
		"text/css, */*");

	web_url("converged.login.min.css",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/cdnbundles/converged.login.min.css",
		"Resource=1",
		"RecContentType=text/css",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t875.inf",
		"LAST");

	web_add_header("Accept", 
		"application/javascript, */*;q=0.8");

	web_url("convergedloginpaginatedstrings-en.min.js",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/cdnbundles/convergedloginpaginatedstrings-en.min.js",
		"Resource=1",
		"RecContentType=application/x-javascript",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t876.inf",
		"LAST");

	web_add_header("Accept", 
		"*/*");

	web_url("favicon_a.ico", 
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/images/favicon_a.ico", 
		"Resource=1", 
		"RecContentType=image/x-icon", 
		"Referer=", 
		"Snapshot=t877.inf", 
		"LAST");

	web_concurrent_end(0);

	web_add_header("Accept", 
		"image/png, image/svg+xml, image/*;q=0.8, */*;q=0.5");

	web_concurrent_start(0);

	web_url("microsoft_logo.svg",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/images/microsoft_logo.svg?x=ee5c8d9fb6248c938fd0dc19370e90bd",
		"Resource=1",
		"RecContentType=image/svg+xml",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t878.inf",
		"LAST");

	web_add_header("Accept", 
		"image/png, image/svg+xml, image/*;q=0.8, */*;q=0.5");

	web_url("12.png",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/images/applogos/12.png?x=e15869494a1446169159c7b1a5e959c0",
		"Resource=1",
		"RecContentType=image/png",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t879.inf",
		"LAST");

	web_add_header("Accept", 
		"image/png, image/svg+xml, image/*;q=0.8, */*;q=0.5");

	web_url("picker_more.svg",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/images/picker_more.svg?x=7568a43cf440757c55d2e7f51557ae1f",
		"Resource=1",
		"RecContentType=image/svg+xml",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t880.inf",
		"LAST");

	web_add_header("Accept", 
		"image/png, image/svg+xml, image/*;q=0.8, */*;q=0.5");

	web_url("picker_account_aad.svg",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/images/picker_account_aad.svg?x=9de70d1c5191d1852a0d5aac28b44a6c",
		"Resource=1",
		"RecContentType=image/svg+xml",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t881.inf",
		"LAST");

	web_add_header("Accept", 
		"image/png, image/svg+xml, image/*;q=0.8, */*;q=0.5");

	web_url("picker_account_add.svg",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/images/picker_account_add.svg?x=56e73414003cdb676008ff7857343074",
		"Resource=1",
		"RecContentType=image/svg+xml",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t882.inf",
		"LAST");

	web_add_header("Accept", 
		"image/png, image/svg+xml, image/*;q=0.8, */*;q=0.5");

	web_url("ellipsis_white.svg",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/images/ellipsis_white.svg?x=5ac590ee72bfe06a7cecfd75b588ad73",
		"Resource=1",
		"RecContentType=image/svg+xml",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t883.inf",
		"LAST");

	web_add_header("Accept", 
		"image/png, image/svg+xml, image/*;q=0.8, */*;q=0.5");

	web_url("ellipsis_grey.svg",
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7464.11/content/images/ellipsis_grey.svg?x=2b5d393db04a5e6e1f739cb266e65b4c",
		"Resource=1",
		"RecContentType=image/svg+xml",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t884.inf",
		"LAST");

	web_concurrent_end(0);

	 

	 

	web_add_cookie("esctx={esctx_2}; DOMAIN=login.microsoftonline.com");

	(web_remove_auto_header("X-P2P-PeerDist", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("X-P2P-PeerDistEx", "ImplicitGen=Yes", "LAST"));

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
		"LAST");

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
		"LAST");

	lr_end_transaction("CRM_01_a_VerifyUserID",2);

	lr_think_time(3);

	web_add_cookie("CkTst=G1523947050910; DOMAIN=login.microsoftonline.com");

	web_add_cookie("wlidperf=FR=L&ST=1523947088076; DOMAIN=login.microsoftonline.com");

	web_add_auto_header("Accept", 
		"text/html, application/xhtml+xml, */*");

 





	  






		 

 





	  






		 

 





	web_reg_save_param_regexp(
		"ParamName=flowToken_1",
		"RegExp=@dhhsvicgovau\\.onmicrosoft\\.com\",\"sFT\":\"(.*?)\",",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Body",
		"RequestUrl=*/login*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=ctx_1",
		"RegExp=\"sCtx\":\"(.*?)\",",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Body",
		"RequestUrl=*/login*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=canary_1",
		"RegExp=\"apiCanary\":\"(.*?)\",",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Body",
		"RequestUrl=*/login*",
		"LAST");

	web_submit_data("login",
		"Action=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/login",
		"Method=POST",
		"RecContentType=text/html",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignin1.0&wtrealm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&wctx=pr%3dwsfederation%26rm%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252f%26ru%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26ry%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3%26crmorgid%3d9eb199a9-d221-43d7-8d01-7006601d9cc1%26nonce%3dCRMWSFed.nonce.{CorrelationParameter_22}&wct={wct_3}&wreply=https%3a%2f%2fcloudredirector.crm6.dynamics.com%3a443%2fG%2fAuthRedirect%2fIndex.aspx%3fRedirectTo%3dhttps%253a%252f%252f{param_URL}.crm6.dynamics.com%252fmain.aspx%253fappid%253dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t887.inf",
		"Mode=HTTP",
		"ITEMDATA",
		"Name=i13", "Value=0", "ENDITEM",
		"Name=login", "Value={param_UserID}@dhhsvicgovau.onmicrosoft.com", "ENDITEM",
		"Name=loginfmt", "Value={param_UserID}@dhhsvicgovau.onmicrosoft.com", "ENDITEM",
		"Name=type", "Value=11", "ENDITEM",
		"Name=LoginOptions", "Value=3", "ENDITEM",
		"Name=lrt", "Value=", "ENDITEM",
		"Name=lrtPartition", "Value=", "ENDITEM",
		"Name=hisRegion", "Value=", "ENDITEM",
		"Name=hisScaleUnit", "Value=", "ENDITEM",
		"Name=passwd", "Value={param_Password}", "ENDITEM",
		"Name=ps", "Value=2", "ENDITEM",
		"Name=psRNGCDefaultType", "Value=", "ENDITEM",
		"Name=psRNGCEntropy", "Value=", "ENDITEM",
		"Name=psRNGCSLK", "Value=", "ENDITEM",
		"Name=canary", "Value={canary_3}", "ENDITEM",
		"Name=ctx", "Value={ctx_3}", "ENDITEM",
		"Name=hpgrequestid", "Value={hpgrequestid_3}", "ENDITEM",
		"Name=flowToken", "Value={flowToken_3}", "ENDITEM",
		"Name=PPSX", "Value=", "ENDITEM",
		"Name=NewUser", "Value=1", "ENDITEM",
		"Name=FoundMSAs", "Value=", "ENDITEM",
		"Name=fspost", "Value=0", "ENDITEM",
		"Name=i21", "Value=0", "ENDITEM",
		"Name=CookieDisclosure", "Value=0", "ENDITEM",
		"Name=IsFidoSupported", "Value=0", "ENDITEM",
		"Name=i2", "Value=102", "ENDITEM",
		"Name=i17", "Value=", "ENDITEM",
		"Name=i18", "Value=", "ENDITEM",
		"Name=i19", "Value=36910", "ENDITEM",
		"LAST");

	 

	 

 





	web_reg_save_param_regexp(
		"ParamName=ESTSAUTHPERSISTENT_6",
		"RegExp=ESTSAUTHPERSISTENT=(.*?);",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Cookies",
		"RequestUrl=*/kmsi*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=ESTSAUTH_2",
		"RegExp=ESTSAUTH=(.*?);",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Cookies",
		"RequestUrl=*/kmsi*",
		"LAST");

 





	web_reg_save_param_ex(
		"ParamName=CorrelationParameter_25",
		"LB/IC=xsd&quot;>",
		"RB/IC=&lt",
		"DFEs=Xml",
		"SEARCH_FILTERS",
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		"LAST");

 





	web_reg_save_param_ex(
		"ParamName=CorrelationParameter_26",
		"LB/IC=xsd&quot;>",
		"RB/IC=&lt",
		"DFEs=Xml",
		"Ordinal=2",
		"SEARCH_FILTERS",
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_27",
		"RegExp=quot;_(.*?)&quot",
		"DFEs=Xml",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		"LAST");

 





	web_reg_save_param_ex(
		"ParamName=CorrelationParameter_28",
		"LB/IC=IssueInstant=&quot;",
		"RB/IC=&quot;",
		"DFEs=Xml",
		"SEARCH_FILTERS",
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		"LAST");

 





	web_reg_save_param_ex(
		"ParamName=DigestValue_2",
		"LB/IC=;DigestValue>",
		"RB/IC=&lt",
		"DFEs=Xml",
		"SEARCH_FILTERS",
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		"LAST");

 





	web_reg_save_param(
		"SignatureValue_2",
		"LB/IC=SignatureValue>",
		"RB/IC=&lt;/SignatureValue",
		"LAST");
	
 





	web_reg_save_param_ex(
		"ParamName=CorrelationParameter_29",
		"LB/IC=AuthnInstant=&quot;",
		"RB/IC=&quot;",
		"DFEs=Xml",
		"SEARCH_FILTERS",
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		"LAST");

	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_7_1",
		"RegExp=lt;X509Data>&lt;X509Certificate>(.*?)&lt",
		"DFEs=Xml",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		"LAST");
	web_reg_save_param_ex(
		"ParamName=CorrelationParameter_8_1",
		"LB/IC=persistent&quot;>",
		"RB/IC=&lt;/NameID>",
		"DFEs=Xml",
		"SEARCH_FILTERS",
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		"LAST");

 





	web_reg_save_param_ex(
		"ParamName=AttributeValue_1",
		"LB/IC=objectidentifier&quot;>&lt;AttributeValue>",
		"RB/IC=&lt;/AttributeValue>&lt;",
		"DFEs=Xml",
		"SEARCH_FILTERS",
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		"LAST");

 





	web_reg_save_param_ex(
		"ParamName=CorrelationParameter_9_1",
		"LB/IC=puid&quot;>&lt;AttributeValue>",
		"RB/IC=&lt;/AttributeValue>&lt;",
		"DFEs=Xml",
		"SEARCH_FILTERS",
		"Scope=Body",
		"RequestUrl=*/kmsi*",
		"LAST");

 
	
	web_reg_save_param(
		"corr_surname",
		"LB/IC=surname&quot;>&lt;AttributeValue>",
		"RB/IC=&lt;/AttributeValue>",
		"LAST");
	
 
	
	web_reg_save_param(
		"corr_givenname",
		"LB/IC=givenname&quot;>&lt;AttributeValue>",
		"RB/IC=&lt;/AttributeValue>",
		"LAST");
	
 
	
	web_reg_save_param(
		"corr_displayname",
		"LB/IC=displayname&quot;>&lt;AttributeValue>",
		"RB/IC=&lt;/AttributeValue>",
		"LAST");

	lr_start_transaction("CRM_01_b_SignIn");

	web_submit_data("kmsi",
		"Action=https://login.microsoftonline.com/kmsi",
		"Method=POST",
		"RecContentType=text/html",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/login",
		"Snapshot=t21.inf",
		"Mode=HTTP",
		"ITEMDATA",
		"Name=LoginOptions", "Value=0", "ENDITEM",
		"Name=ctx", "Value={ctx_1}", "ENDITEM",
		"Name=flowToken", "Value={flowToken_1}", "ENDITEM",
		"Name=canary", "Value={canary_1}", "ENDITEM",
		"Name=i2", "Value=", "ENDITEM",
		"Name=i17", "Value=", "ENDITEM",
		"Name=i18", "Value=", "ENDITEM",
		"Name=i19", "Value=7705", "ENDITEM",
		"LAST");

	web_submit_data("Index.aspx",
		"Action=https://cloudredirector.crm6.dynamics.com/G/AuthRedirect/Index.aspx?RedirectTo=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2fmain.aspx%3fappid%3dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Method=POST",
		"RecContentType=text/html",
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/login",
		"Snapshot=t888.inf",
		"Mode=HTTP",
		"ITEMDATA",
		"Name=wa", "Value=wsignin1.0", "ENDITEM",
		"Name=wresult", "Value=<t:RequestSecurityTokenResponse xmlns:t=\"http://schemas.xmlsoap.org/ws/2005/02/trust\"><t:Lifetime><wsu:Created xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">{CorrelationParameter_25}</wsu:Created><wsu:Expires xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">{CorrelationParameter_26}</wsu:Expires></t:Lifetime><wsp:AppliesTo xmlns:wsp=\"http://schemas.xmlsoap.org/ws/2004/09/policy\"><wsa:EndpointReference xmlns:wsa=\"http://www.w3.org/2005/08/addressing\"><wsa:Address>https://{param_URL}.crm6.dynamics.com/</wsa:Address></wsa:EndpointReference></wsp:AppliesTo><t:RequestedSecurityToken><Assertion ID=\"_{CorrelationParameter_27}\" IssueInstant=\"{CorrelationParameter_28}\" Version=\"2.0\" xmlns=\"urn:oasis:names:tc:SAML:2.0:assertion\"><Issuer>https://sts.windows.net/c0e0601f-0fac-449c-9c88-a104c4eb9f28/</Issuer><Signature xmlns=\"http://www.w3.org/2000/09/xmldsig#\"><SignedInfo><CanonicalizationMeth"
		"od Algorithm=\"http://www.w3.org/2001/10/xml-exc-c14n#\" /><SignatureMethod Algorithm=\"http://www.w3.org/2001/04/xmldsig-more#rsa-sha256\" /><Reference URI=\"#_{CorrelationParameter_27}\"><Transforms><Transform Algorithm=\"http://www.w3.org/2000/09/xmldsig#enveloped-signature\" /><Transform Algorithm=\"http://www.w3.org/2001/10/xml-exc-c14n#\" /></Transforms><DigestMethod Algorithm=\"http://www.w3.org/2001/04/xmlenc#sha256\" /><DigestValue>{DigestValue_2}</DigestValue></Reference></SignedInfo><SignatureValue>{SignatureValue_2}</SignatureValue><KeyInfo><X509Data><X509Certificate>{CorrelationParameter_7_1}</X509Certificate></X509Data></KeyInfo></Signature><Subject><NameID Format=\"urn:oasis:names:tc:SAML:2.0:nameid-format:persistent\">{CorrelationParameter_8_1}</NameID><SubjectConfirmation Method=\"urn:oasis:names:tc:SAML:2.0:cm:bearer\" /></Subject><Conditions NotBefore=\"{CorrelationParameter_25}\" NotOnOrAfter=\"{CorrelationParameter_26}\"><AudienceRestriction><Audience>https://fsvhublinkprodpilot.crm6.dy"
		"namics.com/</Audience></AudienceRestriction></Conditions><AttributeStatement><Attribute Name=\"http://schemas.microsoft.com/identity/claims/tenantid\"><AttributeValue>c0e0601f-0fac-449c-9c88-a104c4eb9f28</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/identity/claims/objectidentifier\"><AttributeValue>{AttributeValue_1}</AttributeValue></Attribute><Attribute Name=\"http://schemas.xmlsoap.org/ws/2005/05/identity/claims/name\"><AttributeValue>{param_UserID2}@dhhsvicgovau.onmicrosoft.com</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/identity/claims/puid\"><AttributeValue>{CorrelationParameter_9_1}</AttributeValue></Attribute><Attribute Name=\"http://schemas.xmlsoap.org/ws/2005/05/identity/claims/surname\"><AttributeValue>{corr_surname}</AttributeValue></Attribute><Attribute Name=\"http://schemas.xmlsoap.org/ws/2005/05/identity/claims/givenname\"><AttributeValue>{corr_givenname}</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/identity/cla"
		"ims/displayname\"><AttributeValue>{corr_displayname}</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/identity/claims/identityprovider\"><AttributeValue>https://sts.windows.net/c0e0601f-0fac-449c-9c88-a104c4eb9f28/</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/claims/authnmethodsreferences\"><AttributeValue>http://schemas.microsoft.com/ws/2008/06/identity/authenticationmethod/password</AttributeValue></Attribute></AttributeStatement><AuthnStatement AuthnInstant=\"{CorrelationParameter_29}\"><AuthnContext><AuthnContextClassRef>urn:oasis:names:tc:SAML:2.0:ac:classes:Password</AuthnContextClassRef></AuthnContext></AuthnStatement></Assertion></t:RequestedSecurityToken><t:RequestedAttachedReference><SecurityTokenReference d3p1:TokenType=\"http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLV2.0\" xmlns:d3p1=\"http://docs.oasis-open.org/wss/oasis-wss-wssecurity-secext-1.1.xsd\" xmlns=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecuri"
		"ty-secext-1.0.xsd\"><KeyIdentifier ValueType=\"http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLID\">_{CorrelationParameter_27}</KeyIdentifier></SecurityTokenReference></t:RequestedAttachedReference><t:RequestedUnattachedReference><SecurityTokenReference d3p1:TokenType=\"http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLV2.0\" xmlns:d3p1=\"http://docs.oasis-open.org/wss/oasis-wss-wssecurity-secext-1.1.xsd\" xmlns=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd\"><KeyIdentifier ValueType=\"http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLID\">_{CorrelationParameter_27}</KeyIdentifier></SecurityTokenReference></t:RequestedUnattachedReference><t:TokenType>http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLV2.0</t:TokenType><t:RequestType>http://schemas.xmlsoap.org/ws/2005/02/trust/Issue</t:RequestType><t:KeyType>http://schemas.xmlsoap.org/ws/2005/05/identity/NoProofKey</t:KeyType></t:RequestSecurityToke"
		"nResponse>", "ENDITEM",
		"Name=wctx", "Value=pr=wsfederation&rm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&ru=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2fmain.aspx%3fappid%3dab18c93f-61e6-e711-a848-000d3ad117e3&ry=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2fmain.aspx%3fappid%3dab18c93f-61e6-e711-a848-000d3ad117e3&crmorgid=9eb199a9-d221-43d7-8d01-7006601d9cc1&nonce=CRMWSFed.nonce.{CorrelationParameter_22}", "ENDITEM",
		"LAST");

	lr_end_transaction("CRM_01_b_SignIn",2);
	
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
		"LAST");

	 







 





	
	web_reg_save_param(
		"CorrelationParameter_30",
		"LB/IC=REQ_ID:",
		"RB/IC=\r\nX-Ua-Compatible:",
		"LAST");
	
 





	 




	
	web_reg_save_param(
		"tstamp",
		"LB/IC=?tstamp=",
		"RB/IC=&amp",
		"LAST");

	web_reg_save_param(
		"updateTimeStamp",
		"LB/IC=updateTimeStamp=",
		"RB/IC=&amp",
		"LAST");

	web_reg_save_param(
		"userts",
		"LB/IC=USER_TIMESTAMP = '",
		"RB/IC='",
		"LAST");
	
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_112",
		"RegExp=\\{Token:\\ '(.*?)',\\ Timestamp:\\ ",
		"Ordinal=4",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/main.aspx*",
		"LAST");
	
 
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_1121",
		"RegExp=\\{Token:\\ '(.*?)',\\ Timestamp:\\ ",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/main.aspx*",
		"LAST");

	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_1111",
		"RegExp=,\\ Timestamp:\\ \"(.*?)\"}",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/main.aspx*",
		"LAST");
		
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_2122",
		"RegExp=\\{Token:\\ '(.*?)',\\ Timestamp:\\ ",
		"Ordinal=2",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/main.aspx*",
		"LAST");

	web_reg_save_param(
		"CorrelationParameter_51",
		"LB/IC=REQ_ID:",
		"RB/IC=\r\nX-Ua-Compatible:",
		"LAST");

 
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_2123",
		"RegExp=MSISAuth=(.*?);",
		"SEARCH_FILTERS",
		"Scope=Cookies",
		"IgnoreRedirections=No",
		"RequestUrl=*/main.aspx*",
		"LAST");

 
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_2124",
		"RegExp=MSISAuth1=(.*?);",
		"SEARCH_FILTERS",
		"Scope=Cookies",
		"IgnoreRedirections=No",
		"RequestUrl=*/main.aspx*",
		"LAST");

 
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_2125",
		"RegExp==\\ '(.*?)';\\\r\\\nvar\\ REMIND_AUTH_EXPIRATION\\ ",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/main.aspx*",
		"LAST");

 
	web_reg_save_param(
		"themeID",
		"LB/IC=themeId=",
		"RB/IC=&amp",
		"LAST");

 
	web_reg_save_param(
		"lcid1",
		"LB/IC=?lcid=",
		"RB/IC=&amp;ver=",
		"LAST");

 
	web_reg_save_param(
		"verID1",
		"LB/IC=&amp;ver=",
		"RB/IC=\"",
		"LAST");

 
web_reg_save_param(
		"msdyn_Load1",
		"LB/IC=%7B",
		"RB/IC=%7D/WebResources/msdyn_LoadNPSSurvey",
		"LAST");

	web_reg_save_param("userguid","LB=USER_GUID = '\\x7b","RB=\\x7d';","LAST");

	lr_start_transaction("CRM_01_c_DashBoard");

	web_submit_data("main.aspx_2",
		"Action=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3",
		"Method=POST",
		"RecContentType=text/html",
		"Referer=https://cloudredirector.crm6.dynamics.com/G/AuthRedirect/Index.aspx?RedirectTo=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2fmain.aspx%3fappid%3dab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t890.inf",
		"Mode=HTTP",
		"ITEMDATA",
		"Name=wa", "Value=wsignin1.0", "ENDITEM",
		"Name=wresult", "Value=<t:RequestSecurityTokenResponse xmlns:t=\"http://schemas.xmlsoap.org/ws/2005/02/trust\"><t:Lifetime><wsu:Created xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">{CorrelationParameter_25}</wsu:Created><wsu:Expires xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">{CorrelationParameter_26}</wsu:Expires></t:Lifetime><wsp:AppliesTo xmlns:wsp=\"http://schemas.xmlsoap.org/ws/2004/09/policy\"><wsa:EndpointReference xmlns:wsa=\"http://www.w3.org/2005/08/addressing\"><wsa:Address>https://{param_URL}.crm6.dynamics.com/</wsa:Address></wsa:EndpointReference></wsp:AppliesTo><t:RequestedSecurityToken><Assertion ID=\"_{CorrelationParameter_27}\" IssueInstant=\"{CorrelationParameter_28}\" Version=\"2.0\" xmlns=\"urn:oasis:names:tc:SAML:2.0:assertion\"><Issuer>https://sts.windows.net/c0e0601f-0fac-449c-9c88-a104c4eb9f28/</Issuer><Signature xmlns=\"http://www.w3.org/2000/09/xmldsig#\"><SignedInfo><CanonicalizationMeth"
		"od Algorithm=\"http://www.w3.org/2001/10/xml-exc-c14n#\" /><SignatureMethod Algorithm=\"http://www.w3.org/2001/04/xmldsig-more#rsa-sha256\" /><Reference URI=\"#_{CorrelationParameter_27}\"><Transforms><Transform Algorithm=\"http://www.w3.org/2000/09/xmldsig#enveloped-signature\" /><Transform Algorithm=\"http://www.w3.org/2001/10/xml-exc-c14n#\" /></Transforms><DigestMethod Algorithm=\"http://www.w3.org/2001/04/xmlenc#sha256\" /><DigestValue>{DigestValue_2}</DigestValue></Reference></SignedInfo><SignatureValue>{SignatureValue_2}</SignatureValue><KeyInfo><X509Data><X509Certificate>{CorrelationParameter_7_1}</X509Certificate></X509Data></KeyInfo></Signature><Subject><NameID Format=\"urn:oasis:names:tc:SAML:2.0:nameid-format:persistent\">{CorrelationParameter_8_1}</NameID><SubjectConfirmation Method=\"urn:oasis:names:tc:SAML:2.0:cm:bearer\" /></Subject><Conditions NotBefore=\"{CorrelationParameter_25}\" NotOnOrAfter=\"{CorrelationParameter_26}\"><AudienceRestriction><Audience>https://fsvhublinkprodpilot.crm6.dy"
		"namics.com/</Audience></AudienceRestriction></Conditions><AttributeStatement><Attribute Name=\"http://schemas.microsoft.com/identity/claims/tenantid\"><AttributeValue>c0e0601f-0fac-449c-9c88-a104c4eb9f28</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/identity/claims/objectidentifier\"><AttributeValue>{AttributeValue_1}</AttributeValue></Attribute><Attribute Name=\"http://schemas.xmlsoap.org/ws/2005/05/identity/claims/name\"><AttributeValue>{param_UserID2}@dhhsvicgovau.onmicrosoft.com</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/identity/claims/puid\"><AttributeValue>{CorrelationParameter_9_1}</AttributeValue></Attribute><Attribute Name=\"http://schemas.xmlsoap.org/ws/2005/05/identity/claims/surname\"><AttributeValue>{corr_surname}</AttributeValue></Attribute><Attribute Name=\"http://schemas.xmlsoap.org/ws/2005/05/identity/claims/givenname\"><AttributeValue>{corr_givenname}</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/identity/cla"
		"ims/displayname\"><AttributeValue>{corr_displayname}</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/identity/claims/identityprovider\"><AttributeValue>https://sts.windows.net/c0e0601f-0fac-449c-9c88-a104c4eb9f28/</AttributeValue></Attribute><Attribute Name=\"http://schemas.microsoft.com/claims/authnmethodsreferences\"><AttributeValue>http://schemas.microsoft.com/ws/2008/06/identity/authenticationmethod/password</AttributeValue></Attribute></AttributeStatement><AuthnStatement AuthnInstant=\"{CorrelationParameter_29}\"><AuthnContext><AuthnContextClassRef>urn:oasis:names:tc:SAML:2.0:ac:classes:Password</AuthnContextClassRef></AuthnContext></AuthnStatement></Assertion></t:RequestedSecurityToken><t:RequestedAttachedReference><SecurityTokenReference d3p1:TokenType=\"http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLV2.0\" xmlns:d3p1=\"http://docs.oasis-open.org/wss/oasis-wss-wssecurity-secext-1.1.xsd\" xmlns=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecuri"
		"ty-secext-1.0.xsd\"><KeyIdentifier ValueType=\"http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLID\">_{CorrelationParameter_27}</KeyIdentifier></SecurityTokenReference></t:RequestedAttachedReference><t:RequestedUnattachedReference><SecurityTokenReference d3p1:TokenType=\"http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLV2.0\" xmlns:d3p1=\"http://docs.oasis-open.org/wss/oasis-wss-wssecurity-secext-1.1.xsd\" xmlns=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd\"><KeyIdentifier ValueType=\"http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLID\">_{CorrelationParameter_27}</KeyIdentifier></SecurityTokenReference></t:RequestedUnattachedReference><t:TokenType>http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLV2.0</t:TokenType><t:RequestType>http://schemas.xmlsoap.org/ws/2005/02/trust/Issue</t:RequestType><t:KeyType>http://schemas.xmlsoap.org/ws/2005/05/identity/NoProofKey</t:KeyType></t:RequestSecurityToke"
		"nResponse>", "ENDITEM",
		"Name=wctx", "Value=pr=wsfederation&rm=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f&ru=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2fmain.aspx%3fappid%3dab18c93f-61e6-e711-a848-000d3ad117e3&ry=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2fmain.aspx%3fappid%3dab18c93f-61e6-e711-a848-000d3ad117e3&crmorgid=9eb199a9-d221-43d7-8d01-7006601d9cc1&nonce=CRMWSFed.nonce.{CorrelationParameter_22}", "ENDITEM",
		"LAST");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_concurrent_start(0);

	web_url("fonts.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_common/styles/fonts.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t891.inf", 
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

	web_concurrent_end(0);

	(web_remove_auto_header("Accept-Language", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("Cache-Control", "ImplicitGen=Yes", "LAST"));

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
 
# 1660 "CRM_Login_Popup.c"
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
		"LAST");

	web_add_auto_header("Accept", 
		"application/javascript, */*;q=0.8");

	web_url("Microsoft.Crm.Client.Core.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/Microsoft.Crm.Client.Core.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t941.inf", 
		"LAST");

	web_url("MicrosoftAjax.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/MicrosoftAjax.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t942.inf", 
		"LAST");

	web_concurrent_start(0);

	 







	web_url("CrmServiceProxy.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/CrmServiceProxy.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t944.inf", 
		"LAST");

	web_url("CrmServiceProxyFramework.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/CrmServiceProxyFramework.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t945.inf", 
		"LAST");

	web_url("organizations(9EB199A9-D221-43D7-8D01-7006601D9CC1)", 
		"URL=https://{param_URL}.crm6.dynamics.com/api/data/v9.0/organizations(9EB199A9-D221-43D7-8D01-7006601D9CC1)?$select=%20postmessagewhitelistdomains", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t946.inf", 
		"LAST");

	web_url("NavBarDivider.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/NavBar/NavBarDivider.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t947.inf", 
		"LAST");

	web_url("Theme_NavBarLogo.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/oobwebresource/Theme_NavBarLogo.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t948.inf", 
		"LAST");

	web_url("JsProvider.ashx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_common/JsProvider.ashx?ids=346338581-1481678315&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t949.inf", 
		"LAST");

	web_url("emptyuserimage.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/navbar/emptyuserimage.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t950.inf", 
		"LAST");

	web_add_header("Origin", 
		"https://{param_URL}.crm6.dynamics.com");

	web_url("seguisb.woff", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/seguisb.woff", 
		"Resource=1", 
		"RecContentType=font/x-woff", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t951.inf", 
		"LAST");

	web_concurrent_end(0);

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
		"LAST");

	web_add_header("Origin", 
		"https://{param_URL}.crm6.dynamics.com");

	web_concurrent_start(0);

	web_url("D365Shell.woff", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/D365Shell.woff", 
		"Resource=1", 
		"RecContentType=font/x-woff", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t953.inf", 
		"LAST");

	web_url("control_imgs.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/imagestrips/control_imgs.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t954.inf", 
		"LAST");

	web_url("NavBarAppSwitcher.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/NavBar/NavBarAppSwitcher.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t955.inf", 
		"LAST");

	web_url("commandbarmenudown.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/commandbarmenudown.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t956.inf", 
		"LAST");

	web_url("more_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/more_16.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t957.inf", 
		"LAST");

	web_url("navbar_header.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/imagestrips/navbar_header.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t958.inf", 
		"LAST");

	web_url("ribbonhomepage.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/imagestrips/ribbonhomepage.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t959.inf", 
		"LAST");

	web_concurrent_end(0);

	web_add_auto_header("Accept", 
		"text/html, application/xhtml+xml, */*");

 






	web_reg_save_param(
		"CorrelationParameter_32",
		"LB/IC=REQ_ID:",
		"RB/IC=\r\nX-Ua-Compatible:",
		"LAST");
	

	web_reg_save_param("userguid","LB=USER_GUID = '\\x7b","RB=\\x7d';","LAST");

	web_url("home_dashboards.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t960.inf", 
		"Mode=HTTP", 
		"LAST");

	web_concurrent_start(0);

	web_url("form.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_forms/controls/form.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t961.inf", 
		"LAST");

	web_url("select.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_common/styles/select.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t962.inf", 
		"LAST");

	web_url("menu.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_nav/menu.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t963.inf", 
		"LAST");

	web_url("CompositeControl.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_controls/CompositeControl/CompositeControl.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t964.inf", 
		"LAST");

	web_url("appgrid.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_grid/appgrid.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t965.inf", 
		"LAST");

	web_url("tabs.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_nav/tabs.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t966.inf", 
		"LAST");

	web_url("read.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_forms/styles/read.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t967.inf", 
		"LAST");

	web_url("activitycontainer.css.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/activitycontainer/activitycontainer.css.aspx?{lcid1}&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t968.inf", 
		"LAST");

	web_url("visualization.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/visualization/visualization.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t969.inf", 
		"LAST");

	web_url("dashboardselector.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/dashboardselector.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t970.inf", 
		"LAST");

	web_url("lookupbehavior.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_forms/lookupbehavior.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t971.inf", 
		"LAST");

	web_url("GridControl.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_grid/GridControl.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t972.inf", 
		"LAST");

	web_url("form.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_forms/form.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t973.inf", 
		"LAST");

	web_url("menuselector.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/menuselector/menuselector.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t974.inf", 
		"LAST");

	web_url("select.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_forms/select.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t975.inf", 
		"LAST");

	web_url("stage.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/stage.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t976.inf", 
		"LAST");

	web_url("glowingimage.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/glowingimage.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t977.inf", 
		"LAST");

	web_url("HintText.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/HintText/HintText.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t978.inf", 
		"LAST");

	web_url("visualizationactions.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/visualization/visualizationactions.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t979.inf", 
		"LAST");

	web_url("es6-shim.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/es6-shim.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t980.inf", 
		"LAST");

	web_url("visualizationpane.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/pane/visualizationpane.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t981.inf", 
		"LAST");

	web_url("DataSetControl.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_grid/DataSetControl.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t982.inf", 
		"LAST");

	web_url("checkbox.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_forms/checkbox.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t983.inf", 
		"LAST");

	web_url("ActivityCommandBar.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/ActivityContainer/ActivityCommandBar.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t984.inf", 
		"LAST");

	web_url("RibbonLayout.js.aspx_2",
		"URL=https://{param_URL}.crm6.dynamics.com/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=dhhs_screening&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cdhhs_screening%7cNoRelationship%7c&ie=1&ise=1&{lcid1}&mver={tstamp}&oc=0&page=%2fWORKPLACE%2fHOME_DASHBOARDS.ASPX&relName=&relType=NoRelationship&rver=990654873&ver=-239230285&wrdepver=00000000000000000000000000000000",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t985.inf",
		"LAST");

	web_url("details.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_common/scripts/details.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t986.inf", 
		"LAST");

	web_url("RibbonLayout.js.aspx_3",
		"URL=https://{param_URL}.crm6.dynamics.com/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=incident&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cincident%7cNoRelationship%7c&ie=1&ise=1&{lcid1}&mver={tstamp}&oc=0&page=%2fWORKPLACE%2fHOME_DASHBOARDS.ASPX&relName=&relType=NoRelationship&rver=990654873&ver=-239230285&wrdepver=00000000000000000000000000000000",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t987.inf",
		"LAST");

	web_url("action.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_grid/action.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t988.inf", 
		"LAST");

	web_url("lookup.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/lookup/lookup.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t989.inf", 
		"LAST");

	web_url("RibbonLayout.js.aspx_4",
		"URL=https://{param_URL}.crm6.dynamics.com/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=activitypointer&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cactivitypointer%7cNoRelationship%7c&ie=1&ise=1&{lcid1}&mver={tstamp}&oc=0&page=%2fWORKPLACE%2fHOME_DASHBOARDS.ASPX&relName=&relType=NoRelationship&rver=990654873&ver=-239230285&wrdepver=00000000000000000000000000000000",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t990.inf",
		"LAST");

	web_url("addrelated.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_forms/addrelated.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t991.inf", 
		"LAST");

	web_url("RibbonLayout.js.aspx_5",
		"URL=https://{param_URL}.crm6.dynamics.com/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=queueitem&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cqueueitem%7cNoRelationship%7c&ie=1&ise=1&{lcid1}&mver={tstamp}&oc=0&page=%2fWORKPLACE%2fHOME_DASHBOARDS.ASPX&relName=&relType=NoRelationship&rver=990654873&ver=-239230285&wrdepver=00000000000000000000000000000000",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t992.inf",
		"LAST");

	web_url("popupmenu.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/popupmenu/popupmenu.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t993.inf", 
		"LAST");

	web_url("time.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/_static/_controls/datetime/time.js?ver=-239230285", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t994.inf", 
		"LAST");

	web_url("addphone_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addphone_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t995.inf", 
		"LAST");

	web_url("addemail_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addemail_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t996.inf", 
		"LAST");

	web_url("addtask_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addtask_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t997.inf", 
		"LAST");

	web_url("addappointment_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addappointment_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t998.inf", 
		"LAST");

	web_url("addcampaignresponse_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addcampaignresponse_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t999.inf", 
		"LAST");

	web_url("addactivity_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addactivity_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1000.inf", 
		"LAST");

	web_url("addfax_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addfax_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1001.inf", 
		"LAST");

	web_url("addletter_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addletter_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1002.inf", 
		"LAST");

	web_url("addserviceactivity_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/ribbon/addserviceactivity_16.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1003.inf", 
		"LAST");

	web_url("Calendar_16.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/%7B{msdyn_Load1}%7D/WebResources/msdyn_/fps/Icons/Entity/Calendar_16.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1004.inf", 
		"LAST");

	web_concurrent_end(0);

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
		"LAST");

	web_url("RenderGridView.aspx_2",
		"URL=https://{param_URL}.crm6.dynamics.com/_grid/RenderGridView.aspx?autoExpand=0&deleteAction=&em=1&enableContextualActions=&eventManagerId=crmEventManager&expandable=1&gridType=SubGrid&id=Componentb177617&isGridHidden=false&isSubGridLite=1&jumpbar=0&{lcid1}&loadOnDemand=0&maxRows=12&mdts={tstamp}&oType=&recsPerPage=8&relationshipType=0&relName=&ribbonContext=SubGridStandard&roleOrd=-1&tabIndex=0&teamTmplId=&ver=-239230285&viewid=%7bE87C42AF-07D0-E711-A826-000D3AE0A7F8%7d&viewts=3144254&viewtype=1039",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t1006.inf",
		"Mode=HTTP",
		"LAST");

	web_url("RenderGridView.aspx_3",
		"URL=https://{param_URL}.crm6.dynamics.com/_grid/RenderGridView.aspx?autoExpand=0&deleteAction=&em=1&enableContextualActions=&eventManagerId=crmEventManager&expandable=1&gridType=SubGrid&id=Component376145d&isGridHidden=false&isSubGridLite=1&jumpbar=0&{lcid1}&loadOnDemand=0&maxRows=24&mdts={tstamp}&oType=&recsPerPage=20&relationshipType=0&relName=&ribbonContext=SubGridStandard&roleOrd=-1&tabIndex=0&teamTmplId=&ver=-239230285&viewid=%7bAD7A2839-61CB-E711-A844-000D3AD11148%7d&viewts=3143913&viewtype=1039",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t1007.inf",
		"Mode=HTTP",
		"LAST");

	web_url("RenderGridView.aspx_4",
		"URL=https://{param_URL}.crm6.dynamics.com/_grid/RenderGridView.aspx?autoExpand=0&deleteAction=&em=1&enableContextualActions=&eventManagerId=crmEventManager&expandable=1&gridType=SubGrid&id=Componenta3058e5&isGridHidden=false&isSubGridLite=1&jumpbar=0&{lcid1}&loadOnDemand=0&maxRows=12&mdts={tstamp}&oType=&recsPerPage=8&relationshipType=0&relName=&ribbonContext=SubGridStandard&roleOrd=-1&tabIndex=0&teamTmplId=&ver=-239230285&viewid=%7b4962E489-10D0-E711-A826-000D3AE0A7F8%7d&viewts=3142834&viewtype=1039",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642",
		"Snapshot=t1008.inf",
		"Mode=HTTP",
		"LAST");

	web_url("grid_ctrl_imgs.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/imagestrips/grid_ctrl_imgs.png?ver=-239230285", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1009.inf", 
		"LAST");

	(web_remove_auto_header("X-P2P-PeerDist", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("X-P2P-PeerDistEx", "ImplicitGen=Yes", "LAST"));

	web_add_header("SOAPAction",
		"http://schemas.microsoft.com/crm/2009/WebServices/GetDashboardWrpcTokens");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate");

	web_add_auto_header("Cache-Control", 
		"no-cache");

	web_convert_from_formatted("FormattedData=<?xml version=\"1.0\" encoding=\"utf-8\"?><HP_EXTENSION name=\"Xml\"><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetDashboardWrpcTokens xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"></GetDashboardWrpcTokens></soap:Body></soap:Envelope></HP_EXTENSION>", 
		"TargetParam=DFE_BODY_1", 
		"LAST");

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
		"LAST");

	web_add_header("SOAPAction",
		"http://schemas.microsoft.com/crm/2009/WebServices/GetDefaultDashboardId");

	web_convert_from_formatted("FormattedData=<?xml version=\"1.0\" encoding=\"utf-8\"?><HP_EXTENSION name=\"Xml\"><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetDefaultDashboardId xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"><siteMapPath>NewArea_6370afe4&#124;group_myWork&#124;NewSubArea_cb6d1642</siteMapPath><appid>ab18c93f-61e6-e711-a848-000d3ad117e3</appid></GetDefaultDashboardId></soap:Body></soap:Envelope></HP_EXTENSION>", 
		"TargetParam=DFE_BODY_2", 
		"LAST");

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
		"LAST");

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
		"LAST");

	web_add_header("SOAPAction",
		"http://schemas.microsoft.com/crm/2009/WebServices/GetUserDashboardListHash");

	web_convert_from_formatted("FormattedData=<?xml version=\"1.0\" encoding=\"utf-8\"?><HP_EXTENSION name=\"Xml\"><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetUserDashboardListHash xmlns=\"http://schemas.microsoft.com/crm/2009/WebServices\"></GetUserDashboardListHash></soap:Body></soap:Envelope></HP_EXTENSION>", 
		"TargetParam=DFE_BODY_3", 
		"LAST");

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
		"LAST");

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
		"LAST");

	(web_remove_auto_header("ReferrerReqId", "ImplicitGen=Yes", "LAST"));

	web_add_auto_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_convert_from_formatted("FormattedData=<HP_EXTENSION name=\"JsonXml,Xml\"><object><object name=\"request\"><array name=\"MetricsCollections\"><object><pair name=\"RequestId\" type=\"str\">d22513f8-328b-4666-a9fc-ac30b6ca9689</pair><array name=\"Metrics\"><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946071739</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"num\">1523946067099</pair><pair name=\"componentId\" type=\"str\">main.aspx</pair><pair name=\"componentInfo\" type=\"str\">precise</pair><pair name=\"marker\" type=\"str\">loadStart</pair><pair name=\"navigation\" type=\"num\">0</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946071740</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"num\">1523946068908</pair><pair name=\"componentId\" type=\"str\">main.aspx</pair><pair name=\"componentInfo\" type=\"str\"></pair><pair name=\"marker\" type=\"str\">responseStart</pair><pair name=\"navigation\" type=\"num\">0</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946071740</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"num\">1523946068918</pair><pair name=\"componentId\" type=\"str\">main.aspx</pair><pair name=\"componentInfo\" type=\"str\"></pair><pair name=\"marker\" type=\"str\">responseEnd</pair><pair name=\"navigation\" type=\"num\">0</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946071740</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"num\">1523946071740</pair><pair name=\"componentId\" type=\"str\">main.aspx</pair><pair name=\"componentInfo\" type=\"str\"></pair><pair name=\"marker\" type=\"str\">loaded</pair><pair name=\"navigation\" type=\"num\">0</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">pagenavigations</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946071908</pair><object name=\"p\"><pair name=\"navigatedAt\" type=\"str\">\\/Date(1523946071907)\\/</pair><pair name=\"navigationCounter\" type=\"num\">1</pair><pair name=\"navigationUri\" type=\"str\">/workplace/home_dashboards.aspx?sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642</pair><pair name=\"tabSessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946071908</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"str\">\\/Date(1523946071908)\\/</pair><pair name=\"componentId\" type=\"str\">pagenavigations</pair><pair name=\"componentInfo\" type=\"str\">/workplace/home_dashboards.aspx?sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642</pair><pair name=\"marker\" type=\"str\">navigationStart</pair><pair name=\"navigation\" type=\"num\">1</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946071934</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"str\">\\/Date(1523946071934)\\/</pair><pair name=\"componentId\" type=\"str\">pagenavigations</pair><pair name=\"componentInfo\" type=\"str\">/workplace/home_dashboards.aspx?sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642</pair><pair name=\"marker\" type=\"str\">navigationEnd</pair><pair name=\"navigation\" type=\"num\">1</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommand.Execute</pair><pair name=\"v\" type=\"num\">2259</pair><pair name=\"t\" type=\"num\">1523946073800</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">MessageBar</pair><pair name=\"ReqId\" type=\"str\">44eb6a18-749e-45bb-b320-89d42ad52c0e</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommand.Execute</pair><pair name=\"v\" type=\"num\">186</pair><pair name=\"t\" type=\"num\">1523946096716</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">RecentlyViewedWebService</pair><pair name=\"ReqId\" type=\"str\">679de8a0-89fa-4e37-a6c3-52a895eecec1</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommand.Execute</pair><pair name=\"v\" type=\"num\">1109</pair><pair name=\"t\" type=\"num\">1523946134611</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">LookupMruWebService</pair><pair name=\"ReqId\" type=\"str\">12a8b43c-bc9e-43e6-a460-9981231e6362</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommand.Execute</pair><pair name=\"v\" type=\"num\">1123</pair><pair name=\"t\" type=\"num\">1523946134599</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">RecentlyViewedWebService</pair><pair name=\"ReqId\" type=\"str\">1aa90dcc-f030-48d5-aaba-733d7458173c</pair></object></object></array><pair name=\"IsExistingActivity\" type=\"bool\">true</pair></object><object><pair name=\"RequestId\" type=\"str\">c2d0993d-de6a-48c7-9c20-7db152668f0f</pair><array name=\"Metrics\"><object><pair name=\"n\" type=\"str\">RemoteCommand.Execute</pair><pair name=\"v\" type=\"num\">321</pair><pair name=\"t\" type=\"num\">1523946096541</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">DashboardWebService</pair><pair name=\"ReqId\" type=\"str\">32b8f6cf-f1dc-46c3-9fef-d04bb3543dbe</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommand.Execute</pair><pair name=\"v\" type=\"num\">334</pair><pair name=\"t\" type=\"num\">1523946096539</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">DashboardWebService</pair><pair name=\"ReqId\" type=\"str\">b56f42fa-c9f7-4fad-9f5f-1e2d6010a0dc</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommand.Execute</pair><pair name=\"v\" type=\"num\">345</pair><pair name=\"t\" type=\"num\">1523946096533</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">DashboardWebService</pair><pair name=\"ReqId\" type=\"str\">95992587-6955-4120-8d97-6b0aa4ee6765</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommandXml.Execute</pair><pair name=\"v\" type=\"num\">353</pair><pair name=\"t\" type=\"num\">1523946110613</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">AppGridWebService</pair><pair name=\"ReqId\" type=\"str\">83b97765-6706-4fd1-a41b-2af10fa5d718</pair></object></object><object><pair name=\"n\" type=\"str\">SubGrid</pair><pair name=\"v\" type=\"num\">429</pair><pair name=\"t\" type=\"num\">1523946110602</pair><object name=\"p\"><pair name=\"id\" type=\"str\">Component17fb94f</pair><pair name=\"IsAsync\" type=\"bool\">true</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946111031</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"num\">1523946111031</pair><pair name=\"componentId\" type=\"str\">Component17fb94f</pair><pair name=\"componentInfo\" type=\"str\"></pair><pair name=\"marker\" type=\"str\">loaded</pair><pair name=\"navigation\" type=\"num\">1</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommandXml.Execute</pair><pair name=\"v\" type=\"num\">202</pair><pair name=\"t\" type=\"num\">1523946110833</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">AppGridWebService</pair><pair name=\"ReqId\" type=\"str\">e1ca3ea1-a5f2-4f7e-a8d3-84d35705ff12</pair></object></object><object><pair name=\"n\" type=\"str\">SubGrid</pair><pair name=\"v\" type=\"num\">335</pair><pair name=\"t\" type=\"num\">1523946110826</pair><object name=\"p\"><pair name=\"id\" type=\"str\">Component376145d</pair><pair name=\"IsAsync\" type=\"bool\">true</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946111162</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"num\">1523946111161</pair><pair name=\"componentId\" type=\"str\">Component376145d</pair><pair name=\"componentInfo\" type=\"str\"></pair><pair name=\"marker\" type=\"str\">loaded</pair><pair name=\"navigation\" type=\"num\">1</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommandXml.Execute</pair><pair name=\"v\" type=\"num\">318</pair><pair name=\"t\" type=\"num\">1523946110905</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">AppGridWebService</pair><pair name=\"ReqId\" type=\"str\">6e93d49c-091d-4e78-9948-129faa7e3042</pair></object></object><object><pair name=\"n\" type=\"str\">SubGrid</pair><pair name=\"v\" type=\"num\">359</pair><pair name=\"t\" type=\"num\">1523946110899</pair><object name=\"p\"><pair name=\"id\" type=\"str\">Componentb177617</pair><pair name=\"IsAsync\" type=\"bool\">true</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946111259</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"num\">1523946111259</pair><pair name=\"componentId\" type=\"str\">Componentb177617</pair><pair name=\"componentInfo\" type=\"str\"></pair><pair name=\"marker\" type=\"str\">loaded</pair><pair name=\"navigation\" type=\"num\">1</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object><object><pair name=\"n\" type=\"str\">RemoteCommandXml.Execute</pair><pair name=\"v\" type=\"num\">389</pair><pair name=\"t\" type=\"num\">1523946110871</pair><object name=\"p\"><pair name=\"IsAsync\" type=\"bool\">true</pair><pair name=\"Service\" type=\"str\">AppGridWebService</pair><pair name=\"ReqId\" type=\"str\">b521f550-327f-44b6-b6a6-c4e3b64b4f83</pair></object></object><object><pair name=\"n\" type=\"str\">SubGrid</pair><pair name=\"v\" type=\"num\">465</pair><pair name=\"t\" type=\"num\">1523946110864</pair><object name=\"p\"><pair name=\"id\" type=\"str\">Componenta3058e5</pair><pair name=\"IsAsync\" type=\"bool\">true</pair></object></object><object><pair name=\"n\" type=\"str\">clienttimeline</pair><pair name=\"v\" type=\"null\">null</pair><pair name=\"t\" type=\"num\">1523946111330</pair><object name=\"p\"><pair name=\"browserTimestamp\" type=\"num\">1523946111330</pair><pair name=\"componentId\" type=\"str\">Componenta3058e5</pair><pair name=\"componentInfo\" type=\"str\"></pair><pair name=\"marker\" type=\"str\">loaded</pair><pair name=\"navigation\" type=\"num\">1</pair><pair name=\"sessionId\" type=\"str\">7fa23607-b06d-4d65-bff0-25179df54f40</pair></object></object></array><pair name=\"IsExistingActivity\" type=\"bool\">true</pair></object></array></object></object></HP_EXTENSION>", 
		"TargetParam=DFE_BODY_4", 
		"LAST");

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
		"LAST");

	lr_save_string(lr_eval_string("{CorrelationParameter_112}"), "path1");
	
	crmwrpctoken();
	
	 
# 2485 "CRM_Login_Popup.c"

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
		"LAST");

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
		"LAST");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_concurrent_start(0);

	web_url("process.js", 
		"URL=https://{param_URL}.crm6.dynamics.com/%7B{msdyn_Load1}%7D/WebResources/mag_/js/process.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=-239230285", 
		"Resource=1", 
		"RecContentType=text/jscript", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1017.inf", 
		"LAST");

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
		"LAST");

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
		"LAST");

	web_concurrent_end(0);

	(web_remove_auto_header("LoginRequestCorrelationId", "ImplicitGen=Yes", "LAST"));

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

	lr_end_transaction("CRM_01_c_DashBoard",2);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_concurrent_start(0);

	web_url("default.png", 
		"URL=https://{param_URL}.crm6.dynamics.com/_imgs/EmptyStates/default.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{param_URL}.crm6.dynamics.com/workplace/home_dashboards.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&pagemode=iframe&sitemappath=NewArea_6370afe4%7cgroup_myWork%7cNewSubArea_cb6d1642", 
		"Snapshot=t1024.inf", 
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_add_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	 
	 

	web_url("systemusers()", 
		"URL=https://{param_URL}.crm6.dynamics.com/api/data/V9.0/systemusers()?$select=azureactivedirectoryobjectid&$filter=systemuserid%20eq%20{userguid}", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1040.inf", 
		"LAST");

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
		"LAST");

	web_concurrent_end(0);

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
		"LAST");

	web_add_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_reg_save_param("MASTER","LB/IC=MASTER\",\"version\":\"","RB=\"}","Ord=All","LAST");

	web_url("config", 
		"URL=https://home.dynamics.com/api/config", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1043.inf", 
		"LAST");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	web_concurrent_start(0);

	web_url("NPSSurvey.css", 
		"URL=https://crmprodnpssurvey.azureedge.net/survey/NPSSurvey.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1044.inf", 
		"LAST");

	 
# 3246 "CRM_Login_Popup.c"

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
		"LAST");

	 
# 3291 "CRM_Login_Popup.c"

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

	 
# 3361 "CRM_Login_Popup.c"

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
		"LAST");

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
		"LAST");

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
		"LAST");

	web_concurrent_end(0);

	 

	web_add_cookie("ESTSAUTHPERSISTENT={ESTSAUTHPERSISTENT_6}; DOMAIN=login.microsoftonline.com");

	web_add_cookie("ESTSAUTH={ESTSAUTH_2}; DOMAIN=login.microsoftonline.com");

	(web_remove_auto_header("Cache-Control", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("ReferrerReqId", "ImplicitGen=Yes", "LAST"));

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate, peerdist");

	web_add_auto_header("Accept", 
		"text/html, application/xhtml+xml, */*");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_33",
		"RegExp=state=OpenIdConnect.AuthenticationProperties%3d(.*?)&nonce",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"RequestUrl=*/signon*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=nonce_3",
		"RegExp=nonce=(.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"RequestUrl=*/signon*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=nonce_4",
		"RegExp=nonce=(.*?)&amp",
		"DFEs=Xml",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Body",
		"RequestUrl=*/authorize*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=session_state_2",
		"RegExp=name=\"session_state\"\\ value=\"(.*?)\"\\ ",
		"DFEs=Xml",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/authorize*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=code_2",
		"RegExp=name=\"code\"\\ value=\"(.*?)\"\\ ",
		"DFEs=Xml",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/authorize*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_34",
		"RegExp=name=\"id_token\"\\ value=\"(.*?)\"\\ ",
		"DFEs=Xml",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/authorize*",
		"LAST");
	
	web_reg_save_param_regexp(
		"ParamName=client_id_1",
		"RegExp=client_id=(.*?)&response_mode",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"RequestUrl=*/signon*",
		"LAST");

	web_url("signon", 
		"URL=https://home.dynamics.com/proxy/signon?d365FrameChannelId=6b5c3763-3251-49f7-bff1-25f475cb19a5", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t1057.inf", 
		"Mode=HTTP", 
		"LAST");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate");

	web_add_auto_header("Cache-Control", 
		"no-cache");

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_35",
		"RegExp=type=\"hidden\"\\ value=\"(.*?)\"\\ ",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/proxy*",
		"LAST");

	web_reg_save_param_regexp(
		"ParamName=v_1",
		"RegExp=src=\"/bundles/proxy\\?v=(.*?)\"></script",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/proxy*",
		"LAST");

	web_submit_data("signon_2",
		"Action=https://home.dynamics.com/proxy/signon",
		"Method=POST",
		"RecContentType=text/html",
		"Referer=https://login.microsoftonline.com/common/oauth2/authorize?client_id={client_id_1}&response_mode=form_post&response_type=code+id_token&scope=openid+profile&state=OpenIdConnect.AuthenticationProperties%3d{CorrelationParameter_33}&nonce={nonce_3}",
		"Snapshot=t1058.inf",
		"Mode=HTTP",
		"ITEMDATA",
		"Name=code", "Value={code_2}", "ENDITEM",
		"Name=id_token", "Value={CorrelationParameter_34}", "ENDITEM",
		"Name=state", "Value=OpenIdConnect.AuthenticationProperties={CorrelationParameter_33}", "ENDITEM",
		"Name=session_state", "Value={session_state_2}", "ENDITEM",
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

	web_convert_from_formatted("FormattedData=<HP_EXTENSION name=\"JsonXml,Xml\"><array><object><object name=\"data\"><pair name=\"data\" type=\"str\">{\\&quot;serviceName\\&quot;:\\&quot;\\&quot;,\\&quot;appId\\&quot;:\\&quot;9eb199a9-d221-43d7-8d01-7006601d9cc1\\&quot;,\\&quot;time\\&quot;:74}</pair><pair name=\"eventName\" type=\"str\">appActiveSet</pair><pair name=\"eventTimeStamp\" type=\"str\">2018-04-17T06:38:51.089Z</pair><pair name=\"eventType\" type=\"str\">TelemetryAction</pair><pair name=\"objectId\" type=\"str\">{AttributeValue_1}</pair><pair name=\"principalId\" type=\"str\">{CorrelationParameter_9_1}</pair><pair name=\"region\" type=\"str\">westus</pair><pair name=\"sessionId\" type=\"str\">be66a651-c43d-4bf3-bee8-a6d30b5a4dc7</pair><pair name=\"tenantId\" type=\"str\">c0e0601f-0fac-449c-9c88-a104c4eb9f28</pair><pair name=\"trackingId\" type=\"str\">00000000-0000-0000-0000-000000000000</pair><pair name=\"userAgent\" type=\"str\">Mozilla/5.0 (Windows NT 6.3; WOW64; Trident/7.0; .NET4.0E; .NET4.0C; .NET CLR 3.5.30729; .NET CLR 2.0.50727; .NET CLR 3.0.30729; InfoPath.3; .NET CLR 1.1.4322; rv:11.0) like Gecko</pair><pair name=\"userHash\" type=\"str\">{AttributeValue_1}</pair></object><pair name=\"name\" type=\"str\">ClientTelemetry</pair></object></array></HP_EXTENSION>", 
		"TargetParam=DFE_BODY_10", 
		"LAST");

	web_custom_request("LogTrace", 
		"URL=https://home.dynamics.com/api/logging/LogTrace", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://home.dynamics.com/proxy?d365FrameChannelId=6b5c3763-3251-49f7-bff1-25f475cb19a5", 
		"Snapshot=t1062.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={DFE_BODY_10}", 
		"LAST");

	web_convert_from_formatted("FormattedData=<HP_EXTENSION name=\"JsonXml,Xml\"><array><object><object name=\"data\"><pair name=\"data\" type=\"str\">{\\&quot;viewportWidth\\&quot;:1920,\\&quot;viewportHeight\\&quot;:963,\\&quot;referrerUrl\\&quot;:\\&quot;https://cloudredirector.crm6.dynamics.com/G/AuthRedirect/Index.aspx?RedirectTo=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2fmain.aspx%3fappid%3dab18c93f-61e6-e711-a848-000d3ad117e3\\&quot;,\\&quot;hasHeader\\&quot;:false,\\&quot;hasTaskpane\\&quot;:true,\\&quot;inFocusMode\\&quot;:false,\\&quot;product\\&quot;:\\&quot;unknown\\&quot;,\\&quot;time\\&quot;:10520}</pair><pair name=\"eventName\" type=\"str\">shellLoaded</pair><pair name=\"eventTimeStamp\" type=\"str\">2018-04-17T06:38:51.089Z</pair><pair name=\"eventType\" type=\"str\">TelemetryAction</pair><pair name=\"objectId\" type=\"str\">{AttributeValue_1}</pair><pair name=\"principalId\" type=\"str\">{CorrelationParameter_9_1}</pair><pair name=\"region\" type=\"str\">westus</pair><pair name=\"sessionId\" type=\"str\">be66a651-c43d-4bf3-bee8-a6d30b5a4dc7</pair><pair name=\"tenantId\" type=\"str\">c0e0601f-0fac-449c-9c88-a104c4eb9f28</pair><pair name=\"trackingId\" type=\"str\">00000000-0000-0000-0000-000000000000</pair><pair name=\"userAgent\" type=\"str\">Mozilla/5.0 (Windows NT 6.3; WOW64; Trident/7.0; .NET4.0E; .NET4.0C; .NET CLR 3.5.30729; .NET CLR 2.0.50727; .NET CLR 3.0.30729; InfoPath.3; .NET CLR 1.1.4322; rv:11.0) like Gecko</pair><pair name=\"userHash\" type=\"str\">{AttributeValue_1}</pair></object><pair name=\"name\" type=\"str\">ClientTelemetry</pair></object></array></HP_EXTENSION>", 
		"TargetParam=DFE_BODY_11", 
		"LAST");

	web_custom_request("LogTrace_2", 
		"URL=https://home.dynamics.com/api/logging/LogTrace", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://home.dynamics.com/proxy?d365FrameChannelId=6b5c3763-3251-49f7-bff1-25f475cb19a5", 
		"Snapshot=t1063.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={DFE_BODY_11}", 
		"LAST");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

	 
# 3695 "CRM_Login_Popup.c"

	web_convert_from_formatted("FormattedData=<HP_EXTENSION name=\"JsonXml,Xml\"><array><object><object name=\"data\"><pair name=\"data\" type=\"str\">{\\&quot;isNewUser\\&quot;:false,\\&quot;uiLocation\\&quot;:\\&quot;taskpane\\&quot;,\\&quot;time\\&quot;:28237}</pair><pair name=\"eventName\" type=\"str\">appsInitialized</pair><pair name=\"eventTimeStamp\" type=\"str\">2018-04-17T06:39:07.741Z</pair><pair name=\"eventType\" type=\"str\">TelemetryAction</pair><pair name=\"objectId\" type=\"str\">{AttributeValue_1}</pair><pair name=\"principalId\" type=\"str\">{CorrelationParameter_9_1}</pair><pair name=\"region\" type=\"str\">westus</pair><pair name=\"sessionId\" type=\"str\">be66a651-c43d-4bf3-bee8-a6d30b5a4dc7</pair><pair name=\"tenantId\" type=\"str\">c0e0601f-0fac-449c-9c88-a104c4eb9f28</pair><pair name=\"trackingId\" type=\"str\">00000000-0000-0000-0000-000000000000</pair><pair name=\"userAgent\" type=\"str\">Mozilla/5.0 (Windows NT 6.3; WOW64; Trident/7.0; .NET4.0E; .NET4.0C; .NET CLR 3.5.30729; .NET CLR 2.0.50727; .NET CLR 3.0.30729; InfoPath.3; .NET CLR 1.1.4322; rv:11.0) like Gecko</pair><pair name=\"userHash\" type=\"str\">{AttributeValue_1}</pair></object><pair name=\"name\" type=\"str\">ClientTelemetry</pair></object></array></HP_EXTENSION>", 
		"TargetParam=DFE_BODY_12", 
		"LAST");

	web_custom_request("LogTrace_3", 
		"URL=https://home.dynamics.com/api/logging/LogTrace", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://home.dynamics.com/proxy?d365FrameChannelId=6b5c3763-3251-49f7-bff1-25f475cb19a5", 
		"Snapshot=t1066.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={DFE_BODY_12}", 
		"LAST");

	lr_think_time(3);

	 
# 3733 "CRM_Login_Popup.c"

	lr_think_time(3);

	(web_remove_auto_header("Cache-Control", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("LoginRequestCorrelationId", "ImplicitGen=Yes", "LAST"));

return 0;
}
# 9 "globals.h" 2

# 1 "CRM_Logout.c" 1
CRM_Logout()
{
	
	char path1[1024],path2[1024],path3[1024];
    	char separators[] = "\\"; 
   	char * token,* token1,* pch;
   	char word[] = "x2b";
   	char crmwrpctoken1[1024],crmwrpctoken2[1024],crmwrpctoken3[1024],crmwrpctoken4[1024];

	lr_think_time(3);
	
	 
# 87 "CRM_Logout.c"

	lr_save_string(lr_eval_string("{CorrelationParameter_2122}"), "path1");
	
	crmwrpctoken();

	 
# 164 "CRM_Logout.c"

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
		"LAST");

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
		"LAST");

	web_add_auto_header("Accept", 
		"text/html, application/xhtml+xml, */*");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate, peerdist");

	web_add_auto_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_auto_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

 





	web_reg_save_param_regexp(
		"ParamName=ESTSAUTHPERSISTENT",
		"RegExp=ESTSAUTHPERSISTENT=(.*?);",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Cookies",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=ESTSAUTH_1",
		"RegExp=ESTSAUTH=(.*?);",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Cookies",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/wsfed*",
		"LAST");

	web_url("main.aspx_3", 
		"URL=https://{param_URL}.crm6.dynamics.com/main.aspx?signout=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t204.inf", 
		"Mode=HTTP", 
		"LAST");

	web_add_auto_header("Accept", 
		"application/javascript, */*;q=0.8");

	web_url("jquery.1.11.min.js", 
		"URL=https://secure.aadcdn.microsoftonline-p.com/ests/2.1.7293.16/content/cdnbundles/jquery.1.11.min.js", 
		"Resource=1", 
		"RecContentType=application/x-javascript", 
		"Referer=https://login.microsoftonline.com/c0e0601f-0fac-449c-9c88-a104c4eb9f28/wsfed?wa=wsignout1.0&wreply=https%3a%2f%2f{param_URL}.crm6.dynamics.com%2f", 
		"Snapshot=t205.inf", 
		"LAST");

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
		"LAST");

	lr_end_transaction("CRM_01_d_SignOut",2);

	lr_think_time(3);

return 0;
}
# 10 "globals.h" 2

# 1 "crmwrpctoken.h" 1
crmwrpctoken()
{
	
	
		char path1[1024],path2[1024],path3[1024];
    	char separators[] = "\\"; 
   		char * token,* token1,* pch;
   		char word[] = "x2b";		
		char crmwrpctoken1[1024]="",crmwrpctoken2[1024]="",crmwrpctoken3[1024]="";
	 
	lr_output_message ("path is %s", lr_eval_string("{path1}"));
	lr_save_string("\\", "separators");
	 
   	 
   	token = (char *)strtok(lr_eval_string("{path1}"), lr_eval_string("{separators}"));
   
    lr_output_message ("token is %s", token);
    
    strcat(crmwrpctoken1,token);
    	  
    lr_output_message ("fullpath is %s",crmwrpctoken1);
    
    if (!token) 
	    {
	        
	    	lr_save_string("token", "crmwrpctoken1");
	        lr_output_message ("No tokens found in string!");
	        lr_output_message ("Full path of file is %s",crmwrpctoken1);
	         
	    }
	
    else{
			     
			    do      
				    {    	    
						lr_output_message ("Full path of file is %s", crmwrpctoken1);			
				        lr_output_message ("%s", token );
				       
				        token = (char *)strtok(0, separators);
				        lr_output_message ("%s", token );
				        if(token != 0)
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
										        



								    	    
				}while (token != 0 );
			    
    	}

    lr_output_message ("Full path of file is %s", crmwrpctoken1);
   	 	
	lr_save_string(crmwrpctoken1, "path1");
	
	return 0;
}
# 11 "globals.h" 2

# 1 "crmwrpctokencase.h" 1
crmwrpctokencase()
{
	
	char path1[1024],path2[1024],path3[1024];
    	char separators[] = "\\"; 
   	char * token,* token1,* pch;
   	char word[] = "x2b";		
	char crmwrpctoken1[1024]="",crmwrpctoken2[1024]="",crmwrpctoken3[1024]="";
	

	 
	lr_output_message ("path is %s", lr_eval_string("{path2}"));
	lr_save_string("\\", "separators");
	
	 
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
		 
		    do      
			{    	    
  	    			lr_output_message ("Full path of file is %s", crmwrpctoken2);			
			        lr_output_message ("%s", token );

			         
				token = (char *)strtok(0, separators);
				lr_output_message ("%s", token );
				
				if(token != 0)
				    {
				       	lr_output_message ("%s", token );
					strcat(crmwrpctoken2, token);
					lr_output_message ("Full path of file is %s", crmwrpctoken2);
				    }
			}while (token != 0 );
	   }
	
    	lr_output_message ("Full path of file is %s", crmwrpctoken2);
   	 	
	lr_save_string(crmwrpctoken2, "path2");

	return 0;
}
# 12 "globals.h" 2


 
 

		
		char path1[1024],path2[1024],path3[1024],path4[1024],path5[1024];
    	char separators[] = "\\"; 
   		char * token,* token1,* pch;
   		char word[] = "x2b";
   		char crmwrpctoken1[1024],crmwrpctoken2[1024],crmwrpctoken3[1024],crmwrpctoken4[1024];


# 3 "c:\\users\\ssen3107\\appdata\\local\\temp\\c221tysz.tjj\\\\combined_CRM_06_CreateCase.c" 2

# 1 "vuser_init.c" 1
vuser_init()
{

	 
	
	 
	
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

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_24",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"RequestUrl=*/homepage.aspx*",
		"LAST");

	lr_start_transaction("CRM_06_CreateCase_02_ClickCase");

	web_url("homepage.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/_root/homepage.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&etc=112&pagemode=iframe&sitemappath=area_service%7cPeople%7cNewSubArea_b823cecf&viewid=%7b00000000-0000-0000-00AA-000010001032%7d", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		"LAST");

	lr_end_transaction("CRM_06_CreateCase_02_ClickCase",2);

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
		"LAST");

	(web_remove_auto_header("X-P2P-PeerDist", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("X-P2P-PeerDistEx", "ImplicitGen=Yes", "LAST"));

	web_add_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_26",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"RequestUrl=*/Data.aspx*",
		"LAST");

 
	web_reg_save_param_json(
		"ParamName=process",
		"QueryString=$.formData._processControlDataKey._processId",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/Data.aspx*",
		"LAST");

 
	web_reg_save_param_json(
		"ParamName=formid_1",
		"QueryString=$.formData._formId",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/Data.aspx*",
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_36",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"RequestUrl=*/Data.aspx*",
		"LAST");

 
	web_reg_save_param_json(
		"ParamName=CorrelationParameter_53",
		"QueryString=$.tokenData[9].Timestamp",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/Data.aspx*",
		"LAST");
	
	web_reg_save_param(
		"CorrelationParameter_2129",
		"LB/IC=\"Token\":\"",
		"RB/IC=\",\"Url\":\"\\/APPWEBSERVICES\\/INLINEEDITWEBSERVICE.ASMX\"",
		 
		 
		"LAST");
		
	web_reg_save_param(
		"CorrelationParameter_2128",
		"LB/IC=\"Token\":\"",
		"RB/IC=\",\"Url\":\"\\/APPWEBSERVICES\\/APPGRIDWEBSERVICE.ASHX\"",
		 
		 
		"LAST");

	web_url("Data.aspx", 
		"URL=https://{param_URL}.crm6.dynamics.com/form/Data.aspx?_CreateFromId=&_CreateFromType=&appid=ab18c93f-61e6-e711-a848-000d3ad117e3&counter=1522024938097&etc=112&extraqs=%3fetc%3d112%26process%3d&formid=46831689-423c-4c43-9b9d-50425db20926&oid=&pagemode=iframe&pagetype=entityrecord&process=", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", 
		"Snapshot=t316.inf", 
		"LAST");

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

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_27",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"LAST");

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
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_28",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"LAST");

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
		"LAST");

	(web_remove_auto_header("Cache-Control", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("LoginRequestCorrelationId", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("ReferrerReqId", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("SOAPAction", "ImplicitGen=Yes", "LAST"));

	 
# 263 "vuser_init.c"

	 
# 440 "vuser_init.c"

	web_add_auto_header("Accept","text/html, */*; q=0.01");

	web_url("notesv2template.aspx",
		"URL=https://{param_URL}.crm6.dynamics.com/_controls/notes/notesv2template.aspx?lcid=1033&ver=-2068631631",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t37.inf",
		"Mode=HTML",
		"LAST");

	web_url("ActivitiesWallContent.aspx",
		"URL=https://{param_URL}.crm6.dynamics.com/_static/WallControl/ActivitiesWallContent.aspx?ver=-2068631631",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t38.inf",
		"Mode=HTML",
		"LAST");

	web_url("WallContent.1033.htm",
		"URL=https://{param_URL}.crm6.dynamics.com/%7B636567693290000510%7D/WebResources/msdyn_/WallContent.1033.htm?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=-2068631631",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t39.inf",
		"Mode=HTML",
		"LAST");

	web_url("FirstRunContent.1033.htm",
		"URL=https://{param_URL}.crm6.dynamics.com/%7B636567693290000510%7D/WebResources/msdyn_/FirstRunContent.1033.htm?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=-2068631631",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=-2068631631",
		"Snapshot=t40.inf",
		"Mode=HTML",
		"LAST");

	(web_remove_auto_header("X-Requested-With", "ImplicitGen=Yes", "LAST"));

	web_add_auto_header("Accept", 
		"*/*");

	web_add_header("FormLoadId", 
		"{61832369-0ee9-1055-a44b-5695cb830697}");

	web_add_header("x-crm-original", 
		"null");

 
	web_reg_save_param_regexp(
		"ParamName=formid",
		"RegExp=:\\[\\\\\"(.*?)\\\\\",",
		"Ordinal=5",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=No",
		"LAST");
 

	web_url("layout.aspx",
		"URL=https://{param_URL}.crm6.dynamics.com/_forms/read/layout.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&etc=112&formid=&formts=1525827372045&hash=1525827372045&highcontrast=false&isPreview=False&isTurboForm=true&process=&processts=0",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038",
		"Snapshot=t11.inf",
		"Mode=HTTP",
		"EXTRARES",
		"URL=/_imgs/formsections_navigationflyout_button.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_imgs/search_normal.gif", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_imgs/imagestrips/transparent_spacer.gif", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_imgs/AdvFind/progress.gif", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"LAST");

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
		"EXTRARES",
		"URL=../_imgs/formsections_navigationflyout_button.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=../_imgs/inlineedit/alert.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/cc_shared/knockout/3.2.0/libs/knockout.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=../_imgs/imagestrips/formentityimages.png?ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=../_imgs/imagestrips/inlineedit_images.png?ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=../_imgs/imagestrips/process_control_images.png?ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=../_imgs/imagestrips/entity_imgs.png?ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=../_imgs/theme/Outlook15White/FormFooterGradient.png?ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=../_imgs/dropdown_refresh.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/cc_shared/sol/2.0.0/libs/sol.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/cc_shared/mscommon/1.2.2/libs/mscommon.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=../_static/cs/cases/cases.js?ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=../_static/_common/scripts/formevt.js?ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/Service/Incident/Incident_main_system_library.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=../%7b636609085240000054%7d/webresources/crm/clientutility.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=../%7b636609085240000054%7d/webresources/service/localization/script/resourcestringprovider.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=../%7b636609085240000054%7d/webresources/crm/localization/resourcestringprovider.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/msdyn_/Utils/head.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/msdyn_/Case/Case.Library.js?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/dhhs_case?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/dhhs_telemetry?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/cc_shared/wijmo/5.20173.403/libs/wijmo/wijmo.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"LAST");

	  
# 578 "vuser_init.c"

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
		"EXTRARES",
		"URL=/_imgs/formsections_navigationflyout_button.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_imgs/search_normal.gif", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_imgs/imagestrips/transparent_spacer.gif", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_imgs/AdvFind/progress.gif", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_imgs/processcontrol/processcontrolarrows.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_imgs/processcontrol/process_control_global_active_flag.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_imgs/processcontrol/10_stage_scroll_arrow_left.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_imgs/processcontrol/10_stage_scroll_arrow_right.png", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/%7B636609085240000054%7D/WebResources/cc_shared/wijmoInput/5.20173.403/libs/wijmo/wijmoInput.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/%7B636609085240000054%7D/WebResources/cc_shared/wijmoGrid/5.20173.403/libs/wijmo/wijmoGrid.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=../formscript.js.aspx?airenabled=true&businessrulesversion=%7b636609084220000061%7d1033&formid=2286cef5-5237-4a7f-9023-41ad0af2b9b6&formname=crmform&fver=874927165&ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=Form&etn=incident&hierarchy=2286cef5-5237-4a7f-9023-41ad0af2b9b6&id=Mscrm.CommandBar&ie=1&isTurboForm=True&ise=1&lcid=1033&mver={tstamp}&oc=0&page=&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=activitypointer&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cactivitypointer%7cOneToMany%7cIncident_ActivityPointers&ie=1&ise=1&lcid=1033&mver={tstamp}&oc=0&page=%2f_FORMS%2fREAD%2fLAYOUT.ASPX&relName=Incident_ActivityPointers&relType=OneToMany&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=connection&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cconnection%7cOneToMany%7ccontact_connections1&ie=1&ise=1&lcid=1033&mver={tstamp}&oc=0&page=%2f_FORMS%2fREAD%2fLAYOUT.ASPX&relName=contact_connections1&relType=OneToMany&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=connection&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cconnection%7cOneToMany%7cincident_connections1&ie=1&ise=1&lcid=1033&mver={tstamp}&oc=0&page=%2f_FORMS%2fREAD%2fLAYOUT.ASPX&relName=incident_connections1&relType=OneToMany&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=incident&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cincident%7cOneToMany%7cdhhs_casegroup_incident_Casegroupsid&ie=1&ise=1&lcid=1033&mver={tstamp}&oc=0&page=%2f_FORMS%2fREAD%2fLAYOUT.ASPX&relName=dhhs_casegroup_incident_Casegroupsid&relType=OneToMany&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=dhhs_caseactivity&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cdhhs_caseactivity%7cOneToMany%7cdhhs_incident_dhhs_caseactivity_CaseId&ie=1&ise=1&lcid=1033&mver={tstamp}&oc=0&page=%2f_FORMS%2fREAD%2fLAYOUT.ASPX&relName=dhhs_incident_dhhs_caseactivity_CaseId&relType=OneToMany&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=dhhs_screeningpersons&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cdhhs_screeningpersons%7cManyToMany%7cdhhs_incident_dhhs_screeningpersons_L17&ie=1&ise=1&lcid=1033&mver={tstamp}&oc=0&page=%2f_FORMS%2fREAD%2fLAYOUT.ASPX&relName=dhhs_incident_dhhs_screeningpersons_L17&relType=ManyToMany&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=dhhs_alert&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cdhhs_alert%7cOneToMany%7cdhhs_contact_dhhs_alert_PersonorClient&ie=1&ise=1&lcid=1033&mver={tstamp}&oc=0&page=%2f_FORMS%2fREAD%2fLAYOUT.ASPX&relName=dhhs_contact_dhhs_alert_PersonorClient&relType=OneToMany&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/_controls/ribbon/RibbonLayout.js.aspx?cb=true&econtext=SubGridStandard&etn=incident&hierarchy=00000000-0000-0000-0000-000000000000&id=SubGridStandard%7cincident%7cNoRelationship%7c&ie=1&ise=1&lcid=1033&mver={tstamp}&oc=0&page=%2f_FORMS%2fREAD%2fLAYOUT.ASPX&relName=&relType=NoRelationship&rver=-1678346133&ver=385312038&wrdepver=00000000000000000000000000000000", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/%7B636609085240000054%7D/WebResources/cc_shared/wijmoGridFilter/5.20173.403/libs/wijmo/wijmoGridFilter.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=/%7B636609085240000054%7D/WebResources/msdyn_/Utils/jquery1.4.1.min.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=/%7B636609085240000054%7D/WebResources/msdyn_/SDK/SOAP/Sdk_Soap_min.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=/_imgs/inlineedit/save.png?ver=385312038", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"LAST");

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
		"LAST");

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
		"EXTRARES",
		"URL=../%7B636609085240000054%7D/WebResources/msdyn_/Action/FieldServiceSystemAction/Sdk_msdyn_FieldServiceSystemAction_min.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/msdyn_/Utils/CrudSDK.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/msdyn_/Utils/sdk.jquery.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/msdyn_/Utils/FieldOneSkyUtils.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/msdyn_/Utils/EntityDictionary.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/msdyn_/LocalizationLibrary/Localization.Library.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/cc_shared/wijmoKnockout/5.20173.403/libs/wijmo/wijmoKnockout.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/cc_shared/wijmoGridDetail/5.20173.403/libs/wijmo/wijmoGridDetail.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/cc_shared/wijmoAccessibilityExtender/1.0.0/libs/wijmo/wijmoAccessibilityExtender.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/dhhs_screeningperson?appid=ab18c93f-61e6-e711-a848-000d3ad117e3", "Referer=https://{param_URL}.crm6.dynamics.com/form/ClientApiWrapper.aspx?ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/cc_shared/gridlib/1.9.17/libs/gridlib.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"URL=../%7B636609085240000054%7D/WebResources/cc_MscrmControls.Grid.GridControl/Grid.js", "Referer=https://{param_URL}.crm6.dynamics.com/form/page.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3&lcid=1033&themeId=6706240e-d78b-4278-814e-fdb8c89f220f&tstamp={tstamp}&updateTimeStamp={updateTimeStamp}&userts={userts}&ver=385312038", "ENDITEM",
		"LAST");

	lr_end_transaction("CRM_06_CreateCase_03_FirstTimeUserExperienceNewCase",2);

	(web_remove_auto_header("FormLoadId", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("ReferrerReqId", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("X-P2P-PeerDist", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("X-P2P-PeerDistEx", "ImplicitGen=Yes", "LAST"));

	lr_think_time(10);

	(web_remove_auto_header("Cache-Control", "ImplicitGen=Yes", "LAST"));
		

	return 0;
}
# 4 "c:\\users\\ssen3107\\appdata\\local\\temp\\c221tysz.tjj\\\\combined_CRM_06_CreateCase.c" 2

# 1 "CreateCase.c" 1
CreateCase()
{
	char crmwrpctoken5[1024]="",crmwrpctoken6[1024]="";
	int temp,ord,var1;
	
	var1 = 0;
	
	lr_save_datetime("%d%m%Y", var1 , "param_ClientDate");
	lr_think_time(5);

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_38",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"RequestUrl=*/LookupService.asmx*",
		"LAST");

 
	web_reg_save_param("ClientFN","LB/IC=\" oname=\"","RB/IC= ","Ord=All","NotFound=Warning","LAST");
	web_reg_save_param("ClientLN","LB/IC= ","RB/IC=\" otypename=\"contact\"","Ord=All","NotFound=Warning","LAST");
	web_reg_save_param("ClientOid","LB=oid=\"{","RB=}\" oname=\"","Ord=All","NotFound=Warning","LAST");
	
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
		"LAST");

	if(atoi(lr_eval_string("{ClientOid_count}")) == 0)
	{
	
	lr_end_transaction("CRM_06_CreateCase_04_EnterDetails1",1);
	
	lr_exit(5,1);
	
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

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_39",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"LAST");

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
		"LAST");

	(web_remove_auto_header("Cache-Control", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("FormLoadId", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("ReferrerReqId", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("SOAPAction", "ImplicitGen=Yes", "LAST"));

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_40",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"RequestUrl=*/PresenceService.asmx*",
		"LAST");

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
		"LAST");

	lr_save_string(lr_eval_string("{CorrelationParameter_2128}"), "path2");

	crmwrpctokencase();

	lr_save_string(lr_eval_string("{path2}"), "path3");

	 
# 195 "CreateCase.c"

	lr_save_string(lr_eval_string("{CorrelationParameter_2129}"), "path2");
		
	crmwrpctokencase();

	lr_save_string(lr_eval_string("{path2}"),"path4");

	 
# 250 "CreateCase.c"

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

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_41",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"RequestUrl=*/InlineEditWebService.asmx*",
		"LAST");

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
		"LAST");

	web_add_auto_header("CRMWRPCToken", 
		lr_eval_string("{path3}"));

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_42",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"LAST");

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
		"LAST");

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_43",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"LAST");

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
		"LAST");

	web_add_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/Execute");

	(web_remove_auto_header("CRMWRPCToken", "ImplicitGen=Yes", "LAST"));

	web_add_header("CRMWRPCToken", 
		lr_eval_string("{path4}"));

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_44",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"LAST");

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
		"LAST");

	lr_end_transaction("CRM_06_CreateCase_04_EnterDetails1",2);

	lr_think_time(5);

	(web_remove_auto_header("CRMWRPCTokenTimeStamp", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("Cache-Control", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("FormLoadId", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("ReferrerReqId", "ImplicitGen=Yes", "LAST"));

	web_add_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/RetrieveInlineSearchResults");

	web_add_auto_header("Cache-Control", 
		"no-cache");

	web_add_auto_header("FormLoadId", 
		"{90e54e86-12d1-3a6b-32ae-82426864576d}");

	web_add_auto_header("ReferrerReqId",
		"{CorrelationParameter_36}");

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_45",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"RequestUrl=*/LookupService.asmx*",
		"LAST");

	 
	web_reg_save_param("GroupOid","LB=oid=\"{","RB=}\" oname=\"","LAST");

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
		"LAST");

	web_add_header("CRMWRPCToken", 
		lr_eval_string("{path4}"));

	web_add_auto_header("CRMWRPCTokenTimeStamp",
		"{CorrelationParameter_53}");

	web_add_header("SOAPAction", 
		"http://schemas.microsoft.com/crm/2009/WebServices/Execute");

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_46",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"LAST");

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
		"LAST");

	web_add_header("CRMWRPCToken", 
		lr_eval_string("{path3}"));

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_47",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"LAST");

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
		"LAST");

	lr_end_transaction("CRM_06_CreateCase_05_EnterDetails2",2);

	lr_think_time(5);

	(web_remove_auto_header("CRMWRPCTokenTimeStamp", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("FormLoadId", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("ReferrerReqId", "ImplicitGen=Yes", "LAST"));

 
# 603 "CreateCase.c"

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
	
	web_reg_save_param("oId","LB/IC=\"_entity\":{\"Id\":\"{","RB/IC=}\",","LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

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
		"LAST");

	(web_remove_auto_header("CRMWRPCToken", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("CRMWRPCTokenTimeStamp", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("Cache-Control", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("ReferrerReqId", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("FormLoadId", "ImplicitGen=Yes", "LAST"));

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
		"LAST");

	(web_remove_auto_header("Cache-Control", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("ReferrerReqId", "ImplicitGen=Yes", "LAST"));

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
		"LAST");

	web_add_auto_header("Accept", 
		"application/xml, text/xml, */*; q=0.01");

	(web_remove_auto_header("FormLoadId", "ImplicitGen=Yes", "LAST"));

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
		"LAST");

	web_add_auto_header("Accept", 
		"*/*");

	(web_remove_auto_header("Cache-Control", "ImplicitGen=Yes", "LAST"));

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
		"LAST");

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
		"LAST");

	web_add_auto_header("Accept", 
		"*/*");

	(web_remove_auto_header("Cache-Control", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("FormLoadId", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("ReferrerReqId", "ImplicitGen=Yes", "LAST"));

	web_add_header("CRMWRPCToken", 
		lr_eval_string("{path3}"));

	web_add_header("CRMWRPCTokenTimeStamp",
		"{CorrelationParameter_53}");

	 

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
		"LAST");

	 

	lr_end_transaction("CRM_06_CreateCase_06_SaveCase",2);

	lr_think_time(5);

	 
	
	return 0;
}
# 5 "c:\\users\\ssen3107\\appdata\\local\\temp\\c221tysz.tjj\\\\combined_CRM_06_CreateCase.c" 2

# 1 "NewCase.c" 1
NewCase()
{

	
	web_add_header("LoginRequestCorrelationId",
		"462d2695-18e7-484b-83e9-3af296a53985");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=2.0");

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_36",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"RequestUrl=*/Data.aspx*",
		"LAST");

 
	web_reg_save_param_json(
		"ParamName=CorrelationParameter_53",
		"QueryString=$.tokenData[9].Timestamp",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/Data.aspx*",
		"LAST");
	
	web_reg_save_param(
		"CorrelationParameter_2129",
		"LB/IC=\"Token\":\"",
		"RB/IC=\",\"Url\":\"\\/APPWEBSERVICES\\/INLINEEDITWEBSERVICE.ASMX\"",
		 
		 
		"LAST");
		
	web_reg_save_param(
		"CorrelationParameter_2128",
		"LB/IC=\"Token\":\"",
		"RB/IC=\",\"Url\":\"\\/APPWEBSERVICES\\/APPGRIDWEBSERVICE.ASHX\"",
		 
		 
		"LAST");
	
	lr_think_time(5);

	lr_start_transaction("CRM_06_CreateCase_03_NewCaseMulti");

	web_url("Data.aspx_2",
		"URL=https://{param_URL}.crm6.dynamics.com/form/Data.aspx?_CreateFromId=&_CreateFromType=&appid=ab18c93f-61e6-e711-a848-000d3ad117e3&counter=1522024942876&etc=112&extraqs=%3fetc%3d112%26formid%3d{formid}%26process%3d&formid={formid}&oid=&pagemode=iframe&pagetype=entityrecord&process=",
		"Resource=1",
		"RecContentType=application/json",
		"Referer=https://{param_URL}.crm6.dynamics.com/main.aspx?appid=ab18c93f-61e6-e711-a848-000d3ad117e3",
		"Snapshot=t423.inf",
		"LAST");

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

 





	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_37",
		"RegExp=REQ_ID:\\ (.*?)\\\r\\\n",
		"Ordinal=1",
		"SEARCH_FILTERS",
		"Scope=Headers",
		"RequestUrl=*/LookupService.asmx*",
		"LAST");

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
		"LAST");

	lr_end_transaction("CRM_06_CreateCase_03_NewCaseMulti",2);

	return 0;
}
# 6 "c:\\users\\ssen3107\\appdata\\local\\temp\\c221tysz.tjj\\\\combined_CRM_06_CreateCase.c" 2

# 1 "vuser_end.c" 1
vuser_end()
{

	lr_think_time(3);
	
	CRM_Logout();

	return 0;
}
# 7 "c:\\users\\ssen3107\\appdata\\local\\temp\\c221tysz.tjj\\\\combined_CRM_06_CreateCase.c" 2


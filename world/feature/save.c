// save.c

int save()
{
	string file;

/*
    if ( userp(this_object()) )
  {
          if ( this_object()->query("mud_age") < 1800 && !wizardp( this_object() )  )
                 {
             write("本站不保存新建id档案，在线半小时以上才保存，如有不便，请见谅。\n");
                          return 1 ;
                             }
  }
  */
	if( stringp(file = this_object()->query_save_file()) ) {
		assure_file(file+ __SAVE_EXTENSION__);
		return save_object(file);
	}
	return 0;
}

int restore()
{
	string file;

	if( stringp(file = this_object()->query_save_file()) )
		return restore_object(file);
	return 0;
}

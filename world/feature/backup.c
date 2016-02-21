// backup.c

int backup()
{
	string file;

	if( stringp(file = this_object()->query_save_file()) ) {
		file = file + ".oo";
		assure_file(file+ __SAVE_EXTENSION__);
		return save_object(file);
	}
	return 0;
}

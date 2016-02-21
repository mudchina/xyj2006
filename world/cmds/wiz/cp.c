// cp.c
// creator:     Fan@falling-sun.chinesemud.net
// creat time:  1999/04/05

inherit F_CLEAN_UP;
 
protected string get_path(string str);
protected string get_file(string str);
protected int cp_file(string from, string to, int rflag, int iflag, int silent);
int help(object ob);

int directory_exists(string dirname)
{
    return (file_size(dirname) == -2);
}
int file_exists(string filename)
{
	return (file_size(filename) > -1 );
}


varargs string extract( string str, int from, int to )
{
    if( !stringp( str ) ) return ""; // syntax error
    if( nullp( from ) ) return str;
    if( nullp( to ) ) to = strlen( str );
    return str[from..to];
}

//
 
int main(object me, string arg)
{
 mixed *files;
   string str,flags, tpath, fpath, from, to, tmp1, tmp2;
   int loop, rflag, iflag, silent;

   if (me!=this_player(1))	return 0;
   seteuid( getuid(me) );
 
   if(!arg || arg == "")  return help(me);
 
   if(sscanf(arg, "-%s %s", flags, str) == 2
   || sscanf(arg, "%s -%s", str, flags) == 2) {
        if(sscanf(" " + flags + " ", "%sr%s", tmp1, tmp2) == 2)  rflag = 1;
        if(sscanf(" " + flags + " ", "%si%s", tmp1, tmp2) == 2)  iflag = 1;
        if(sscanf(" " + flags + " ", "%sf%s", tmp1, tmp2) == 2)  iflag = 0;
        if(sscanf(" " + flags + " ", "%ss%s", tmp1, tmp2) == 2)  silent = 1;
   }else str=arg;
 
   if(sscanf(str, "%s to %s", from, to) != 2 &&
      sscanf(str, "%s %s", from, to) !=2)         return help(me);
 

   if(to == ".")  to = (string)this_player()->query("cwd");
 
   from = resolve_path(me->query("cwd"), from);
   to   = resolve_path(me->query("cwd"), to);

   if(directory_exists(from))
      if(from[strlen(from)-1] == '/')  from += "*";
      else from += "/*";

   fpath = get_path(from);
   tpath = get_path(to);

   //   Check for existence of source and dest directories
   if(!directory_exists(fpath)) {
        write("Cp: 没有这个目录 : " + fpath + "\n");
        return 1; 
    }
 
   if(!directory_exists(tpath)) {
        write("Cp: 没有这个目录 : " + tpath + "\n");
        return 1; 
   }

   if((int)master()->valid_read(fpath, me, "cp") == 0) {
       printf("Cp: 权限不允许读%s.\n",
          (fpath == "" ? "根目录" : fpath));
       return 1; }
 
   if((int)master()->valid_write(tpath, me, "cp") == 0) {
        printf("Cp: 权限不允许写%s.\n",
          (tpath == "" ? "根目录" : tpath));
        return 1; 
   }

   //   Process request for wildcard entry

   files = get_dir(from);
   files -= ({ "." });
   files -= ({ ".." });
 
   //   Check to see if any files match the pattern

   if(!files || !sizeof(files)) {
        write("Cp:  没有这样的用法 : " + from + "\n");
        return 1;
   }
 
   //   如果复制多个文件，则把"to"视为一个目标目录
 
   if(sizeof(files) > 1) {

       if(tpath != "")   tpath = to + "/";

        if(!directory_exists(tpath)) {
          if (!rflag){
            write("Cp: 没有这个目录 : " + tpath + "\n");
            return 1; 
         }else mkdir(tpath);
        }

       if(tpath == fpath) {
           write("Cp: 这不是白折腾吗？\n");
           return 1; 
       }
   }
 
   if(sscanf(tpath, fpath + "%s", tmp1) == 1 && tmp1 != "" && rflag) {
       write("Cp: 不能递归复制。\n");
       return 1; 
   }
 
   //  If only one file selected ...

   if(sizeof(files) == 1) {
 
        if(!file_exists(fpath + files[0]) &&
           !directory_exists(fpath + files[0])) {
        write("Cp: " + fpath + files[0] + " 文件不存在.\n");
        return 1; }
 
        if(directory_exists(to)) 
          to += (tpath == "" ? "" : "/") + get_file(files[0]);
 
        cp_file(fpath + files[0], to, rflag, iflag, 0);
 
        this_player()->set("cwf", to);
 
   return 1; }

   //  Otherwise loop through the multiple file choices
 
   for(loop=0; loop<sizeof(files); loop++) 
     cp_file(fpath + files[loop], tpath + files[loop], rflag, iflag, silent);
 
   if(silent)  write("Cp: 文件复制完成。\n");
 
return 1; }
 
protected int cp_file(string from, string to, int rflag, int iflag, int silent) {
 mixed *tmp;
   int loop;
 
   //  Block if source and destination are equivalent
 
   if(from == to) {
   write("Cp: 白折腾...\n");
   return 1; }

  //   Check to see if source file/dir does exist
  //   Shouldn't need this ... but just in case. :)

   if(file_size(from) == -1) {
   write("Cp: " + from + " 文件不存在.\n");
   return 1; }
 
   //  If source file request is a directory
 
   if(directory_exists(from)) {
 
        from += "/";  to += "/";

        if(rflag) {
        tmp = get_dir(from);
 
        if(!directory_exists(to))   
           mkdir( to[0..strlen(to)-2] );        // Strip tailing '/'
 
        for(loop=0; loop<sizeof(tmp); loop++)
           cp_file(from + tmp[loop], to + tmp[loop], rflag, iflag, silent);
        }
 
        else {
        if(!silent)  write("不能复制: " + from + " 是一个目录。\n");
        return 1; }
 
        rmdir( from[0..strlen(from)-2] );

        if(!silent)
        write("复制目录结构: " + from + " --> " + to + "\n");
        return 1; }

   //  If to file already exists and the iflag is set ... block copy
 
   if(iflag && file_exists(to)) {
   if(!silent) write("目标文件: " + to + " 已经存在。\n");
   return 1; }
 
   //  Attempt to copy the file to new location
    if (cp(from,to))
        if(!silent)  write("" + from + " ---> " + to + "...ok.\n");
    else
        if(!silent)  write("" + from + " ---> " + to + "失败！\n");
        
	return 1; 
}
 

//  返回文件所在的目录

protected string get_path(string str)
{
    mixed *tmp;
    string path;

    if(str == "/")       return "";

    if(str[strlen(str)-1] == '/')   return str;
    else if(directory_exists(str))  return str+"/";
 
    tmp = explode(str, "/") - ({ 0 });
    if (sizeof(tmp)>=2)
        path = "/" + implode( tmp[0..sizeof(tmp)-2], "/")+"/";
    else
        path="";
    if(path == "//")  path = "";
 
    return path; 
}
 
//  This function returns the filename without the whole file path

protected string get_file(string str) {
   mixed *tmp;

   tmp = explode(str, "/");

    return tmp[sizeof(tmp)-1]; 
}
  
int help(object me)
{
  write(@HELP
指令格式: cp [-rsfi] <源文件> <目标文件>
 
    此指令可以复制文件。
    
    
    这个指令允许使用通配符*和?复制更多的文件，可以使用以下参数：
    
    -r : 复制包括子目录的文件。并以覆盖的形式改写已经存在的目标文件。
    -i : 避免使用覆盖方式改写目标文件。
    -f : 强制使用覆盖方式改写已经存在的文件。
    -s : 使用寂静方式复制文件。
    

HELP
    );
    return 1;
}
 

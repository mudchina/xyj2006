//Cracked by Roath
void init() {
    add_action("do_get","get");
//    add_action("do_drop","drop");
}
int do_get(string arg) {
  object whom;

  string from;
  if (!arg) return 0;
 if( sscanf(arg, "%s from %s", arg, from)==2 ) {
   write("不许在这里拿人东西！\n");
  return 1;
  }
  if (!whom=present(arg,this_object())) return 0;
  if (userp(whom)  &&  (!living(whom)))  {
    write(whom->name()+"对你而言太重了。\n");
    return 1;
  }
  return 0;
}
int do_drop() {
  write("爱护环境，人人有责，别乱扔垃圾。\n");
  return 1;
}

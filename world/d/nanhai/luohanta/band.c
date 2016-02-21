// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

// #include <net/telnet.h>

#define BANNED_SITES "/adm/etc/banned_sites"
#define CHAR_BANNED_SITES "/adm/etc/char_banned_sites"
#define STRICT_BANNED_SITES "/adm/etc/strict_banned_sites"

int check_ip(string my_ip);
void load_sites();
void load_sites2();
void load_sites3(); //strictly banned.
void add(string pattern);
void add2(string pattern);
void add3(string pattern); //strictly banned.
void remove(string pattern);
void remove2(string pattern);
void remove3(string pattern); //strictly banned.
int  is_banned(string site);
int  create_char_banned(string site);
int  is_strict_banned(string site);
void print();
void print2();
void print3(); 

string *Sites;
string *Sites2;
string *Sites3;

void create()
{
   seteuid(getuid());
   load_sites();
   load_sites2();
   load_sites3();
}

void load_sites()
{
   string *tmp, file;
   int loop;

   Sites = ({});
   
   // reads in the list of the banned sites

   file = read_file(BANNED_SITES);
   if (!file) return;
   
   tmp = explode(file, "\n");
      for(loop=0; loop<sizeof(tmp); loop++)
           if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                continue;
           else Sites += ({ tmp[loop] });
}

void load_sites2()
{
   string *tmp, file;
   int loop;

   Sites2 = ({});
   
   // reads in the list of the banned sites

   file = read_file(CHAR_BANNED_SITES);
   if (!file) return;
   
   tmp = explode(file, "\n");
      for(loop=0; loop<sizeof(tmp); loop++)
           if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                continue;
           else Sites2 += ({ tmp[loop] });
}

void load_sites3()
{
        string *tmp, file;
        int loop;

        Sites3 = ({});

        // reads in the list of the banned sites

        file = read_file(STRICT_BANNED_SITES);
        if (!file) return;

        tmp = explode(file, "\n");
        for(loop=0; loop<sizeof(tmp); loop++)
                if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                        continue;
                else Sites3 += ({ tmp[loop] });
}


int is_banned(string site)
{
   string *line;
   int i;

   line = ({});
   line += ({site});

   for (i = 0; i < sizeof(Sites); i++)
     if (sizeof(regexp(line, Sites[i])) == 1)
        return 1;
   return 0;
}   

int create_char_banned(string site)
{
   string *line;
   int i;

   line = ({});
   line += ({site});

   for (i = 0; i < sizeof(Sites2); i++)
     if (sizeof(regexp(line, Sites2[i])) == 1)
        return 1;
   return 0;
}   

int is_strict_banned(string site)
{
        string *line;
        int i;

        line = ({});
        line += ({site});

        for (i = 0; i < sizeof(Sites3); i++)
                if (sizeof(regexp(line, Sites3[i])) == 1)
                        return 1;
        return 0;
}


void print()
{
   int i;
   for (i = 0; i < sizeof(Sites); i++)
     write(Sites[i] + "\n");
}

void print2()
{
   int i;
   for (i = 0; i < sizeof(Sites2); i++)
     write(Sites2[i] + "\n");
}

void print3()
{
        int i;
        for (i = 0; i < sizeof(Sites3); i++)
                write(Sites3[i] + "\n");
}

void add(string site)
{
   int i;
   
   Sites += ({site});
   write_file(BANNED_SITES, Sites[sizeof(Sites)-1] + "\n", 0);
}

void add2(string site)
{
   int i;
   
   Sites2 += ({site});
   write_file(CHAR_BANNED_SITES, Sites2[sizeof(Sites2)-1] + "\n", 0);
}

void add3(string site)
{
        int i;

        Sites3 += ({site});
        write_file(STRICT_BANNED_SITES, Sites3[sizeof(Sites3)-1] + "\n", 0);
}


void remove(string site)
{
   write("请修改 " + BANNED_SITES + " 解禁。\n");
}

void remove2(string site)
{
   write("请修改 " + CHAR_BANNED_SITES + " 解禁。\n");
}

void remove3(string site)
{
        write("请修改 " + STRICT_BANNED_SITES + " 解禁。\n");
}

//by mon 9/22/97
//can only run on these machines.
int check_ip(string my_ip)
{
   if(!my_ip || strlen(my_ip)<2) return 0;

   if(my_ip=="209.83.132.67") return 1; //main site
   if(my_ip=="202.96.132.48") return 1; //zh mirror
   if(my_ip=="202.118.66.15") return 1;  //dl mirror
   if(my_ip=="202.118.66.5") return 1;  //dl mirror
   if(my_ip=="168.160.225.39") return 1; //bj mirror
   if(my_ip=="210.32.134.188") return 1;  //zheda mirror
   if(my_ip=="202.96.102.6") return 1;  //hz mirror
   if(my_ip=="10.103.32.2") return 1;  //hz mirror
   if(my_ip=="202.101.106.246") return 1;  //xiamen mirror
   if(my_ip=="202.118.226.88") return 1;  //haerbin mirror
   if(my_ip=="130.126.160.111") return 1;  //test mirror

//   if(my_ip=="") return 1;

   return 0;
}


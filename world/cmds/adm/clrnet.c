//file          : clrnet.c
//purpose       : dest所有断线user的程序，慎用
//created       : 02-1-12 22:09
//by            : Canoe@DHXY-Online

//history       : 02-1-12 22:09 Canoe 创建文件
 
int main ( )
{
        int i , j , iMax ; 
        string cName ;
        object * oList = livings();
        seteuid(ROOT_UID);
        
        j = 0 ;
        iMax = sizeof(oList) ;
        for ( i = 0 ; i < iMax ; i++ )
        {
                if ( oList[i]->query_temp("netdead") )
              {
                     if ( time() - (int)oList[i]->query("birthday") < 3600 )
                     {
                                cName = oList[i]->query("id");
rm(DATA_DIR + "login/" + cName[0..0] + "/" + cName + __SAVE_EXTENSION__);
rm(DATA_DIR + "user/" + cName[0..0] + "/" + cName + __SAVE_EXTENSION__);
                                destruct( oList[i] ); 
                     } 
                   else 
                   {
                      if ( oList[i]->save() )
                                destruct( oList[i] ); 
                            else
                             log_file ( "save" , sprintf("%s存档出错。\n",oList[i]->query("id") ) ) ;
                         }
                        j++ ;
                }
        }
        write ( sprintf("清理完毕，共清理%d个断线id。\n",j) ) ;
        return 1 ;
}


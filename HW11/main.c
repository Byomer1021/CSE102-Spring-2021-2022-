#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define FILENAME "Final_database.bin"
typedef struct table {
    char *table_name;
    char **field;
    char **type;
    bool **isNull;
    bool *isKey;
    struct table *next;
} table;

typedef struct tables {
   struct  tables *next; 
    table * t;
} tables;


typedef struct database {
    tables * tList; /* to be implemented as a linked list */
    int n; /* num of entries */
    char * name; /* table name */
    struct database *next;
} database;


database *change_database(database*source,database*data_changing);

void create_database(database *d,char *name);

void show_table(database *d);

void desc_table(database *d, table *t);

void insert_table(database *d, table *t); 

tables * remove_table(database *d, char *name);

database * remove_database(database *d, char *name);

void insert_key(database *d, table *t,bool key_value);

void edit_input(char *inp);

database *return_database(database *d,char *name);

bool control_database1(database *d,char *name);

bool control_database2(tables *d,int a);

bool control_tables(tables *d,char *name);

tables *return_TABLE(tables *d,char *name);

void fill_table(tables * tabble);

void fill_table_values(tables * tabble);

bool control_contunie(char *temp);

bool control_contunie1(char *temp);


void write_file(database *d);



int main()
{
    database *data_root;
    data_root=(database *)malloc(sizeof(database));
    data_root->n=1;
    data_root->next=NULL;
    data_root->tList=(tables *)malloc(sizeof(tables));
    data_root->tList->next=NULL;
    char *temp=NULL;
    int control=0;
    database *data_root_temp=data_root;
    //data_root_temp=takingFILE(data_root_temp);

    while(1)
    {
        printf("\n\n\n\t\tHySQL SYSTEMM\n"
                "1.Create Database System:\n"
                "2.Create a table for a Database system:\n"
                "3.Remove a Database system: \n"
                "4.Remove a Table:\n"
                "5.Write tables\n"
                "6.Fill a table for a Database system:\n"
                "7.Fill a table VALUES:\n"
                "8.Write FILE:\n"
                "9.EXIT\n\n\n");
        temp=(char *)calloc(100,sizeof(char));
        fgets(temp,100,stdin);
        edit_input(temp);
        if(strcmp(temp,"1")==0)
        {
            control++;
            free(temp);
            temp=(char *)calloc(100,sizeof(char));
            printf("For new creating Please write your database name: ");
            fgets(temp,100,stdin);
            edit_input(temp);
            data_root_temp=data_root;
            create_database(data_root_temp,temp);
            data_root_temp=data_root;
            }
        else if(strcmp(temp,"2")==0)
        {
            free(temp);
            temp=(char *)calloc(100,sizeof(char));
            char *temp2;
            temp2=(char *)calloc(100,sizeof(char));
            printf("Print your Database name for adding Table:\n");
            fgets(temp,100,stdin);
            edit_input(temp);
            strcpy(temp2,temp);
            if(control_database1(data_root_temp,temp))
            {
                free(temp);
                temp=(char *)calloc(100,sizeof(char));
                table *temp_Table=(table *)malloc(sizeof(table));
                temp_Table->table_name=(char *)calloc(strlen(temp)+1,sizeof(char));
                printf("Write your table name: ");
                fgets(temp,100,stdin);
                edit_input(temp);
                strcpy(temp_Table->table_name,temp);
                free(temp);
                data_root_temp=data_root;   
                insert_table(return_database(data_root_temp,temp2),temp_Table); 
                free(temp2);   
                data_root_temp=data_root;        
            }
            else
                printf("ERROR!!!\n Couldn't found database\n");
            
        }
        else if(strcmp(temp,"3")==0)
        {
            free(temp);
            temp=(char *)calloc(100,sizeof(char));
            printf("Print your Database removing:\n"); 
            fgets(temp,100,stdin);
            edit_input(temp);
            if(control_database1(data_root_temp,temp))
                remove_database(data_root_temp,temp);
            else
                printf("Database couldn 't found!!\n");

        }
        else if(strcmp(temp,"4")==0)
        {
            free(temp);
            temp=(char *)calloc(100,sizeof(char));
            printf("Write your database Name: ");
            fgets(temp,100,stdin);
            edit_input(temp);
            if(control_database1(data_root_temp,temp))
            {
                database *new_temp=return_database(data_root_temp,temp);
                new_temp->tList= remove_table(return_database(data_root_temp,temp),temp);
                data_root=change_database(data_root_temp,new_temp);
                data_root_temp=data_root;
            }
            else
                printf("Database couldn't found!!!\n");
        }
        else if(strcmp(temp,"5")==0)
        {
            data_root_temp=data_root;
            show_table(data_root_temp);
            data_root_temp=data_root;
        }
        else if(strcmp(temp,"6")==0)
        {
            free(temp);
            temp=(char *)calloc(100,sizeof(char));
            char *temp2;
            temp2=(char *)calloc(100,sizeof(char));
            printf("Write your database Name: ");
            fgets(temp,100,stdin);
            edit_input(temp);
            strcpy(temp2,temp);
            if(control_database1(data_root_temp,temp))
            {
                free(temp);
                temp=(char *)calloc(100,sizeof(char));
                printf("Write your Table Name: ");
                fgets(temp,100,stdin);
                edit_input(temp);
                if(control_tables(data_root_temp->tList,temp))
                {
                    printf("kontrol et\n");
                    fill_table(return_TABLE(return_database(data_root_temp,temp2)->tList,temp));
                    printf("kontrol et1\n");
                    desc_table(data_root_temp,return_TABLE(return_database(data_root_temp,temp2)->tList,temp)->t);
                }
                else
                    printf("Table couldn't found!!!\n"); 
            }
            else
                printf("Database couldn't found!!!\n"); 
        }
        else if(strcmp(temp,"7")==0)
        {
            free(temp);
            temp=(char *)calloc(100,sizeof(char));
            char *temp2;
            temp2=(char *)calloc(100,sizeof(char));
            printf("Write your database Name: ");
            fgets(temp,100,stdin);
            edit_input(temp);
            strcpy(temp2,temp);
            if(control_database1(data_root_temp,temp))
            {
                free(temp);
                temp=(char *)calloc(100,sizeof(char));
                printf("Write your Table Name: ");
                fgets(temp,100,stdin);
                edit_input(temp);
                if(control_tables(data_root_temp->tList,temp))
                {

                    fill_table_values(return_TABLE(return_database(data_root_temp,temp2)->tList,temp));
                    desc_table(data_root_temp,return_TABLE(return_database(data_root_temp,temp2)->tList,temp)->t);
                }
                else
                    printf("Table couldn't found!!!\n"); 
            }
            else
                printf("Database couldn't found!!!\n"); 
        }
        else if(strcmp(temp,"8")==0)
        {
            write_file(data_root_temp);
        }
        else if(strcmp(temp,"9")==0)
        {
            break;
        }
    }

    return 0;
}

void edit_input(char *inp)
{
    int i=0;
    while(inp[i]!=0)/*fgets() taking ınput with \n becausse of that ı change \n with \0 */
    {
        if(inp[i]==10)
            inp[i]=0;
    i++;
    }
}
void create_database(database *data_root,char *name)
{
    if(data_root->next==NULL)
    {
        database *temp=(database *)malloc(sizeof(database));
        temp->tList=(tables *)malloc(sizeof(tables));
        temp->tList->next=NULL;
        data_root->name=(char *)calloc(strlen(name)+1,sizeof(char));
        strcpy(data_root->name,name);
        temp->n=data_root->n;
        temp->n+=1;
        temp->next=NULL;
        data_root->next=temp;
        return;
    }
    else
        create_database(data_root->next,name);
    
    
}

void insert_table(database *d, table *t)
{

    tables *temp=d->tList;
    tables *temp2=(tables *)malloc(sizeof(tables));
    temp2->next=NULL;
    while(temp!=NULL)
    {
        if(temp->next==NULL)
        {
            temp->t=t;    
            temp->next=temp2;
            break;
        }
        temp=temp->next;
    }
}

bool control_database1(database *d,char *name)
{
    if(d->next==NULL)
        return false;
    else if(strcmp(d->name,name)==0)
        return true;
    else
        control_database1(d->next,name);
}
bool control_database2(tables *d,int a)
{
    if(d->next==NULL&&a>0)
        return false;
    else if(d->next==NULL&&a==0)
        return true;
    else
    {
        a+=1;
        control_database2(d->next,a);
    }
}

void show_table(database *d)
{
    if(d->next==NULL)
        return;
    else
    {
        tables *temp =d->tList;
        printf("DATABASE => %s \n",d->name);
        while (temp->next!=NULL)
        {
            printf(" %s \n",temp->t->table_name);
           temp=temp->next;
        }
            //printf(" %s \n",temp->t->table_name);
        show_table(d->next);
        
    }
}

database *return_database(database *d,char *name)
{
    printf("kontrol et3\n");
    if(d->next==NULL)
        return NULL;
    else if( strcmp(d->name,name)==0)
        return d;
    else
        return return_database(d->next,name);
}

tables * remove_table(database *d, char *name)
{
    char delet[50];
    printf("write your table name\n");
    fgets(delet,50,stdin);
    edit_input(delet);
    tables *temp=d->tList;/*creating new temp*/
    tables *temp2=d->tList->next;/*creating new temp*/
    if(strcmp(temp->t->table_name,delet)==0)
        d->tList=d->tList->next;
    else
    {
        while (temp2!=NULL)
        {
            if(strcmp(temp2->t->table_name,delet)==0)
            {
                        temp->next=temp2->next;
                        break;
            }
            temp=temp2;
            temp2=temp2->next;
        }
    }
    return d->tList;
}

database *change_database(database*source,database*data_changing)
{
    database *temp=source;
    while (temp!=NULL)
    {
        if(strcmp(temp->name,data_changing->name)==0)
        {
            temp=data_changing;
            return source;
        }
        temp=temp->next;
    }
}

database * remove_database(database *d, char *name)
{
    database *temp=d;
    database *temp2=d->next;
    if (strcmp(temp->name,name)==0)
    {
        if(control_database2(temp->tList,0))
        {
            temp=temp->next;
            printf("REMOVED succesfully\n");
            return temp;
        }
        else
        {
            char *temp_array;
            while(1)
            {
                temp_array=(char *)calloc(100,sizeof(char));
                printf("Database is not EMPTY!! . If you really want to remove database press Y/y(yes) ");
                fgets(temp_array,100,stdin);
                edit_input(temp_array);
                if(strcmp(temp_array,"Y")==0||strcmp(temp_array,"y")==0||strcmp(temp_array,"yes")==0)
                {
                   temp=temp->next;
                    printf("REMOVED succesfully\n");
                    return temp;
                }
            }
        }
    }
    else
    {    
        while (temp2!=NULL)
        {
            if (strcmp(temp2->name,name)==0)
            {

                if(control_database2(temp2->tList,0))
                {
                    temp->next=temp2->next;
                    printf("REMOVED succesfully\n");
                    return temp;

                }
                else
                {
                    char *temp_array;
                    while(1)
                    {
                        temp_array=(char *)calloc(100,sizeof(char));
                        printf("Database is not EMPTY!! . If you really want to remove database press Y/y(yes) ");
                        fgets(temp_array,100,stdin);
                        edit_input(temp_array);
                        if(strcmp(temp_array,"Y")==0||strcmp(temp_array,"y")==0||strcmp(temp_array,"yes")==0)
                        {
                            temp->next=temp2->next;
                            printf("REMOVED succesfully\n");
                            return temp;
                        }
                    free(temp_array);
                    }
                }
                return d;
            }
        temp=temp2;
        temp2=temp2->next;
        }

    }
    return temp;
    
}


bool control_tables(tables *d,char *name)
{
    if(d==NULL)
        return false;
    else if(strcmp(d->t->table_name,name)==0)
        return true;
    else 
        control_tables(d->next,name);
}

tables *return_TABLE(tables *d,char *name)
{
    printf("kontrolet2\n");
    if(d==NULL)
        return NULL;
    else if(strcmp(d->t->table_name,name)==0)
        return d;
    else
        return_TABLE(d->next,name);

}

void fill_table(tables * tabble)
{
    printf("name->%s\n",tabble->t->table_name);
    char *temp;
    int value,i;
    printf("Print number of field value ");
    scanf("%d%*c",&value);
    printf("value %d \n",value);
    tabble->t->field=(char **)calloc(value+1,sizeof(char *));
    tabble->t->type=(char **)calloc(value+1,sizeof(char *));
    tabble->t->isNull=(bool **)calloc(value+1,sizeof(bool *));
    printf("kontrol5\n");
    for( i=0;i<value;i++)
    {  
        printf("Write  field name ");
        temp=(char *)calloc(100,sizeof(char));
        fgets(temp,100,stdin);
        edit_input(temp);
        tabble->t->field[i]=(char *)calloc(strlen(temp)+1,sizeof(char));
        strcpy(tabble->t->field[i],temp); 
        free(temp);
        temp=(char *)calloc(100,sizeof(char));
        printf("Write  type name ");
        fgets(temp,100,stdin);
        edit_input(temp);
        tabble->t->type[i]=(char *)calloc(strlen(temp)+1,sizeof(char));
        strcpy(tabble->t->type[i],temp); 
        free(temp);
    }
        tabble->t->field[i]=(char *)calloc(4,sizeof(char));
        tabble->t->type[i]=(char *)calloc(4,sizeof(char));
        strcpy(tabble->t->field[i],"END");
        strcpy(tabble->t->type[i],"END");
    table *new=(table *)malloc(sizeof(table));
    new->next=NULL;
    new->field=(char **)calloc(value+1,sizeof(char *));
    new->type=(char **)calloc(value+1,sizeof(char *));
    for( i=0;i<value;i++)
    {
        new->field[i]=NULL;
        new->type[i]=NULL;
        tabble->t->isNull[i]=NULL;

    }
    tabble->t->next=new;
}

void desc_table(database *d, table *t)
{
    int i=0;
    char a[]="FIELD";
    char e[]="TYPE";
    char b[]="KEY";
    char c[]="NULL";
    //char de[]="DEFAULT";
    char space[]="";
    //char a[]="FIELD";
    //char a[]="FIELD";
    printf("%-15s %-15s %-15s %-15s\n",a,e,b,c);
    while (strcmp(t->field[i],"END")!=0)
    {
        printf("+-------------------------------------------------------------------------------------+\n");
        printf("|%-13s|",t->field[i]);
        printf("|%-13s|",t->type[i]);
        if(t->next->field[i]==NULL)
            printf("|%-13s|",space);
        else
            printf("|%-13s|",t->next->field[i]);
        if(t->next->field[i]==NULL)
            printf("%-13s\n",t->next->field[i]);
        else
            printf("%-13s\n",space);
        i+=1;
    }
        
}

void fill_table_values(tables * tabble)
{
    char *temp;
    char *temp2;
    int i=0;
    while (strcmp(tabble->t->field[i],"END")!=0)
    {
        printf("Write %s value .If you dont entry press N/n(no) ",tabble->t->field[i]);
        temp=(char *)calloc(100,sizeof(char));
        temp2=(char *)calloc(100,sizeof(char));
        fgets(temp,100,stdin);
        edit_input(temp);
        printf("sring--> %s \n",temp);
        strcpy(temp2,temp);
        if(control_contunie(temp))
        {
            if(tabble->t->next->field[i]==NULL)
            {
                tabble->t->next->field[i]=(char *)calloc(strlen(temp)+1,sizeof(char));
                strcpy(tabble->t->next->field[i],temp);

            }
            else
            {
                free(temp);
                printf("Thies field is not empty: Do you want to update(Y/y(yes)) ");
                temp=(char *)calloc(100,sizeof(char));
                fgets(temp,100,stdin);
                edit_input(temp);
                if(control_contunie(temp))
                {
                    free(tabble->t->next->field[i]);
                    tabble->t->next->field[i]=(char *)calloc(strlen(temp)+1,sizeof(char));
                    strcpy(tabble->t->next->field[i],temp2);

                }
                else
                    printf("Field didn't update \n");

            }
        }
        free(temp);
        //temp=(char *)calloc(100,sizeof(char));
        //printf("Write %s value .If you dont entry press N/n(no) ");
        //fgets(temp,100,stdin);
        //edit_input(temp);
        //if(control_contunie(temp))
        //    strcpy(tabble->t->next->field[i],temp);
        i++;
    }
    
}

bool control_contunie(char *temp)
{
    if((strcmp(temp,"N")==0)||(strcmp(temp,"n")==0)||(strcmp(temp,"no")==0))
        return false;
    else
        return true;
}
bool control_contunie1(char *temp)
{
    if((strcmp(temp,"Y")==0)||(strcmp(temp,"y")==0)||(strcmp(temp,"yes")==0))
        return true;
    else
        return false;
}

// database *takingFILE(database *d)
// {
    // FILE *f=fopen(FILENAME,"rb");
    // tables *new_list=(tables*)malloc(sizeof(tables));
    // tables *new_list_temp1=new_list;
    // tables *new_list_temp2=new_list;
    // database *new=(database *)malloc(sizeof(database));
    // if(f==NULL)
        // printf("\nThere is no DATABASE now :\n");
    // else
    // {
        // printf("there are Databsae  on file : \n");
        // while (1)
        // {
            // fread(new,sizeof(database),1,f);
            // if(new->tList!=NULL)
            // {
                // new_list=new->tList;
                // while (1)
                // {
                    // fread(new_list_temp1,sizeof(tables),1,f);
                    // if(new_list_temp==NULL)
// 
                // }
                // 
            // }
        // }
        // 
    // }
// }

void write_file(database *d)
{
    database *new;
    FILE *f=fopen(FILENAME,"ab");
    while(1)
    {
        if(d!=NULL)
        {
            fwrite(d,sizeof(database),1,f);
            if(d->tList!=NULL)
            {
                printf("kontrol noktası\n\n");
                while (1)
                {
                    fwrite(d->tList,sizeof(tables),1,f);
                    d->tList=d->tList->next;
                    if(d->tList==NULL)
                    {
                        fwrite(d->tList,sizeof(tables),1,f);
                        break;
                    }
                }
                
            }
        }
        d=d->next;
        if(d==NULL)
        {
            fwrite(d,sizeof(database),1,f);
            break;
        }


    }
    fclose(f);
   // printf("\nömer\n");
   // f=fopen(FILENAME,"rb");
   // fread(new,sizeof(database),1,f);
   // printf("taking FILE\n%s \n%s \n%s \n",new->name,new->tList->t->table_name,new->tList->next->t->table_name);
   // fclose(f);
}

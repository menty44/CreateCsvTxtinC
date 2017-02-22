/*
  Copyright (c) 2009 Dave Gamble
 
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
 
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
 
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

char *jsonout;

/* Parse text to JSON, then render back to text, and print! */
void doit(char *text)
{
	char *jsonout;cJSON *json;
	
	json=cJSON_Parse(text);
	if (!json) {printf("Error before: [%s]\n",cJSON_GetErrorPtr());}
	else
	{
		jsonout=cJSON_Print(json);
		cJSON_Delete(json);
		printf("%s\n",jsonout);
		free(jsonout);
	}
}

/* Read a file, parse, render back, etc. */
void dofile(char *filename)
{
	FILE *f;long len;char *data;
	
	f=fopen(filename,"rb");fseek(f,0,SEEK_END);len=ftell(f);fseek(f,0,SEEK_SET);
	data=(char*)malloc(len+1);fread(data,1,len,f);fclose(f);
	doit(data);
	free(data);
}

/* Used by some code below as an example datatype. */
struct record {const char *precision;double lat,lon;const char *address,*city,*state,*zip,*country; };

/* Create a bunch of objects as demonstration. */
void create_objects(void)
{
	cJSON *root,*fmt,*img,*thm,*fld;int i;	/* declare a few. */
	
	
	/* Our "Video" datatype: */
	root=cJSON_CreateObject();	
	cJSON_AddItemToObject(root, "name", cJSON_CreateString("FamilyBank"));
	cJSON_AddItemToObject(root, "amount",cJSON_CreateString(""));
        cJSON_AddItemToObject(root, "pin", cJSON_CreateString(""));
	cJSON_AddItemToObject(root, "card_number",cJSON_CreateString("5666766"));
	
	
	jsonout=cJSON_Print(root);	cJSON_Delete(root);	printf("%s\n",jsonout);	free(jsonout);	/* Print to text, Delete the cJSON, print it, release the string. */

	

	



}

int main (int argc, const char * argv[]) {

	create_objects();
	printf("%s\n",jsonout);
	return 0;
}

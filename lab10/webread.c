/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2016, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
/* 
 * Simple HTTP GET that stores the web file in a local file
 
 Compile: gcc webread.c -lcurl -o mydownloader
 Execute: ./mydownloader
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <curl/curl.h>

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

int main(void)
{
  CURL *curl_handle;
  static const char *webfilename = "mylocalfile";
  FILE *webfile;

  curl_global_init(CURL_GLOBAL_ALL);

  /* init the curl session */
  curl_handle = curl_easy_init();

  /* set URL to get */
  curl_easy_setopt(curl_handle, CURLOPT_URL, "172.24.16.12/wiki/index.html");

  /* no progress meter please */
  curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);

  /* send all data to this function  */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

  /* open the web file */
  webfile = fopen(webfilename, "wb");
  if(!webfile) {
    curl_easy_cleanup(curl_handle);
    return -1;
  }

  /* we want the body be written to this file handle instead of stdout */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, webfile);

  /* get it! */
  curl_easy_perform(curl_handle);

  /* close the web file */
  fclose(webfile);

  /* cleanup curl stuff */
  curl_easy_cleanup(curl_handle);

  return 0;
}

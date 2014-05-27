#include <uuid/uuid.h>
#include "httpd.h"
#include "http_config.h"

static int generate_uuid(request_rec *r)
{
  char *uuid_str;
  uuid_t uuid;
  uuid_generate_random(uuid);

  uuid_str = (char *)apr_palloc(r->pool, sizeof(char)*37);
  uuid_unparse_lower(uuid, uuid_str);
  apr_table_setn(r->subprocess_env, "UUID", uuid_str);

  return DECLINED;
}

static void register_hooks(apr_pool_t *p)
{
    ap_hook_post_read_request(generate_uuid, NULL, NULL, APR_HOOK_MIDDLE);
}

module AP_MODULE_DECLARE_DATA uuid_module = {
    STANDARD20_MODULE_STUFF,
    NULL,                       /* dir config creater */
    NULL,                       /* dir merger --- default is to override */
    NULL,                       /* server config */
    NULL,                       /* merge server configs */
    NULL,                       /* command apr_table_t */
    register_hooks              /* register hooks */
};

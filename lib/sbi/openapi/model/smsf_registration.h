/*
 * smsf_registration.h
 *
 *
 */

#ifndef _OpenAPI_smsf_registration_H_
#define _OpenAPI_smsf_registration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "network_node_diameter_address.h"
#include "plmn_id.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_smsf_registration_s OpenAPI_smsf_registration_t;
typedef struct OpenAPI_smsf_registration_s {
    char *smsf_instance_id;
    char *smsf_set_id;
    char *supported_features;
    struct OpenAPI_plmn_id_s *plmn_id;
    char *smsf_map_address;
    struct OpenAPI_network_node_diameter_address_s *smsf_diameter_address;
    char *registration_time;
} OpenAPI_smsf_registration_t;

OpenAPI_smsf_registration_t *OpenAPI_smsf_registration_create(
    char *smsf_instance_id,
    char *smsf_set_id,
    char *supported_features,
    OpenAPI_plmn_id_t *plmn_id,
    char *smsf_map_address,
    OpenAPI_network_node_diameter_address_t *smsf_diameter_address,
    char *registration_time
    );
void OpenAPI_smsf_registration_free(OpenAPI_smsf_registration_t *smsf_registration);
OpenAPI_smsf_registration_t *OpenAPI_smsf_registration_parseFromJSON(cJSON *smsf_registrationJSON);
cJSON *OpenAPI_smsf_registration_convertToJSON(OpenAPI_smsf_registration_t *smsf_registration);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_smsf_registration_H_ */

uniform float rayDistance;
uniform float maxDistance;
uniform bool is_flashlight_on;
uniform vec2 screenSize;
uniform sampler2D texture;

void main()
{
    vec2 uv = gl_TexCoord[0].xy;
    vec4 color = texture2D(texture, uv);

    vec2 pixelPos = gl_FragCoord.xy;
    vec2 center = screenSize * 0.5;
    float distToCenter = distance(pixelPos, center);

    float flashlightRadius = min(screenSize.x, screenSize.y) * 0.3;
    float fadeZone = flashlightRadius * 1.0;

    float distanceFactor = clamp(rayDistance / maxDistance, 0.0, 1.0);
    float darkAmount = 1.0;

    if (is_flashlight_on) {
        float outerLimit = flashlightRadius + fadeZone;

        if (distToCenter <= flashlightRadius) {
            darkAmount = distanceFactor * 0.2;
        } else if (distToCenter < outerLimit) {
            float t = (distToCenter - flashlightRadius) / fadeZone;
            darkAmount = mix(distanceFactor * 0.2, 0.85, t);
        } else {
            darkAmount = 0.85;
        }
    } else {
        darkAmount = clamp(0.6 + distanceFactor * 0.4, 0.6, 1.0);
    }

    vec3 darkened = mix(color.rgb, vec3(0.0), darkAmount);
    gl_FragColor = vec4(darkened, color.a);
}

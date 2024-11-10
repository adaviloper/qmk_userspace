enum layers {
  _MAC,
  _MAC_ALT,
  _WINDOWS,
  _WINDOWS_ALT,
#ifdef GAMING_ENABLE
  _GAMING,
  _GAMING2,
#endif
#ifdef GIT_ENABLE
  _GIT,
#endif
#ifdef ART_ENABLE
  _ART,
  _ART2,
#endif
  _SYSTEM,
  _FUNC,
  _SYMBOL,
  _RAISE,
  _FUNC2,
  _ADJUST,
#ifdef RGBLIGHT_LAYERS
  _LIGHTS
#endif
};

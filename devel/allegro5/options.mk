# $NetBSD: options.mk,v 1.4 2024/08/25 06:18:31 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.allegro5
PKG_SUPPORTED_OPTIONS=		alsa openal pulseaudio x11
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS=		openal x11
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_CONFIGURE_ARGS+=	-DWANT_ALSA=ON
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_ALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Mopenal)
CMAKE_CONFIGURE_ARGS+=	-DWANT_OPENAL=ON
.  include "../../audio/openal-soft/buildlink3.mk"
.else
# OpenAL is required on Darwin and also built-in.
.  if ${OPSYS} != "Darwin"
CMAKE_CONFIGURE_ARGS+=	-DWANT_OPENAL=OFF
.  endif
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_CONFIGURE_ARGS+=	-DWANT_PULSEAUDIO=ON
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_PULSEAUDIO=OFF
.endif

.if !empty(PKG_OPTIONS:Mx11)
CMAKE_CONFIGURE_ARGS+=	-DWANT_X11=ON
.  include "../../x11/libICE/buildlink3.mk"
.  include "../../x11/libXScrnSaver/buildlink3.mk"
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXcursor/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXinerama/buildlink3.mk"
.  include "../../x11/libXpm/buildlink3.mk"
.  include "../../x11/libXrandr/buildlink3.mk"
.  include "../../x11/libXxf86vm/buildlink3.mk"
.  if ${OPSYS} != "Darwin"
.    include "../../x11/gtk3/buildlink3.mk" # native_dialog
.  endif
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_X11=OFF
.endif

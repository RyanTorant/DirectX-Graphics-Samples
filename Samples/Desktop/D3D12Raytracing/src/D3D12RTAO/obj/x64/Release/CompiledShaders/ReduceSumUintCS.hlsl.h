#if 0
;
; Note: shader requires additional functionality:
;       Wave level operations
;
;
; Input signature:
;
; Name                 Index   Mask Register SysValue  Format   Used
; -------------------- ----- ------ -------- -------- ------- ------
; no parameters
;
; Output signature:
;
; Name                 Index   Mask Register SysValue  Format   Used
; -------------------- ----- ------ -------- -------- ------- ------
; no parameters
;
; Pipeline Runtime Information: 
;
;
;
; Buffer Definitions:
;
;
; Resource Bindings:
;
; Name                                 Type  Format         Dim      ID      HLSL Bind  Count
; ------------------------------ ---------- ------- ----------- ------- -------------- ------
; g_input                           texture     u32          2d      T0             t0     1
; g_output                              UAV     u32          2d      U0             u0     1
;
target datalayout = "e-m:e-p:32:32-i1:32-i8:32-i16:32-i32:32-i64:64-f16:32-f32:32-f64:64-n8:16:32:64"
target triple = "dxil-ms-dx"

%"class.Texture2D<unsigned int>" = type { i32, %"class.Texture2D<unsigned int>::mips_type" }
%"class.Texture2D<unsigned int>::mips_type" = type { i32 }
%"class.RWTexture2D<unsigned int>" = type { i32 }
%dx.types.Handle = type { i8* }
%dx.types.ResRet.i32 = type { i32, i32, i32, i32, i32 }

@"\01?g_input@@3V?$Texture2D@I@@A" = external constant %"class.Texture2D<unsigned int>", align 4
@"\01?g_output@@3V?$RWTexture2D@I@@A" = external constant %"class.RWTexture2D<unsigned int>", align 4
@"\01?gShared@@3PAIA" = external addrspace(3) global [128 x i32], align 4

define void @main() {
  %g_output_UAV_2d = call %dx.types.Handle @dx.op.createHandle(i32 57, i8 1, i32 0, i32 0, i1 false)  ; CreateHandle(resourceClass,rangeId,index,nonUniformIndex)
  %g_input_texture_2d = call %dx.types.Handle @dx.op.createHandle(i32 57, i8 0, i32 0, i32 0, i1 false)  ; CreateHandle(resourceClass,rangeId,index,nonUniformIndex)
  %1 = call i32 @dx.op.threadId.i32(i32 93, i32 0)  ; ThreadId(component)
  %2 = call i32 @dx.op.threadId.i32(i32 93, i32 1)  ; ThreadId(component)
  %3 = call i32 @dx.op.flattenedThreadIdInGroup.i32(i32 96)  ; FlattenedThreadIdInGroup()
  %4 = call i32 @dx.op.groupId.i32(i32 94, i32 0)  ; GroupId(component)
  %5 = call i32 @dx.op.groupId.i32(i32 94, i32 1)  ; GroupId(component)
  %6 = mul i32 %4, 72
  %.i0 = add i32 %6, %1
  %TextureLoad16 = call %dx.types.ResRet.i32 @dx.op.textureLoad.i32(i32 66, %dx.types.Handle %g_input_texture_2d, i32 0, i32 %.i0, i32 %2, i32 undef, i32 undef, i32 undef, i32 undef)  ; TextureLoad(srv,mipLevelOrSampleCount,coord0,coord1,coord2,offset0,offset1,offset2)
  %7 = extractvalue %dx.types.ResRet.i32 %TextureLoad16, 0
  %.i020 = add i32 %.i0, 8
  %TextureLoad15 = call %dx.types.ResRet.i32 @dx.op.textureLoad.i32(i32 66, %dx.types.Handle %g_input_texture_2d, i32 0, i32 %.i020, i32 %2, i32 undef, i32 undef, i32 undef, i32 undef)  ; TextureLoad(srv,mipLevelOrSampleCount,coord0,coord1,coord2,offset0,offset1,offset2)
  %8 = extractvalue %dx.types.ResRet.i32 %TextureLoad15, 0
  %9 = add i32 %8, %7
  %.i022 = add i32 %.i0, 16
  %TextureLoad14 = call %dx.types.ResRet.i32 @dx.op.textureLoad.i32(i32 66, %dx.types.Handle %g_input_texture_2d, i32 0, i32 %.i022, i32 %2, i32 undef, i32 undef, i32 undef, i32 undef)  ; TextureLoad(srv,mipLevelOrSampleCount,coord0,coord1,coord2,offset0,offset1,offset2)
  %10 = extractvalue %dx.types.ResRet.i32 %TextureLoad14, 0
  %11 = add i32 %9, %10
  %.i024 = add i32 %.i0, 24
  %TextureLoad13 = call %dx.types.ResRet.i32 @dx.op.textureLoad.i32(i32 66, %dx.types.Handle %g_input_texture_2d, i32 0, i32 %.i024, i32 %2, i32 undef, i32 undef, i32 undef, i32 undef)  ; TextureLoad(srv,mipLevelOrSampleCount,coord0,coord1,coord2,offset0,offset1,offset2)
  %12 = extractvalue %dx.types.ResRet.i32 %TextureLoad13, 0
  %13 = add i32 %11, %12
  %.i026 = add i32 %.i0, 32
  %TextureLoad12 = call %dx.types.ResRet.i32 @dx.op.textureLoad.i32(i32 66, %dx.types.Handle %g_input_texture_2d, i32 0, i32 %.i026, i32 %2, i32 undef, i32 undef, i32 undef, i32 undef)  ; TextureLoad(srv,mipLevelOrSampleCount,coord0,coord1,coord2,offset0,offset1,offset2)
  %14 = extractvalue %dx.types.ResRet.i32 %TextureLoad12, 0
  %15 = add i32 %13, %14
  %.i028 = add i32 %.i0, 40
  %TextureLoad11 = call %dx.types.ResRet.i32 @dx.op.textureLoad.i32(i32 66, %dx.types.Handle %g_input_texture_2d, i32 0, i32 %.i028, i32 %2, i32 undef, i32 undef, i32 undef, i32 undef)  ; TextureLoad(srv,mipLevelOrSampleCount,coord0,coord1,coord2,offset0,offset1,offset2)
  %16 = extractvalue %dx.types.ResRet.i32 %TextureLoad11, 0
  %17 = add i32 %15, %16
  %.i030 = add i32 %.i0, 48
  %TextureLoad10 = call %dx.types.ResRet.i32 @dx.op.textureLoad.i32(i32 66, %dx.types.Handle %g_input_texture_2d, i32 0, i32 %.i030, i32 %2, i32 undef, i32 undef, i32 undef, i32 undef)  ; TextureLoad(srv,mipLevelOrSampleCount,coord0,coord1,coord2,offset0,offset1,offset2)
  %18 = extractvalue %dx.types.ResRet.i32 %TextureLoad10, 0
  %19 = add i32 %17, %18
  %.i032 = add i32 %.i0, 56
  %TextureLoad9 = call %dx.types.ResRet.i32 @dx.op.textureLoad.i32(i32 66, %dx.types.Handle %g_input_texture_2d, i32 0, i32 %.i032, i32 %2, i32 undef, i32 undef, i32 undef, i32 undef)  ; TextureLoad(srv,mipLevelOrSampleCount,coord0,coord1,coord2,offset0,offset1,offset2)
  %20 = extractvalue %dx.types.ResRet.i32 %TextureLoad9, 0
  %21 = add i32 %19, %20
  %.i034 = add i32 %.i0, 64
  %TextureLoad8 = call %dx.types.ResRet.i32 @dx.op.textureLoad.i32(i32 66, %dx.types.Handle %g_input_texture_2d, i32 0, i32 %.i034, i32 %2, i32 undef, i32 undef, i32 undef, i32 undef)  ; TextureLoad(srv,mipLevelOrSampleCount,coord0,coord1,coord2,offset0,offset1,offset2)
  %22 = extractvalue %dx.types.ResRet.i32 %TextureLoad8, 0
  %23 = add i32 %21, %22
  %.i036 = add i32 %.i0, 72
  %TextureLoad = call %dx.types.ResRet.i32 @dx.op.textureLoad.i32(i32 66, %dx.types.Handle %g_input_texture_2d, i32 0, i32 %.i036, i32 %2, i32 undef, i32 undef, i32 undef, i32 undef)  ; TextureLoad(srv,mipLevelOrSampleCount,coord0,coord1,coord2,offset0,offset1,offset2)
  %24 = extractvalue %dx.types.ResRet.i32 %TextureLoad, 0
  %25 = add i32 %23, %24
  %WaveActiveOp = call i32 @dx.op.waveActiveOp.i32(i32 119, i32 %25, i8 0, i8 1)  ; WaveActiveOp(value,op,sop)
  %WaveGetLaneCount = call i32 @dx.op.waveGetLaneCount(i32 112)  ; WaveGetLaneCount()
  %26 = getelementptr [128 x i32], [128 x i32] addrspace(3)* @"\01?gShared@@3PAIA", i32 0, i32 %3
  %27 = icmp ult i32 %WaveGetLaneCount, 128
  br i1 %27, label %.lr.ph.preheader, label %._crit_edge

.lr.ph.preheader:                                 ; preds = %0
  %28 = mul i32 %WaveGetLaneCount, %3
  %29 = getelementptr [128 x i32], [128 x i32] addrspace(3)* @"\01?gShared@@3PAIA", i32 0, i32 %28
  br label %.lr.ph

.lr.ph:                                           ; preds = %33, %.lr.ph.preheader
  %s.02 = phi i32 [ %35, %33 ], [ %WaveGetLaneCount, %.lr.ph.preheader ]
  %sum.11 = phi i32 [ %WaveActiveOp17, %33 ], [ %WaveActiveOp, %.lr.ph.preheader ]
  store i32 %sum.11, i32 addrspace(3)* %26, align 4, !tbaa !24
  call void @dx.op.barrier(i32 80, i32 9)  ; Barrier(barrierMode)
  %30 = add i32 %s.02, 127
  %31 = udiv i32 %30, %s.02
  %32 = icmp ult i32 %3, %31
  br i1 %32, label %33, label %._crit_edge.loopexit

; <label>:33                                      ; preds = %.lr.ph
  %34 = load i32, i32 addrspace(3)* %29, align 4, !tbaa !24
  %WaveActiveOp17 = call i32 @dx.op.waveActiveOp.i32(i32 119, i32 %34, i8 0, i8 1)  ; WaveActiveOp(value,op,sop)
  %35 = mul i32 %WaveGetLaneCount, %s.02
  %36 = icmp ult i32 %35, 128
  br i1 %36, label %.lr.ph, label %._crit_edge.loopexit

._crit_edge.loopexit:                             ; preds = %33, %.lr.ph
  %sum.1.lcssa.ph = phi i32 [ %WaveActiveOp17, %33 ], [ %sum.11, %.lr.ph ]
  br label %._crit_edge

._crit_edge:                                      ; preds = %._crit_edge.loopexit, %0
  %sum.1.lcssa = phi i32 [ %WaveActiveOp, %0 ], [ %sum.1.lcssa.ph, %._crit_edge.loopexit ]
  %37 = icmp eq i32 %3, 0
  br i1 %37, label %38, label %39

; <label>:38                                      ; preds = %._crit_edge
  call void @dx.op.textureStore.i32(i32 67, %dx.types.Handle %g_output_UAV_2d, i32 %4, i32 %5, i32 undef, i32 %sum.1.lcssa, i32 %sum.1.lcssa, i32 %sum.1.lcssa, i32 %sum.1.lcssa, i8 15)  ; TextureStore(srv,coord0,coord1,coord2,value0,value1,value2,value3,mask)
  br label %39

; <label>:39                                      ; preds = %38, %._crit_edge
  ret void
}

; Function Attrs: nounwind readnone
declare i32 @dx.op.threadId.i32(i32, i32) #0

; Function Attrs: nounwind readnone
declare i32 @dx.op.flattenedThreadIdInGroup.i32(i32) #0

; Function Attrs: nounwind readnone
declare i32 @dx.op.groupId.i32(i32, i32) #0

; Function Attrs: nounwind readonly
declare %dx.types.ResRet.i32 @dx.op.textureLoad.i32(i32, %dx.types.Handle, i32, i32, i32, i32, i32, i32, i32) #1

; Function Attrs: nounwind
declare void @dx.op.textureStore.i32(i32, %dx.types.Handle, i32, i32, i32, i32, i32, i32, i32, i8) #2

; Function Attrs: nounwind
declare i32 @dx.op.waveActiveOp.i32(i32, i32, i8, i8) #2

; Function Attrs: nounwind readnone
declare i32 @dx.op.waveGetLaneCount(i32) #0

; Function Attrs: noduplicate nounwind
declare void @dx.op.barrier(i32, i32) #3

; Function Attrs: nounwind readonly
declare %dx.types.Handle @dx.op.createHandle(i32, i8, i32, i32, i1) #1

attributes #0 = { nounwind readnone }
attributes #1 = { nounwind readonly }
attributes #2 = { nounwind }
attributes #3 = { noduplicate nounwind }

!llvm.ident = !{!0}
!dx.version = !{!1}
!dx.valver = !{!2}
!dx.shaderModel = !{!3}
!dx.resources = !{!4}
!dx.typeAnnotations = !{!10, !17}
!dx.entryPoints = !{!21}

!0 = !{!"dxc 1.2"}
!1 = !{i32 1, i32 3}
!2 = !{i32 1, i32 4}
!3 = !{!"cs", i32 6, i32 3}
!4 = !{!5, !8, null, null}
!5 = !{!6}
!6 = !{i32 0, %"class.Texture2D<unsigned int>"* undef, !"g_input", i32 0, i32 0, i32 1, i32 2, i32 0, !7}
!7 = !{i32 0, i32 5}
!8 = !{!9}
!9 = !{i32 0, %"class.RWTexture2D<unsigned int>"* undef, !"g_output", i32 0, i32 0, i32 1, i32 2, i1 false, i1 false, i1 false, !7}
!10 = !{i32 0, %"class.Texture2D<unsigned int>" undef, !11, %"class.Texture2D<unsigned int>::mips_type" undef, !14, %"class.RWTexture2D<unsigned int>" undef, !16}
!11 = !{i32 8, !12, !13}
!12 = !{i32 6, !"h", i32 3, i32 0, i32 7, i32 5}
!13 = !{i32 6, !"mips", i32 3, i32 4}
!14 = !{i32 4, !15}
!15 = !{i32 6, !"handle", i32 3, i32 0, i32 7, i32 5}
!16 = !{i32 4, !12}
!17 = !{i32 1, void ()* @main, !18}
!18 = !{!19}
!19 = !{i32 0, !20, !20}
!20 = !{}
!21 = !{void ()* @main, !"main", null, !4, !22}
!22 = !{i32 0, i64 524288, i32 4, !23}
!23 = !{i32 8, i32 16, i32 1}
!24 = !{!25, !25, i64 0}
!25 = !{!"int", !26, i64 0}
!26 = !{!"omnipotent char", !27, i64 0}
!27 = !{!"Simple C/C++ TBAA"}

#endif

const unsigned char g_pReduceSumUintCS[] = {
  0x44, 0x58, 0x42, 0x43, 0xbd, 0xb6, 0xdb, 0x61, 0x44, 0xc6, 0xfb, 0xd9,
  0x28, 0xfe, 0x99, 0xdd, 0xc8, 0x41, 0xf2, 0x3b, 0x01, 0x00, 0x00, 0x00,
  0xfc, 0x0b, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00,
  0x44, 0x00, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00,
  0xc8, 0x00, 0x00, 0x00, 0x53, 0x46, 0x49, 0x30, 0x08, 0x00, 0x00, 0x00,
  0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x53, 0x47, 0x31,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x4f, 0x53, 0x47, 0x31, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x50, 0x53, 0x56, 0x30, 0x5c, 0x00, 0x00, 0x00,
  0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xff, 0xff, 0xff, 0xff, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x58, 0x49, 0x4c,
  0x2c, 0x0b, 0x00, 0x00, 0x63, 0x00, 0x05, 0x00, 0xcb, 0x02, 0x00, 0x00,
  0x44, 0x58, 0x49, 0x4c, 0x03, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x14, 0x0b, 0x00, 0x00, 0x42, 0x43, 0xc0, 0xde, 0x21, 0x0c, 0x00, 0x00,
  0xc2, 0x02, 0x00, 0x00, 0x0b, 0x82, 0x20, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x13, 0x00, 0x00, 0x00, 0x07, 0x81, 0x23, 0x91, 0x41, 0xc8, 0x04, 0x49,
  0x06, 0x10, 0x32, 0x39, 0x92, 0x01, 0x84, 0x0c, 0x25, 0x05, 0x08, 0x19,
  0x1e, 0x04, 0x8b, 0x62, 0x80, 0x18, 0x45, 0x02, 0x42, 0x92, 0x0b, 0x42,
  0xc4, 0x10, 0x32, 0x14, 0x38, 0x08, 0x18, 0x4b, 0x0a, 0x32, 0x62, 0x88,
  0x48, 0x90, 0x14, 0x20, 0x43, 0x46, 0x88, 0xa5, 0x00, 0x19, 0x32, 0x42,
  0xe4, 0x48, 0x0e, 0x90, 0x11, 0x23, 0xc4, 0x50, 0x41, 0x51, 0x81, 0x8c,
  0xe1, 0x83, 0xe5, 0x8a, 0x04, 0x31, 0x46, 0x06, 0x51, 0x18, 0x00, 0x00,
  0x0b, 0x00, 0x00, 0x00, 0x1b, 0x8c, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x07,
  0x40, 0x02, 0xa8, 0x0d, 0x86, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x03, 0x20,
  0x01, 0xd5, 0x06, 0x62, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x01, 0x90, 0x36,
  0x18, 0xc4, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x03, 0x48, 0x00, 0x00,
  0x49, 0x18, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x13, 0x82, 0x60, 0x42,
  0x20, 0x4c, 0x08, 0x86, 0x09, 0x01, 0x01, 0x00, 0x89, 0x20, 0x00, 0x00,
  0x4f, 0x00, 0x00, 0x00, 0x32, 0x22, 0x88, 0x09, 0x20, 0x64, 0x85, 0x04,
  0x13, 0x23, 0xa4, 0x84, 0x04, 0x13, 0x23, 0xe3, 0x84, 0xa1, 0x90, 0x14,
  0x12, 0x4c, 0x8c, 0x8c, 0x0b, 0x84, 0xc4, 0x4c, 0x10, 0x88, 0xc1, 0x1c,
  0x01, 0x18, 0xcc, 0x84, 0x06, 0xe3, 0xc0, 0x0e, 0xe1, 0x30, 0x0f, 0xf3,
  0xe0, 0x06, 0xb4, 0x50, 0x0e, 0xf8, 0x40, 0x0f, 0xf5, 0x20, 0x0f, 0xe5,
  0x20, 0x07, 0xa4, 0xc0, 0x07, 0xf5, 0xe0, 0x0e, 0xf3, 0x90, 0x0e, 0xe7,
  0xe0, 0x0e, 0xe5, 0x40, 0x0e, 0x60, 0x90, 0x0e, 0xee, 0x40, 0x0f, 0x7e,
  0xa0, 0x07, 0x7a, 0xd0, 0x0e, 0xe9, 0x00, 0x0f, 0xf3, 0xf0, 0x0b, 0xf4,
  0x90, 0x0f, 0xf0, 0x50, 0x0e, 0x28, 0x00, 0x66, 0xea, 0xc6, 0x81, 0x1d,
  0xc2, 0x61, 0x1e, 0xe6, 0xc1, 0x0d, 0x68, 0xa1, 0x1c, 0xf0, 0x81, 0x1e,
  0xea, 0x41, 0x1e, 0xca, 0x41, 0x0e, 0x48, 0x81, 0x0f, 0xea, 0xc1, 0x1d,
  0xe6, 0x21, 0x1d, 0xce, 0xc1, 0x1d, 0xca, 0x81, 0x1c, 0xc0, 0x20, 0x1d,
  0xdc, 0x81, 0x1e, 0xfc, 0x00, 0x09, 0x40, 0x40, 0xc2, 0x4c, 0xdf, 0x38,
  0xb0, 0x43, 0x38, 0xcc, 0xc3, 0x3c, 0xb8, 0x81, 0x2c, 0xdc, 0x02, 0x2d,
  0x94, 0x03, 0x3e, 0xd0, 0x43, 0x3d, 0xc8, 0x43, 0x39, 0xc8, 0x01, 0x29,
  0xf0, 0x41, 0x3d, 0xb8, 0xc3, 0x3c, 0xa4, 0xc3, 0x39, 0xb8, 0x43, 0x39,
  0x90, 0x03, 0x18, 0xa4, 0x83, 0x3b, 0xd0, 0x83, 0x1f, 0xa0, 0x00, 0x20,
  0x22, 0x01, 0x03, 0x80, 0x41, 0x04, 0x63, 0x18, 0x01, 0x28, 0x01, 0x42,
  0x49, 0x19, 0x00, 0x00, 0xa0, 0xa5, 0x08, 0x00, 0x40, 0xcd, 0x4d, 0xc3,
  0xe5, 0x4f, 0xd8, 0x43, 0x48, 0xfe, 0x4a, 0x48, 0x2b, 0x31, 0xf9, 0xc8,
  0x6d, 0xa3, 0x02, 0x00, 0x00, 0x00, 0x98, 0x23, 0x40, 0x08, 0xba, 0x67,
  0xb8, 0xfc, 0x09, 0x7b, 0x08, 0xc9, 0x0f, 0x81, 0x66, 0x58, 0x08, 0x14,
  0x44, 0x45, 0x79, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9a, 0xca,
  0x82, 0x00, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x55, 0xa5, 0x00,
  0x00, 0x00, 0x82, 0xe8, 0x2a, 0x03, 0x02, 0x00, 0x94, 0xcd, 0x11, 0x04,
  0xc5, 0x90, 0x00, 0x08, 0x00, 0x36, 0xe2, 0x06, 0x02, 0xe6, 0x08, 0x40,
  0x61, 0x10, 0x01, 0x18, 0xa6, 0x00, 0x00, 0x00, 0x13, 0x14, 0x72, 0xc0,
  0x87, 0x74, 0x60, 0x87, 0x36, 0x68, 0x87, 0x79, 0x68, 0x03, 0x72, 0xc0,
  0x87, 0x0d, 0xaf, 0x50, 0x0e, 0x6d, 0xd0, 0x0e, 0x7a, 0x50, 0x0e, 0x6d,
  0x00, 0x0f, 0x7a, 0x30, 0x07, 0x72, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d,
  0x90, 0x0e, 0x71, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x78,
  0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x71, 0x60, 0x07, 0x7a,
  0x30, 0x07, 0x72, 0xd0, 0x06, 0xe9, 0x30, 0x07, 0x72, 0xa0, 0x07, 0x73,
  0x20, 0x07, 0x6d, 0x90, 0x0e, 0x76, 0x40, 0x07, 0x7a, 0x60, 0x07, 0x74,
  0xd0, 0x06, 0xe6, 0x10, 0x07, 0x76, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d,
  0x60, 0x0e, 0x73, 0x20, 0x07, 0x7a, 0x30, 0x07, 0x72, 0xd0, 0x06, 0xe6,
  0x60, 0x07, 0x74, 0xa0, 0x07, 0x76, 0x40, 0x07, 0x6d, 0xe0, 0x0e, 0x78,
  0xa0, 0x07, 0x71, 0x60, 0x07, 0x7a, 0x30, 0x07, 0x72, 0xa0, 0x07, 0x76,
  0x40, 0x07, 0x3a, 0x0f, 0x64, 0x90, 0x21, 0x23, 0x45, 0x44, 0x00, 0x6a,
  0x00, 0xc0, 0xe4, 0x00, 0x80, 0x69, 0x07, 0x00, 0x0f, 0x79, 0x12, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xf2, 0x2c,
  0x40, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xe4,
  0x69, 0x80, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60,
  0xc8, 0xb3, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xc0, 0x90, 0x67, 0x02, 0x02, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x80, 0x21, 0x4f, 0x05, 0x04, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x43, 0x9e, 0x0b, 0x08, 0x80, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x86, 0x3c, 0x0d, 0x10, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x79, 0x32, 0x20, 0x00, 0x08, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xf2, 0x70, 0x40, 0x00, 0x08,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x05, 0x02, 0x00, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x32, 0x1e, 0x98, 0x14, 0x19, 0x11, 0x4c, 0x90,
  0x8c, 0x09, 0x26, 0x47, 0xc6, 0x04, 0x43, 0x02, 0x4a, 0xa0, 0x0c, 0x0a,
  0xa1, 0x18, 0x46, 0x00, 0x8a, 0xa0, 0x14, 0x0a, 0xa2, 0x1c, 0x0a, 0x84,
  0xbe, 0x11, 0x80, 0x02, 0x04, 0x04, 0xa2, 0x6d, 0x04, 0x80, 0x88, 0x19,
  0x00, 0x2a, 0x66, 0x00, 0x68, 0x98, 0x01, 0x20, 0x61, 0x06, 0x80, 0x82,
  0x19, 0x00, 0x00, 0x00, 0x79, 0x18, 0x00, 0x00, 0x69, 0x00, 0x00, 0x00,
  0x1a, 0x03, 0x4c, 0x90, 0x46, 0x02, 0x13, 0xc4, 0x83, 0x0c, 0x6f, 0x0c,
  0x24, 0xc6, 0x45, 0x66, 0x43, 0x10, 0x4c, 0x10, 0x80, 0x66, 0x82, 0x00,
  0x38, 0x1b, 0x84, 0x81, 0x98, 0x20, 0x00, 0xcf, 0x06, 0x61, 0x30, 0x28,
  0x8c, 0xcd, 0x4d, 0x10, 0x00, 0x68, 0xc3, 0x80, 0x24, 0xc4, 0x04, 0x01,
  0x88, 0x26, 0x08, 0x03, 0xc7, 0xe3, 0xec, 0x2b, 0xcd, 0x0d, 0xae, 0x8e,
  0x6e, 0x82, 0x00, 0x48, 0x13, 0x04, 0x60, 0xda, 0x20, 0x2c, 0xcf, 0x86,
  0x64, 0x61, 0x9a, 0x65, 0x19, 0x9c, 0x05, 0xda, 0x10, 0x44, 0x13, 0x84,
  0x62, 0x23, 0x72, 0xf6, 0xf5, 0x56, 0x47, 0x07, 0x57, 0x47, 0x37, 0x41,
  0xd8, 0xb2, 0x0d, 0xcb, 0x32, 0x51, 0xcb, 0x32, 0x38, 0x55, 0x55, 0x41,
  0x1b, 0x02, 0x6b, 0x03, 0x21, 0x5d, 0x00, 0x30, 0x41, 0x10, 0xba, 0x09,
  0x02, 0x40, 0x31, 0x40, 0x9b, 0x20, 0x00, 0xd5, 0x06, 0x23, 0xd9, 0x88,
  0x85, 0x7b, 0x48, 0xb4, 0xa5, 0xc1, 0xcd, 0x6d, 0x20, 0x12, 0x8f, 0x30,
  0x36, 0x0c, 0x5a, 0xf7, 0x4d, 0x10, 0x02, 0x8f, 0x06, 0x5a, 0x98, 0x1b,
  0x19, 0x5b, 0xd9, 0x06, 0x23, 0x11, 0x03, 0x62, 0xe1, 0x9e, 0x0d, 0x82,
  0x31, 0x06, 0x13, 0x04, 0x42, 0xdb, 0x20, 0x18, 0xdd, 0x86, 0x63, 0xc9,
  0xc0, 0x20, 0x0c, 0xc8, 0xa0, 0x0c, 0xcc, 0x60, 0x82, 0xa0, 0x0c, 0x1b,
  0x80, 0x0d, 0xc3, 0x92, 0x06, 0x69, 0xb0, 0x21, 0x50, 0x83, 0x0d, 0xc3,
  0x80, 0x06, 0x6b, 0x40, 0xa2, 0x2d, 0x2c, 0xcd, 0x6d, 0x82, 0xf0, 0x61,
  0x13, 0x04, 0xc0, 0xda, 0x30, 0x68, 0x6f, 0x30, 0x6c, 0x20, 0x16, 0x37,
  0x30, 0xe0, 0x60, 0x43, 0x81, 0x06, 0x6d, 0x00, 0x60, 0x71, 0xc0, 0x21,
  0xcd, 0x8d, 0x8e, 0xcf, 0x5b, 0x9b, 0x5b, 0x1a, 0xdc, 0x1b, 0x5d, 0x99,
  0x1b, 0x1d, 0xc8, 0x18, 0x5a, 0x98, 0x1c, 0xa3, 0xa9, 0xb4, 0x36, 0x38,
  0xb6, 0x32, 0x90, 0xa1, 0x97, 0xa1, 0x95, 0x15, 0x10, 0x2a, 0xa1, 0xa0,
  0xa0, 0x0d, 0x41, 0x1d, 0x4c, 0x10, 0xbe, 0x6b, 0xc3, 0x40, 0x07, 0x76,
  0x70, 0x07, 0x1b, 0x86, 0x39, 0xc0, 0x83, 0x3b, 0xd8, 0x30, 0xe4, 0x41,
  0x1e, 0xdc, 0x41, 0x15, 0x36, 0x36, 0xbb, 0x36, 0x97, 0x34, 0xb2, 0x32,
  0x37, 0xba, 0x29, 0x41, 0x50, 0x85, 0x0c, 0xcf, 0xc5, 0xae, 0x4c, 0x6e,
  0x2e, 0xed, 0xcd, 0x6d, 0x4a, 0x40, 0x34, 0x21, 0xc3, 0x73, 0xb1, 0x0b,
  0x63, 0xb3, 0x2b, 0x93, 0x9b, 0x12, 0x18, 0x75, 0xc8, 0xf0, 0x5c, 0xe6,
  0xd0, 0xc2, 0xc8, 0xca, 0xe4, 0x9a, 0xde, 0xc8, 0xca, 0xd8, 0xa6, 0x04,
  0x49, 0x19, 0x32, 0x3c, 0x17, 0xb9, 0xb2, 0xb9, 0xb7, 0x3a, 0xb9, 0xb1,
  0xb2, 0xb9, 0x29, 0xc1, 0x55, 0x89, 0x0c, 0xcf, 0x85, 0x2e, 0x0f, 0xae,
  0x2c, 0xc8, 0xcd, 0xed, 0x8d, 0x2e, 0x8c, 0x2e, 0xed, 0xcd, 0x6d, 0x6e,
  0x8a, 0x60, 0x06, 0x6b, 0x50, 0x87, 0x0c, 0xcf, 0xa5, 0xcc, 0x8d, 0x4e,
  0x2e, 0x0f, 0xea, 0x2d, 0xcd, 0x8d, 0x6e, 0x6e, 0x4a, 0x10, 0x07, 0x00,
  0x79, 0x18, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x33, 0x08, 0x80, 0x1c,
  0xc4, 0xe1, 0x1c, 0x66, 0x14, 0x01, 0x3d, 0x88, 0x43, 0x38, 0x84, 0xc3,
  0x8c, 0x42, 0x80, 0x07, 0x79, 0x78, 0x07, 0x73, 0x98, 0x71, 0x0c, 0xe6,
  0x00, 0x0f, 0xed, 0x10, 0x0e, 0xf4, 0x80, 0x0e, 0x33, 0x0c, 0x42, 0x1e,
  0xc2, 0xc1, 0x1d, 0xce, 0xa1, 0x1c, 0x66, 0x30, 0x05, 0x3d, 0x88, 0x43,
  0x38, 0x84, 0x83, 0x1b, 0xcc, 0x03, 0x3d, 0xc8, 0x43, 0x3d, 0x8c, 0x03,
  0x3d, 0xcc, 0x78, 0x8c, 0x74, 0x70, 0x07, 0x7b, 0x08, 0x07, 0x79, 0x48,
  0x87, 0x70, 0x70, 0x07, 0x7a, 0x70, 0x03, 0x76, 0x78, 0x87, 0x70, 0x20,
  0x87, 0x19, 0xcc, 0x11, 0x0e, 0xec, 0x90, 0x0e, 0xe1, 0x30, 0x0f, 0x6e,
  0x30, 0x0f, 0xe3, 0xf0, 0x0e, 0xf0, 0x50, 0x0e, 0x33, 0x10, 0xc4, 0x1d,
  0xde, 0x21, 0x1c, 0xd8, 0x21, 0x1d, 0xc2, 0x61, 0x1e, 0x66, 0x30, 0x89,
  0x3b, 0xbc, 0x83, 0x3b, 0xd0, 0x43, 0x39, 0xb4, 0x03, 0x3c, 0xbc, 0x83,
  0x3c, 0x84, 0x03, 0x3b, 0xcc, 0xf0, 0x14, 0x76, 0x60, 0x07, 0x7b, 0x68,
  0x07, 0x37, 0x68, 0x87, 0x72, 0x68, 0x07, 0x37, 0x80, 0x87, 0x70, 0x90,
  0x87, 0x70, 0x60, 0x07, 0x76, 0x28, 0x07, 0x76, 0xf8, 0x05, 0x76, 0x78,
  0x87, 0x77, 0x80, 0x87, 0x5f, 0x08, 0x87, 0x71, 0x18, 0x87, 0x72, 0x98,
  0x87, 0x79, 0x98, 0x81, 0x2c, 0xee, 0xf0, 0x0e, 0xee, 0xe0, 0x0e, 0xf5,
  0xc0, 0x0e, 0xec, 0x30, 0x03, 0x62, 0xc8, 0xa1, 0x1c, 0xe4, 0xa1, 0x1c,
  0xcc, 0xa1, 0x1c, 0xe4, 0xa1, 0x1c, 0xdc, 0x61, 0x1c, 0xca, 0x21, 0x1c,
  0xc4, 0x81, 0x1d, 0xca, 0x61, 0x06, 0xd6, 0x90, 0x43, 0x39, 0xc8, 0x43,
  0x39, 0x98, 0x43, 0x39, 0xc8, 0x43, 0x39, 0xb8, 0xc3, 0x38, 0x94, 0x43,
  0x38, 0x88, 0x03, 0x3b, 0x94, 0xc3, 0x2f, 0xbc, 0x83, 0x3c, 0xfc, 0x82,
  0x3b, 0xd4, 0x03, 0x3b, 0xb0, 0xc3, 0x8c, 0xcc, 0x21, 0x07, 0x7c, 0x70,
  0x03, 0x74, 0x60, 0x07, 0x37, 0x90, 0x87, 0x72, 0x98, 0x87, 0x77, 0xa8,
  0x07, 0x79, 0x18, 0x87, 0x72, 0x70, 0x83, 0x70, 0xa0, 0x07, 0x7a, 0x90,
  0x87, 0x74, 0x10, 0x87, 0x7a, 0xa0, 0x87, 0x72, 0x00, 0x00, 0x00, 0x00,
  0x71, 0x20, 0x00, 0x00, 0x3d, 0x00, 0x00, 0x00, 0x96, 0x60, 0x0d, 0x97,
  0xef, 0x3c, 0xbe, 0x05, 0x54, 0x84, 0x26, 0x4c, 0x48, 0x45, 0xa0, 0x8f,
  0x8f, 0xdc, 0xb6, 0x29, 0x58, 0xc3, 0xe5, 0x3b, 0x8f, 0x6f, 0x01, 0x15,
  0x01, 0x12, 0x53, 0x09, 0x34, 0x04, 0xe7, 0x50, 0xcd, 0x64, 0x07, 0xd5,
  0x70, 0xf9, 0xce, 0xe3, 0x4f, 0xc4, 0x35, 0x51, 0x11, 0x51, 0x3a, 0xc0,
  0xe0, 0x23, 0xb7, 0x6d, 0x03, 0x04, 0x03, 0x20, 0x4d, 0x09, 0x40, 0x81,
  0xdf, 0x79, 0x8a, 0x0e, 0xcb, 0xcb, 0x64, 0x20, 0x70, 0x06, 0x0d, 0x26,
  0x83, 0x66, 0x10, 0x0d, 0x97, 0xef, 0x3c, 0xbe, 0x11, 0x39, 0xd4, 0x23,
  0x0e, 0x3e, 0x72, 0xdb, 0x86, 0x60, 0x0d, 0x97, 0xef, 0x3c, 0xfe, 0x44,
  0x5c, 0x13, 0x15, 0x11, 0xec, 0xe4, 0x44, 0x84, 0x8f, 0xdc, 0x76, 0x01,
  0x74, 0x81, 0xdf, 0xf9, 0x9b, 0x76, 0xc3, 0xeb, 0x74, 0x20, 0x70, 0x66,
  0xfd, 0x91, 0xa8, 0x65, 0x3c, 0xbd, 0x2e, 0x2f, 0xcb, 0x88, 0xc0, 0x24,
  0x10, 0x18, 0xb4, 0x02, 0x31, 0x18, 0x2e, 0xdf, 0x79, 0xfc, 0x62, 0x01,
  0xa6, 0x89, 0x68, 0x88, 0xa1, 0x3d, 0x22, 0x02, 0x18, 0xc4, 0x41, 0x6c,
  0xc0, 0xc8, 0xa1, 0x1e, 0x1f, 0xb9, 0x6d, 0x63, 0x90, 0x86, 0xcb, 0x77,
  0x1e, 0x5f, 0x88, 0x08, 0x60, 0x22, 0x42, 0xa0, 0x19, 0x16, 0xc2, 0x08,
  0xa4, 0xe1, 0xf2, 0x9d, 0xc7, 0x9f, 0x8e, 0x88, 0x00, 0x06, 0x71, 0xf0,
  0x91, 0xdb, 0xae, 0x00, 0x30, 0x08, 0xfc, 0xce, 0xdf, 0x77, 0x9d, 0x0e,
  0xaf, 0xd3, 0x81, 0xc0, 0x99, 0xf5, 0x47, 0x92, 0x5e, 0xa9, 0x65, 0x3c,
  0xbd, 0x2e, 0x2f, 0xcb, 0x88, 0xc0, 0x24, 0x10, 0x18, 0xb4, 0x85, 0x66,
  0xb8, 0x7c, 0xe7, 0xf1, 0x03, 0x20, 0x8a, 0x10, 0x22, 0x02, 0x00, 0x00,
  0x61, 0x20, 0x00, 0x00, 0xf5, 0x00, 0x00, 0x00, 0x13, 0x04, 0x48, 0x2c,
  0x10, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x04, 0xcc, 0x00, 0x14,
  0x61, 0x40, 0xc9, 0x95, 0x6e, 0x40, 0xf1, 0x06, 0x14, 0x64, 0x40, 0xb9,
  0x07, 0x14, 0xa0, 0x40, 0x01, 0x07, 0x14, 0x4c, 0x01, 0x15, 0x54, 0x81,
  0x15, 0x5c, 0x01, 0x06, 0x14, 0x78, 0x40, 0x81, 0x06, 0x94, 0x44, 0xf9,
  0x07, 0x94, 0x61, 0x00, 0x41, 0x25, 0x30, 0x02, 0x50, 0x1e, 0x00, 0x00,
  0x23, 0x06, 0x09, 0x00, 0x82, 0x60, 0xc0, 0xa9, 0x41, 0x35, 0x94, 0x41,
  0x19, 0x74, 0x23, 0x06, 0x09, 0x00, 0x82, 0x60, 0xc0, 0xad, 0x81, 0x35,
  0x98, 0x81, 0x19, 0x78, 0x23, 0x06, 0x06, 0x00, 0x82, 0x60, 0xb0, 0xd0,
  0x81, 0x75, 0x06, 0x23, 0x06, 0x06, 0x00, 0x82, 0x60, 0xb0, 0xd4, 0xc1,
  0xc5, 0x06, 0x23, 0x06, 0x05, 0x00, 0x82, 0x60, 0xd0, 0xd4, 0xc1, 0x34,
  0x62, 0x60, 0x00, 0x20, 0x08, 0x06, 0x4b, 0x1d, 0x60, 0x6a, 0x30, 0x62,
  0x60, 0x00, 0x20, 0x08, 0x06, 0x8b, 0x1d, 0x64, 0x6f, 0x50, 0x42, 0x26,
  0x15, 0x18, 0x30, 0x62, 0xd0, 0x00, 0x20, 0x08, 0x06, 0x13, 0x1e, 0x7c,
  0x88, 0x1b, 0x04, 0x06, 0x18, 0x80, 0x01, 0x18, 0x80, 0xc1, 0x68, 0x42,
  0x00, 0xd4, 0xd0, 0x06, 0x30, 0x62, 0xd0, 0x00, 0x20, 0x08, 0x06, 0xd3,
  0x1e, 0x88, 0xc1, 0x12, 0x07, 0x41, 0x32, 0x06, 0x63, 0x30, 0x06, 0x63,
  0x30, 0x9a, 0x10, 0x00, 0x15, 0x10, 0x50, 0xc7, 0x1b, 0xc0, 0x88, 0x41,
  0x03, 0x80, 0x20, 0x18, 0x4c, 0x7f, 0x60, 0x06, 0x4f, 0x1d, 0x04, 0xcd,
  0x19, 0x9c, 0xc1, 0x19, 0x9c, 0xc1, 0x68, 0x42, 0x00, 0x14, 0x11, 0x40,
  0x2d, 0x61, 0x00, 0x23, 0x06, 0x0d, 0x00, 0x82, 0x60, 0x30, 0x8d, 0x82,
  0x1a, 0x4c, 0x79, 0x10, 0x44, 0x6b, 0xb0, 0x06, 0x6b, 0xb0, 0x06, 0xa3,
  0x09, 0x01, 0x50, 0x44, 0x00, 0xf5, 0x90, 0x01, 0x8c, 0x18, 0x34, 0x00,
  0x08, 0x82, 0xc1, 0x74, 0x0a, 0x6e, 0x70, 0xf5, 0x41, 0x50, 0xbd, 0xc1,
  0x1b, 0xbc, 0xc1, 0x1b, 0x8c, 0x26, 0x04, 0x40, 0x11, 0x01, 0xd4, 0x74,
  0x06, 0x30, 0x62, 0xd0, 0x00, 0x20, 0x08, 0x06, 0xd3, 0x2a, 0xc8, 0xc1,
  0x16, 0x0a, 0x41, 0x36, 0x07, 0x73, 0x30, 0x07, 0x73, 0x30, 0x9a, 0x10,
  0x00, 0x45, 0x04, 0x50, 0x97, 0x1a, 0xc0, 0x88, 0x41, 0x03, 0x80, 0x20,
  0x18, 0x4c, 0xaf, 0x60, 0x07, 0x5f, 0x29, 0x04, 0xdd, 0x1d, 0xdc, 0xc1,
  0x1d, 0xdc, 0xc1, 0x68, 0x42, 0x00, 0x14, 0x11, 0x40, 0x6d, 0x6d, 0x00,
  0x23, 0x06, 0x0d, 0x00, 0x82, 0x60, 0x30, 0xcd, 0x82, 0x1e, 0x8c, 0x41,
  0x2a, 0x04, 0x61, 0xb0, 0x07, 0x7b, 0xb0, 0x07, 0x7b, 0x30, 0x9a, 0x10,
  0x00, 0x45, 0x04, 0x50, 0x1f, 0x1c, 0xc0, 0x88, 0x41, 0x03, 0x80, 0x20,
  0x18, 0x4c, 0xb7, 0xe0, 0x07, 0x67, 0xd0, 0x0a, 0x41, 0x19, 0xfc, 0xc1,
  0x1f, 0xfc, 0xc1, 0x1f, 0x8c, 0x26, 0x04, 0x40, 0x11, 0x01, 0xd4, 0x18,
  0xf4, 0x01, 0x8c, 0x18, 0x34, 0x00, 0x08, 0x82, 0xc1, 0xb4, 0x0b, 0xa2,
  0xb0, 0x06, 0xb1, 0x10, 0xa4, 0xc1, 0x28, 0x8c, 0xc2, 0x28, 0x8c, 0xc2,
  0x68, 0x42, 0x00, 0x14, 0x11, 0xc0, 0x88, 0x01, 0x02, 0x80, 0x20, 0x18,
  0x5c, 0xbc, 0x00, 0x0a, 0x41, 0x1c, 0xc8, 0xc1, 0x88, 0x41, 0x01, 0x80,
  0x20, 0x18, 0x34, 0xbc, 0x80, 0x07, 0xcb, 0x18, 0xca, 0xc1, 0x16, 0xda,
  0x60, 0xb8, 0x41, 0x10, 0x05, 0x32, 0x98, 0x65, 0x08, 0x8a, 0xa0, 0x86,
  0x37, 0x90, 0x65, 0x0c, 0xe8, 0x90, 0x0b, 0xc1, 0x2c, 0x81, 0x30, 0x50,
  0x01, 0x3c, 0x83, 0x12, 0x0c, 0x54, 0x00, 0xcb, 0xe0, 0x04, 0xc3, 0x06,
  0x84, 0x11, 0x0c, 0xc0, 0x88, 0x81, 0x01, 0x80, 0x20, 0x18, 0x64, 0xe2,
  0xe0, 0x07, 0x7d, 0x50, 0x02, 0x1f, 0x40, 0x05, 0xc3, 0x0c, 0x37, 0xd4,
  0x41, 0x40, 0x06, 0xb3, 0x0c, 0x03, 0x11, 0x90, 0x01, 0x8c, 0x11, 0x03,
  0x04, 0x00, 0x41, 0x30, 0xb8, 0xd0, 0x81, 0x15, 0x82, 0x3e, 0xf0, 0x83,
  0x62, 0x0e, 0x19, 0x6e, 0x08, 0x5a, 0x81, 0x0c, 0x66, 0x19, 0x04, 0x22,
  0x18, 0xa8, 0x00, 0x8c, 0x01, 0x12, 0x66, 0x09, 0x8a, 0x81, 0x0a, 0x00,
  0x0c, 0x00, 0x81, 0x18, 0x6e, 0xe0, 0x83, 0x72, 0x00, 0x83, 0x59, 0x06,
  0xe3, 0x08, 0x46, 0x0c, 0x1c, 0x00, 0x04, 0xc1, 0xa0, 0x7a, 0x87, 0x52,
  0x08, 0x05, 0x3e, 0xd8, 0x03, 0x5c, 0x10, 0x04, 0x41, 0x10, 0x85, 0x59,
  0x82, 0x03, 0xc3, 0x81, 0x00, 0x00, 0x00, 0x00, 0x52, 0x00, 0x00, 0x00,
  0xc6, 0x66, 0x48, 0x14, 0xe3, 0xd7, 0xb5, 0x05, 0x15, 0x3e, 0x42, 0xdb,
  0xb4, 0x69, 0x31, 0x2d, 0x71, 0x4d, 0x54, 0x44, 0x94, 0x0e, 0x30, 0xf4,
  0x56, 0x54, 0xf8, 0x08, 0x6d, 0xdb, 0xe6, 0xc5, 0xb4, 0xc4, 0x35, 0x51,
  0x11, 0x51, 0x3a, 0xc0, 0xc0, 0x5b, 0x52, 0xe1, 0x23, 0xb4, 0x8d, 0x5b,
  0x19, 0x03, 0x03, 0x15, 0xa1, 0x09, 0x13, 0x52, 0x11, 0xe8, 0x63, 0x4d,
  0x85, 0x8f, 0xd0, 0xb6, 0x6e, 0x51, 0x85, 0x8f, 0xd0, 0x36, 0x7f, 0x02,
  0x86, 0xbf, 0x44, 0xfe, 0x73, 0x5c, 0xc1, 0xe2, 0xff, 0x42, 0x84, 0x4c,
  0x3f, 0x31, 0x18, 0x84, 0xc5, 0x39, 0x30, 0x50, 0x11, 0x9a, 0x30, 0x21,
  0x15, 0x81, 0x3e, 0xf5, 0x6e, 0x36, 0x8f, 0xf1, 0x3b, 0xd4, 0xf4, 0x50,
  0xd3, 0xef, 0x6a, 0xef, 0x6f, 0x0f, 0x56, 0xb7, 0x48, 0x14, 0xe3, 0xd7,
  0xfe, 0x22, 0x48, 0x12, 0x60, 0x37, 0x92, 0xf1, 0x23, 0xcd, 0x43, 0x4d,
  0xff, 0x44, 0x5c, 0x13, 0x15, 0x11, 0xbf, 0x3d, 0x98, 0x19, 0x04, 0x03,
  0x15, 0x01, 0x12, 0x53, 0x09, 0x34, 0x04, 0xe7, 0x50, 0xcd, 0x64, 0x74,
  0x8e, 0x44, 0x31, 0x7e, 0xed, 0x2f, 0x82, 0x24, 0x01, 0xfe, 0x73, 0xd8,
  0x1a, 0x21, 0xf9, 0xb4, 0x6d, 0x3e, 0x83, 0x8f, 0xd0, 0x56, 0x55, 0xf8,
  0x08, 0x7d, 0xd3, 0x96, 0x55, 0xf8, 0x08, 0x7d, 0xdb, 0xd6, 0x55, 0xf8,
  0x08, 0x7d, 0xe3, 0x17, 0x00, 0xf9, 0x4b, 0xe4, 0x3f, 0x87, 0xff, 0x44,
  0xc4, 0x41, 0x00, 0x03, 0x11, 0x99, 0xd8, 0xd2, 0x12, 0xd7, 0x44, 0x45,
  0x44, 0xe9, 0x00, 0x83, 0x59, 0x35, 0x2d, 0x71, 0x4d, 0x54, 0x44, 0x94,
  0x0e, 0x30, 0xd4, 0xb4, 0x49, 0x35, 0x2d, 0x71, 0x4d, 0x54, 0x44, 0x94,
  0x0e, 0x30, 0xd4, 0xb5, 0x39, 0x35, 0x2d, 0x71, 0x4d, 0x54, 0x44, 0x94,
  0x0e, 0x30, 0xd4, 0xb6, 0x29, 0x35, 0x2d, 0x71, 0x4d, 0x54, 0x44, 0x94,
  0x0e, 0x30, 0xd4, 0xb7, 0x19, 0x35, 0x2d, 0x71, 0x4d, 0x54, 0x44, 0x94,
  0x0e, 0x30, 0xd4, 0xb8, 0x09, 0x35, 0x2d, 0x71, 0x4d, 0x54, 0x44, 0x94,
  0x0e, 0x30, 0xd4, 0xb9, 0xfd, 0x34, 0x2d, 0x71, 0x4d, 0x54, 0x44, 0x94,
  0x0e, 0x30, 0xd4, 0xba, 0x85, 0x15, 0x3e, 0x42, 0xdf, 0xfa, 0x11, 0x50,
  0xfe, 0x2f, 0x44, 0xc8, 0xf4, 0x13, 0x83, 0x41, 0xf8, 0x8b, 0xe3, 0x3c,
  0xc4, 0x85, 0x4c, 0x00, 0x01, 0x31, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x5b, 0x86, 0x3c, 0x08, 0xf2, 0x60, 0xcb, 0xf0, 0x07, 0x41, 0x1e, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

xof 0303txt 0032
template AnimTicksPerSecond {
 <9e415a43-7ba6-4a73-8743-b73d47e88476>
 DWORD AnimTicksPerSecond;
}

template Frame {
 <3d82ab46-62da-11cf-ab39-0020af71e433>
 [...]
}

template Matrix4x4 {
 <f6f23f45-7686-11cf-8f52-0040333594a3>
 array FLOAT matrix[16];
}

template FrameTransformMatrix {
 <f6f23f41-7686-11cf-8f52-0040333594a3>
 Matrix4x4 frameMatrix;
}

template Vector {
 <3d82ab5e-62da-11cf-ab39-0020af71e433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template MeshFace {
 <3d82ab5f-62da-11cf-ab39-0020af71e433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template Mesh {
 <3d82ab44-62da-11cf-ab39-0020af71e433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template MeshNormals {
 <f6f23f43-7686-11cf-8f52-0040333594a3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template Coords2d {
 <f6f23f44-7686-11cf-8f52-0040333594a3>
 FLOAT u;
 FLOAT v;
}

template MeshTextureCoords {
 <f6f23f40-7686-11cf-8f52-0040333594a3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template ColorRGBA {
 <35ff44e0-6c7c-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <d3e16e81-7835-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template Material {
 <3d82ab4d-62da-11cf-ab39-0020af71e433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshMaterialList {
 <f6f23f42-7686-11cf-8f52-0040333594a3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material <3d82ab4d-62da-11cf-ab39-0020af71e433>]
}

template TextureFilename {
 <a42790e1-7810-11cf-8f52-0040333594a3>
 STRING filename;
}

template VertexDuplicationIndices {
 <b8d65549-d7c9-4995-89cf-53a9a8b031e3>
 DWORD nIndices;
 DWORD nOriginalVertices;
 array DWORD indices[nIndices];
}

template Animation {
 <3d82ab4f-62da-11cf-ab39-0020af71e433>
 [...]
}

template AnimationSet {
 <3d82ab50-62da-11cf-ab39-0020af71e433>
 [Animation <3d82ab4f-62da-11cf-ab39-0020af71e433>]
}

template FloatKeys {
 <10dd46a9-775b-11cf-8f52-0040333594a3>
 DWORD nValues;
 array FLOAT values[nValues];
}

template TimedFloatKeys {
 <f406b180-7b3b-11cf-8f52-0040333594a3>
 DWORD time;
 FloatKeys tfkeys;
}

template AnimationKey {
 <10dd46a8-775b-11cf-8f52-0040333594a3>
 DWORD keyType;
 DWORD nKeys;
 array TimedFloatKeys keys[nKeys];
}


AnimTicksPerSecond {
 4800;
}

Frame Plane001 {
 

 FrameTransformMatrix {
  1.015926,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.015926,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 Mesh mesh_P {
  13;
  -0.246081;0.108458;-0.246081;,
  -0.082027;0.042467;-0.246081;,
  0.000000;-0.002292;0.000000;,
  -0.246081;0.042467;-0.082027;,
  0.082027;0.108458;-0.246081;,
  0.246081;0.042467;-0.246081;,
  0.246081;0.108458;-0.082027;,
  -0.246081;0.108458;0.082027;,
  0.246081;0.042467;0.082027;,
  -0.082027;0.108458;0.246081;,
  -0.246081;0.042467;0.246081;,
  0.082027;0.042467;0.246081;,
  0.246081;0.108458;0.246081;;
  12;
  3;0,2,1;,
  3;2,0,3;,
  3;1,2,4;,
  3;4,6,5;,
  3;6,4,2;,
  3;7,2,3;,
  3;2,8,6;,
  3;7,9,2;,
  3;9,7,10;,
  3;9,11,2;,
  3;2,12,8;,
  3;12,2,11;;

  MeshNormals {
   13;
   0.229255;0.944198;0.229255;,
   0.084365;0.982181;0.164636;,
   0.000000;1.000000;0.000000;,
   0.164636;0.982181;0.084365;,
   -0.170252;0.974931;0.137779;,
   0.368290;0.848537;-0.368290;,
   -0.137779;0.974931;0.170252;,
   0.137779;0.974931;-0.170252;,
   -0.164636;0.982181;-0.084365;,
   0.170252;0.974931;-0.137779;,
   -0.368290;0.848538;0.368290;,
   -0.084365;0.982181;-0.164636;,
   -0.229255;0.944198;-0.229255;;
   12;
   3;0,2,1;,
   3;2,0,3;,
   3;1,2,4;,
   3;4,6,5;,
   3;6,4,2;,
   3;7,2,3;,
   3;2,8,6;,
   3;7,9,2;,
   3;9,7,10;,
   3;9,11,2;,
   3;2,12,8;,
   3;12,2,11;;
  }

  MeshTextureCoords {
   13;
   0.000000;1.000000;,
   0.333333;1.000000;,
   0.500000;0.500000;,
   0.000000;0.666667;,
   0.666667;1.000000;,
   1.000000;1.000000;,
   1.000000;0.666667;,
   0.000000;0.333333;,
   1.000000;0.333333;,
   0.333333;0.000000;,
   0.000000;0.000000;,
   0.666667;0.000000;,
   1.000000;0.000000;;
  }

  MeshMaterialList {
   1;
   12;
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0;

   Material {
    0.588235;0.588235;0.588235;1.000000;;
    9.999999;
    0.900000;0.900000;0.900000;;
    1.000000;1.000000;1.000000;;

    TextureFilename {
     "D:\\\\_00\\\\atack_fx\\\\maps\\\\atack_fx.png";
    }
   }
  }

  VertexDuplicationIndices {
   13;
   13;
   0,
   1,
   2,
   3,
   4,
   5,
   6,
   7,
   8,
   9,
   10,
   11,
   12;
  }
 }
}

AnimationSet  {
 

 Animation {
  

  AnimationKey {
   0;
   1;
   0;4;1.000000,0.000000,0.000000,0.000000;;;
  }

  AnimationKey {
   1;
   20;
   0;3;0.011136,0.010000,0.011136;;,
   1;3;0.011136,0.010000,0.011136;;,
   2;3;0.562387,0.505000,0.562387;;,
   3;3;1.113638,1.000000,1.113638;;,
   4;3;1.056819,1.000000,1.056819;;,
   5;3;1.000000,1.000000,1.000000;;,
   6;3;1.056819,1.000000,1.056819;;,
   7;3;1.113638,1.000000,1.113638;;,
   8;3;1.056819,1.000000,1.056819;;,
   9;3;1.000000,1.000000,1.000000;;,
   10;3;1.004550,1.000000,1.004550;;,
   11;3;1.015926,1.000000,1.015926;;,
   12;3;1.030714,1.000000,1.030714;;,
   13;3;1.045503,1.000000,1.045503;;,
   14;3;1.056878,1.000000,1.056878;;,
   15;3;1.061429,1.000000,1.061429;;,
   16;3;0.952198,0.897040,0.952198;;,
   17;3;0.691726,0.651520,0.691726;;,
   18;3;0.380839,0.358480,0.380839;;,
   19;3;0.120367,0.112960,0.120367;;;
  }

  AnimationKey {
   2;
   1;
   0;3;0.000000,0.000000,0.000000;;;
  }
  { Plane001 }
 }
}
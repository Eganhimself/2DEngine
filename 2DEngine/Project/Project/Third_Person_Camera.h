#if !defined(THIRD_PERSON_CAMERA_H)
#define THIRD_PERSON_CAMERA_H


#include <d3d11.h>
#include <D3DX10math.h>

//-----------------------------------------------------------------------------
// A quaternion based third person camera class.
//
// Call the lookAt() method to establish the distance and position of the
// camera relative to the target look at position. The lookAt() method stores
// this relationship to the target look at position in the offset vector. The
// look at position can be changed using the overloaded lookAt(target) method.
//
// Aside from the lookAt() method there is no way to move the camera's eye
// position. The camera's eye position is automatically calculated and updated
// in the update() method using the offset vector.
//
// Rotating the camera using the rotate() method allows the camera to be
// orbited around the the look at position. 
//-----------------------------------------------------------------------------

class ThirdPersonCamera
{
public:
    ThirdPersonCamera();
    ~ThirdPersonCamera();

    void lookAt(const D3DXVECTOR3 &target);
    void lookAt(const D3DXVECTOR3 &eye, const D3DXVECTOR3 &target, const D3DXVECTOR3 &up);
    void perspective(float fovx, float aspect, float znear, float zfar);
    void rotate(float longitudeDegrees, float latitudeDegrees);
    void update(float elapsedTimeSec);

    // Getter methods.

    const D3DXVECTOR3 &getPosition() const;
    const D3DXQUATERNION &getOrientation() const;
    const D3DXMATRIX &getViewMatrix() const;
    const D3DXVECTOR3 &getViewDirection() const;
    const D3DXMATRIX &getProjectionMatrix() const;
    const D3DXVECTOR3 &getXAxis() const;
    const D3DXVECTOR3 &getYAxis() const;
    const D3DXVECTOR3 &getZAxis() const;

private:
    static const float DEFAULT_FOVX;
    static const float DEFAULT_ZFAR;
    static const float DEFAULT_ZNEAR;
    static const D3DXVECTOR3 WORLD_XAXIS;
    static const D3DXVECTOR3 WORLD_YAXIS;
    static const D3DXVECTOR3 WORLD_ZAXIS;

    float m_longitudeDegrees;
    float m_latitudeDegrees;
    float m_fovx;
    float m_znear;
    float m_zfar;
    D3DXVECTOR3 m_eye;
    D3DXVECTOR3 m_target;
    D3DXVECTOR3 m_offset;
    D3DXVECTOR3 m_xAxis;
    D3DXVECTOR3 m_yAxis;
    D3DXVECTOR3 m_zAxis;
    D3DXMATRIX m_viewMatrix;
    D3DXMATRIX m_projMatrix;
    D3DXQUATERNION m_orientation;
};

//-----------------------------------------------------------------------------

inline const D3DXVECTOR3 &ThirdPersonCamera::getPosition() const
{ return m_eye; }

inline const D3DXQUATERNION &ThirdPersonCamera::getOrientation() const
{ return m_orientation; }

inline const D3DXMATRIX &ThirdPersonCamera::getViewMatrix() const
{ return m_viewMatrix; }

inline const D3DXVECTOR3 &ThirdPersonCamera::getViewDirection() const
{ return m_zAxis; }

inline const D3DXMATRIX &ThirdPersonCamera::getProjectionMatrix() const
{ return m_projMatrix; }

inline const D3DXVECTOR3 &ThirdPersonCamera::getXAxis() const
{ return m_xAxis; }

inline const D3DXVECTOR3 &ThirdPersonCamera::getYAxis() const
{ return m_yAxis; }

inline const D3DXVECTOR3 &ThirdPersonCamera::getZAxis() const
{ return m_zAxis; }

#endif